// UVa11270 Tiling Dominoes
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m, cur;

const int maxn = 15;
long long d[2][1<<maxn];

void up(int a, int b) {
  if(b&(1<<m)) d[cur][b^(1<<m)] += d[1-cur][a];
}

int main() {
  while(scanf("%d%d", &n, &m) == 2) {
    if(n < m) swap(n, m);
    memset(d, 0, sizeof(d));
    cur = 0;
    d[0][(1<<m)-1] = 1;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) { // ö�ٵ�ǰҪ��Ľ׶�
        cur ^= 1;
        memset(d[cur], 0, sizeof(d[cur]));
        for(int k = 0; k < (1<<m); k++) { // ö���ϸ��׶ε�״̬
          up(k, k<<1);
          if(i && !(k&(1<<m-1))) up(k, (k<<1)^(1<<m)^1);
          if(j && !(k&1)) up(k, (k<<1)^3);
        }
      }
    printf("%lld\n", d[cur][(1<<m)-1]);
  }
  return 0;
}