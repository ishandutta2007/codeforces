#include <bits/stdc++.h>
#define bc __builtin_popcount
using namespace std;

typedef long long ll;

const int MAXN = 18;

int N;
char adj[MAXN + 1][MAXN + 1];
ll dp[1 << MAXN][MAXN];
ll paths[MAXN][1 << MAXN];
ll ans[1 << MAXN - 1];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%s", adj[i]);
}

ll count_paths(int mask, int last) {
  ll &ref = dp[mask][last];
  if (ref != -1)
    return ref;
  ref = 0;
  if (!(mask >> last & 1))
    return ref;
  mask ^= 1 << last;
  if (!mask)
    return ref = 1;
  for (int i = 0; i < N; i++)
    if (adj[i][last] == '1')
      ref += count_paths(mask, i);
  return ref;
}

void sos_dp(ll arr[1 << MAXN]) {
  for (int j = N - 1; j >= 0; j--)
    for (int i = (1 << N) - 1; i >= 0; i--)
      if (i >> j & 1)
        arr[i] += arr[i ^ 1 << j];
}

void calc(int mask) {
  int last = -1;
  vector <int> blocks;
  for (int i = 0; i < N; i++)
    if (!(mask >> i & 1)) {
      blocks.push_back(i - last);
      last = i;
    }
  sort(blocks.begin(), blocks.end());
  int sum = -1, sorted = (1 << N) - 1;
  for (auto it : blocks) {
    sum += it;
    sorted ^= 1 << sum;
  }
  if (ans[sorted] == -1) {
    ans[sorted] = 0;
    for (int i = 0; i < 1 << N; i++) {
      ll prod = 1;
      for (auto it : blocks)
        prod *= paths[it - 1][(1 << N) - 1 ^ i];
      ans[sorted] += bc(i) % 2 ? -prod : prod;
    }
  }
  ans[mask] = ans[sorted];
}

void solve() {
  memset(dp, -1, sizeof dp);
  memset(ans, -1, sizeof ans);
  for (int i = 1; i < 1 << N; i++) {
    ll &ref = paths[bc(i) - 1][i];
    for (int j = 0; j < N; j++)
      ref += count_paths(i, j);
  }
  for (int i = 0; i < N; i++)
    sos_dp(paths[i]);
  for (int i = 0; i < 1 << N - 1; i++)
    calc(i);
  for (int j = 0; j < N - 1; j++)
    for (int i = 0; i < 1 << N - 1; i++)
      if (!(i >> j & 1))
        ans[i] -= ans[i ^ 1 << j];
  for (int i = 0; i < 1 << N - 1; i++)
    printf("%lld ", ans[i]);
  puts("");
}

int main() {
  load();
  solve();
  return 0;
}