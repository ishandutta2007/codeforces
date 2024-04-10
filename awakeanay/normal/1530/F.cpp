#include <iostream>

const int INV = 3973;
const int MOD = 31607;
const int MAXN = 21;
const int MAXM = (1 << 21);

int pcol[MAXN][MAXM];
int prow[MAXN][MAXM];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int p[n][n];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      std::cin >> p[i][j];
      p[i][j] *= INV;
      p[i][j] %= MOD;
    }
  }
  
  int m = (1 << n);

  int last[m];
  last[0] = -1;
  for(int i = 1; i < m; i++) {
    for(int j = 0; j < n; j++) {
      if((i >> j)&1) {
        last[i] = j;
        break;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    pcol[i][0] = 1;
    prow[i][0] = 1;
    for(int j = 1; j < m; j++) {
      int cur = p[last[j]][i];
      cur *= pcol[i][j^(1 << last[j])];
      cur %= MOD;
      pcol[i][j] = cur;

      cur = p[i][last[j]];
      cur *= prow[i][j^(1 << last[j])];
      cur %= MOD;
      prow[i][j] = cur;
    }
  }

  int k = (1 << (n + 2));
  int ans = 0;

  for(int i = 0; i < k; i++) {
    int a = (i >> n)&1;
    int b = (i >> (n+1))&1;
    int bitc = __builtin_popcount(i);

    int cur = 1;
    for(int j = 0; j < n; j++) {
      int bit = 0;
      if((i >> j)&1)
        bit = m-1;
      else {
        if(a && (!((bit >> j)&1)))
          bit ^= (1 << j);
        if(b && (!((bit >> (n-1-j))&1)))
          bit ^= (1 << (n-1-j));
      }

      cur *= prow[j][bit];
      cur %= MOD;
    }

    int add = 1;
    int def;
    for(int j = 0; j < n; j++) {
      def = i%m;
      def = m-1-def;
      if(a && ((def >> j)&1)) {
        def ^= (1 << j);
      }
      if(b && ((def >> (n-1-j))&1)) {
        def ^= (1 << (n-1-j));
      }
      add *= MOD+1-pcol[j][def];
      add %= MOD;
    }

    add = add*cur;
    add %= MOD;
    if(bitc%2 == 0)
      ans += add;
    else
      ans = (ans+MOD-add);
    ans %= MOD;
  }
  ans = (MOD+1-ans)%MOD;

  std::cout << ans << std::endl;

  return 0;
}