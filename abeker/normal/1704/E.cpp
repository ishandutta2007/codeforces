#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
const int MOD = 998244353;

int N, M;
int a[MAXN], b[MAXN];
vector <int> out[MAXN];
int dp[MAXN];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) {
    scanf("%d", a + i);
    out[i].clear();
    dp[i] = -1;
  }
  while (M--) {
    int x, y;
    scanf("%d%d", &x, &y);
    out[x].push_back(y);
  }
}

inline void add(int &x, int y) {
  x += y;
  if (x >= MOD)
    x -= MOD;
}

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

int rec(int x) {
  int &ref = dp[x];
  if (ref != -1)
    return ref;
  ref = 0;
  for (auto it : out[x])
    add(ref, rec(it));
  return ref;
}

int solve() {
  int sink = 0;
  for (int i = 1; i <= N; i++)
    if (out[i].empty())
      sink = i;
  dp[sink] = 1;
  int last = 0, sol = 0;
  for (int i = 1; i <= N; i++)
    add(sol, mul(a[i], rec(i)));
  for (int i = 1; i <= N; i++) {
    if (a[sink]) {
      add(sol, -1);
      last = i;
    }
    for (int j = 1; j <= N; j++)
      b[j] = a[j];
    for (int j = 1; j <= N; j++)
      if (a[j]) {
        b[j]--;
        for (auto it : out[j])
          b[it]++;
      }
    for (int j = 1; j <= N; j++)
      a[j] = b[j];
  }
  add(sol, last);
  return sol;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%d\n", solve());
  }
  return 0;
}