#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
vector <int> adj[MAXN];
vector <int> dp;

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    int k;
    scanf("%d", &k);
    adj[i].resize(k);
    for (auto &it : adj[i])
      scanf("%d", &it);
  }
}

int rec(int x) {
  int &ref = dp[x];
  if (!ref)
    return ref = MAXN;
  if (ref != -1)
    return ref;
  ref = 0;
  int maks = 1;
  for (auto it : adj[x])
    maks = max(maks, rec(it) + (it > x));
  return ref = maks;
}

int solve() {
  dp = vector <int> (N + 1, -1);
  int sol = 0;
  for (int i = 1; i <= N; i++)
    sol = max(sol, rec(i));
  return sol < MAXN ? sol : -1;
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