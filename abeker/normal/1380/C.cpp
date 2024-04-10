#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int N, X;
    scanf("%d%d", &N, &X);
    vector <int> skill(N);
    for (auto &it : skill)
      scanf("%d", &it);
    sort(skill.begin(), skill.end());
    vector <int> dp(N + 1);
    for (int i = N - 1; i >= 0; i--) {
      dp[i] = dp[i + 1];
      int pos = i + (X - 1) / skill[i] + 1;
      if (pos <= N)
        dp[i] = max(dp[i], dp[pos] + 1);
    }
    printf("%d\n", dp[0]);
  }
  return 0;
}