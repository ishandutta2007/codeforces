#include <iostream>
#include <vector>

#define int long long

const int MOD = 998244353;
const int MAXN = 300005;

int p2[MAXN];
int p2s[MAXN];

signed main() {
  p2[0] = 1;
  p2s[0] = 1;
  for(int i = 1; i < MAXN; i++) {
    p2[i] = (p2[i-1]*2)%MOD;
    p2s[i] = p2[i];
    if(i >= 2)
      p2s[i] = (p2s[i] + p2s[i-2])%MOD;
  }

  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int> > mat[2];
  mat[0] = std::vector<std::vector<int> >(n, std::vector<int>(m, 0));
  mat[1] = std::vector<std::vector<int> >(m, std::vector<int>(n, 0));

  int w = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      char x;
      std::cin >> x;
      if(x == 'o') {
        mat[0][i][j] = 1;
        w++;
        mat[1][j][i] = 1;
      }
    }

  int ans = 0;
  for(int k = 0; k < 2; k++) {
    for(int i = 0; i < n; i++) {
      int cur = 0;
      for(int j = 0; j < m; j++) {
        if(!mat[k][i][j])
          cur = 0;
        else
          cur++;

        if(cur >= 2)
          ans = (ans + (cur == 2 ? 1 : p2s[cur-3] + (cur%2==0))*p2[w-cur])%MOD;
      }
    }

    n ^= m ^= n ^= m;
  }

  std::cout << ans << std::endl;

  return 0;
}