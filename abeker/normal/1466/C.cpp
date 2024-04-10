#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int N;
char s[MAXN];
int dp[MAXN][8];

bool check(int pos, int mask) {
  vector <int> unused;
  for (int i = 0; i < 3; i++) {
    int curr = pos - i;
    int bit = mask >> i & 1;
    if (curr <= 0 && bit)
      return false;
    if (curr > 0 && !bit)
      unused.push_back(curr);
  }
  for (auto it1 : unused)
    for (auto it2 : unused)
      if (it1 != it2 && s[it1] == s[it2])
        return false;
  return true;
}

int solve() {
  scanf("%s", s + 1);
  N = strlen(s + 1);
  for (int i = 0; i <= N; i++)
    memset(dp[i], INF, sizeof dp[i]);
  dp[0][0] = 0;
  for (int i = 1; i <= N; i++)
    for (int j = 0; j < 8; j++) 
      if (check(i, j)) {
        for (int k = 0; k < 2; k++)
          dp[i][j] = min(dp[i][j], dp[i - 1][(j >> 1) | (k << 2)]);
        dp[i][j] += j & 1;
      }
  return *min_element(dp[N], dp[N] + 8);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    printf("%d\n", solve());
  return 0;
}