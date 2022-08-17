#include <iostream>
#include <vector>

#define int long long

const int MOD = 1000000007;
const int MAXM = 200005;

int push[MAXM][10];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  for(int i = 0; i < 10; i++)
    push[0][i] = 1;

  for(int j = 1; j < MAXM; j++) {
    for(int i = 0; i < 10; i++)
      push[j][i] = push[j-1][(i+1)%10];
    push[j][9] = (push[j][9] + push[j-1][1])%MOD;
  }

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    int ans = 0;
    while(n > 0) {
      ans += push[m][n%10];
      ans %= MOD;
      n /= 10;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}