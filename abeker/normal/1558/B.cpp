#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  auto add = [&](int x, int y) {
    x += y;
    if (x >= M)
      return x - M;
    if (x < 0)
      return x + M;
    return x;
  };
  vector <int> dp(N + 1);
  for (int i = 1; i <= N; i++) {
    dp[i] = i > 2 ? add(dp[i], add(dp[i - 1], dp[i - 1])) : i;
    int diff = add(dp[i], -dp[i - 1]);
    for (int j = 2 * i; j <= N; j += i) 
      dp[j] = add(dp[j], diff);
  }
  printf("%d\n", dp[N]);
  return 0;
}