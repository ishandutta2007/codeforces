#include <iostream>

#define int long long

const int MAXN = 20'000'007;

int dp[MAXN];
int divi[MAXN];
int pr[MAXN];

int pi = 0;
int prl[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  pr[1] = -1;
  for(int i = 2; i < MAXN; i++) {
    if(!pr[i]) {
      pr[i] = i;
      prl[pi++] = i;

      for(int j = i*i; j < MAXN; j+=i)
        pr[j] = i;
    }
  }

  int n;
  std::cin >> n;

  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    divi[x]++;
  }

  for(int j = 0; j < pi; j++) {
    for(int i = (MAXN-1)/prl[j]; i >= 1; i--) {
      divi[i] += divi[i*prl[j]];
    }
  }

  int ans = n;
  dp[1] = 0;
  for(int i = 1; i < MAXN; i++) {
    dp[i] += ((int)divi[i])*i;
    ans = std::max(ans, (int)dp[i]);

    for(int j = 0; j < pi; j++) {
      int next = ((int)prl[j])*i;
      if(next >= MAXN)
        break;
      dp[next] = std::max((int)dp[next], dp[i] - ((int)divi[next])*i);
    }
  }

  std::cout << ans << std::endl;

  return 0;
}