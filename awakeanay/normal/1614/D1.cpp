#include <iostream>

#define int long long

const int MAXN = 5000006;

int freq[MAXN];
int dp[MAXN];
int divi[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    freq[x]++;
  }

  for(int i = 1; i < MAXN; i++) {
    for(int j = i; j < MAXN; j+=i)
      divi[i] += freq[j];
  }

  int ans = n;
  for(int i = 1; i < MAXN; i++) {
    dp[i] += divi[i]*i;
    ans = std::max(ans, dp[i]);

    for(int j = 2*i; j < MAXN; j+=i) {
      dp[j] = std::max(dp[j], dp[i]-divi[j]*i);
    }
  }

  std::cout << ans << std::endl;

  return 0;
}