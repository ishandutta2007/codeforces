#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MOD = 998244353;

const vector <int> trans = {0, 1, 3, 4, 6, 7};

char s[MAXN];
int dp[MAXN][8];

void load() {
  scanf("%s", s + 1);
}

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  if (x < 0)
    return x + MOD;
  return x;
}

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

int get_next(int pos, int prev, int mask) {
  int tmp = 0;
  for (int i = 0; i < 3; i++) {
    int bit = mask >> i & 1;
    int digit = s[pos] - '0';
    if (bit < digit)
      tmp |= 1 << i;
    else if (bit > digit && !(prev >> i & 1))
      return -1;
  }
  return prev | tmp;
}

int solve() {
  dp[0][0] = 1;
  int len = strlen(s + 1);
  for (int i = 1; i <= len; i++)
    for (int j = 0; j < 8; j++)
      for (auto it : trans) {
        int k = get_next(i, j, it);
        if (k != -1)
          dp[i][k] = add(dp[i][k], dp[i - 1][j]);
      }
  int N = 0;
  for (int i = 1; i <= len; i++)
    N = add(mul(N, 2), s[i] - '0');
  int tot = 0;
  for (int i = 0; i < 8; i++)
    tot = add(tot, dp[len][i]);
  tot = add(tot, -mul(add(N, 1), add(mul(N, 2), 1)));
  return add(mul(mul(N, add(N, -1)), add(N, 1)), -mul(3, tot));
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}