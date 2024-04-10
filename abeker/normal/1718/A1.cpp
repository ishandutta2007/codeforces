#include <bits/stdc++.h>
using namespace std;

int solve() {
  int N;
  scanf("%d", &N);
  vector <int> a(N + 1);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &a[i]);
    a[i] ^= a[i - 1];
  }
  vector <int> dp(N + 1);
  unordered_map <int, int> last;
  last[0] = 0;
  for (int i = 1; i <= N; i++) {
    dp[i] = dp[i - 1];
    if (last.find(a[i]) != last.end())
      dp[i] = max(dp[i], dp[last[a[i]]] + 1);
    last[a[i]] = i;
  }
  return N - dp[N];
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    printf("%d\n", solve());
  return 0;
}