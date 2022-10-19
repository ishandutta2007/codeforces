#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
int a[N], sz[N], dp[N];
vector<int> G[N];
int mid, k;
bool good = 0;

multiset<int, greater<int>> incomplete_subtree_parts[N];

void dfs1(int v, int p) {
  incomplete_subtree_parts[v].clear();
  sz[v] = 1;
  dp[v] = 1;
  for (int u: G[v]) {
    if (u == p) continue;
    dfs1(u, v);
    sz[v] += sz[u];
    if (dp[u] == sz[u]) dp[v] += dp[u];
    else incomplete_subtree_parts[v].insert(dp[u]);
  }
  if (incomplete_subtree_parts[v].size()) {
    dp[v] += *incomplete_subtree_parts[v].begin();
  }
  if (a[v] < mid) dp[v] = 0;
}

void reroot(int v, int u) {
  // root was v, now it's u
  if (incomplete_subtree_parts[v].size()) {
    dp[v] -= *incomplete_subtree_parts[v].begin();
  }
  if (dp[u] < sz[u]) {
    assert(incomplete_subtree_parts[v].find(dp[u]) != incomplete_subtree_parts[v].end());
    incomplete_subtree_parts[v].erase(incomplete_subtree_parts[v].find(dp[u]));
  }
  else {
    dp[v] -= dp[u];
  }
  if (incomplete_subtree_parts[v].size()) {
    dp[v] += *incomplete_subtree_parts[v].begin();
  }
  sz[v] -= sz[u];
  if (a[v] < mid) dp[v] = 0;

  if (incomplete_subtree_parts[u].size()) {
    dp[u] -= *incomplete_subtree_parts[u].begin();
  }
  if (dp[v] < sz[v]) {
    incomplete_subtree_parts[u].insert(dp[v]);
  }
  else {
    dp[u] += dp[v];
  }
  if (incomplete_subtree_parts[u].size()) {
    dp[u] += *incomplete_subtree_parts[u].begin();
  }
  sz[u] += sz[v];
  if (a[u] < mid) dp[u] = 0;
}

void dfs2(int v, int p) {
  if (dp[v] >= k) good = 1;
  if (good) return;
  for (int u: G[v]) {
    if (u == p) continue;
    reroot(v, u);
    dfs2(u, v);
    reroot(u, v);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int low = 1;
  int high = 1e6+1;
  while (high-low > 1) {
    mid = (low+high)/2;
    good = 0;
    dfs1(1, 1);
    dfs2(1, 1);
    if (good) low = mid;
    else high = mid;
  }
  cout << low << '\n';
}