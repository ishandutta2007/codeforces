#include <bits/stdc++.h>
using namespace std;

const int MAXK = 12;
const int MAXN = 1e5 + 5;

int N, K, Q;
int a[MAXK][MAXN];
bitset <1 << MAXK> dp[MAXN + MAXK];

void load() {
  scanf("%d%d%d", &N, &K, &Q);
  for (int i = 0; i < K; i++)
    for (int j = 0; j < N; j++)
      scanf("%d", a[i] + j);
}

int query(int who, int ch) {
  int res = 0;
  for (int i = 0; i < K; i++) {
    int mask = 0;
    for (int j = 0; j < K; j++)
      if (a[j][ch] >= a[i][ch])
        mask |= 1 << j;
    if (dp[who].test(mask))
      res = max(res, a[i][ch]);
  }
  return res;
}

void solve() {
  for (int i = 0; i < 1 << K; i++)
    for (int j = 0; j < K; j++)
      if (i >> j & 1)
        dp[j].set(i);
  int curr = K;
  while (Q--) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    x--; y--;
    if (t == 1)
      dp[curr++] = dp[x] | dp[y];
    else if (t == 2)
      dp[curr++] = dp[x] & dp[y];
    else 
      printf("%d\n", query(x, y));
  }
}

int main() {
  load();
  solve();
  return 0;
}