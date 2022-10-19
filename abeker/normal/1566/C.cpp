#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
char s[2][MAXN];
int dp[MAXN];

int get_mex(int l, int r) {
  vector <bool> has(3);
  for (int i = 0; i < 2; i++)
    for (int j = l; j <= r; j++)
      has[s[i][j] - '0'] = true;
  for (int i = 0; i < 3; i++)
    if (!has[i])
      return i;
  assert(false);
}

int solve() {
  scanf("%d", &N);
  for (int i = 0; i < 2; i++)
    scanf("%s", s[i] + 1);
  for (int i = 1; i <= N; i++) {
    dp[i] = 0;
    for (int j = 1; j <= 2; j++)
      if (i >= j)
        dp[i] = max(dp[i], dp[i - j] + get_mex(i - j + 1, i));
  }
  return dp[N];
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    printf("%d\n", solve());
  return 0;
}