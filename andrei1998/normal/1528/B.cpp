#include <bits/stdc++.h>
#include <ios>

using namespace std;

using lint = long long int;
const int MOD = 998244353;

const int NMAX = 1000000 + 5;

int dp[NMAX], divs[NMAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    for (int j = i; j <= N; j += i) {
      ++divs[j];
    }
  }

  dp[0] = 1;
  dp[1] = 1;
  int sum = 1;
  for (int i = 2; i <= N; ++i) {
    dp[i] = sum + divs[i];
    if (dp[i] >= MOD) {
      dp[i] -= MOD;
    }
    sum += dp[i];
    if (sum >= MOD) {
      sum -= MOD;
    }
    // cout << i << ' ' << dp[i] << endl;
  }
  cout << dp[N] << endl;
  return 0;
}