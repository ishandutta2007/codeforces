#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
vector<int> children[N];
int p[N];
int rnk[N];
bool seen[N];
vector<int> dp[N];
set<int> dpset[N];
// dp[v][rnk[v]-k] = Nim value of subtree of v after cutting k layers

void dfs(int v) {
  rnk[v] = (children[v].size() ? 1e9 : 1);
  for (int u: children[v]) {
    dfs(u);
    rnk[v] = min(rnk[v], rnk[u]+1);
  }
  if (children[v].size() == 1) {
    int u = children[v][0];
    swap(dp[v], dp[u]);
    swap(dpset[v], dpset[u]);
    int val = dp[v].back();
    while (dpset[v].count(val)) {
      val++;
    }
    dp[v].push_back(val);
    dpset[v].insert(val);
    return;
  }
  dp[v].resize(rnk[v]+1);
  for (int i = 0; i <= rnk[v]+1; i++) {
    seen[i] = 0;
  }
  for (int i = 1; i <= rnk[v]; i++) {
    for (int u: children[v]) {
      dp[v][rnk[v]-i] ^= dp[u][rnk[u]-(i-1)];
    }
    dpset[v].insert(dp[v][rnk[v]-i]);
    seen[dp[v][rnk[v]-i]] = 1;
  }
  for (int i = 0; i <= rnk[v]+1; i++) {
    if (!seen[i]) {
      dp[v][rnk[v]] = i;
      break;
    }
  }
  dpset[v].insert(dp[v][rnk[v]]);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      dp[i].clear();
      children[i].clear();
      dpset[i].clear();
    }
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
      if (p[i]) {
        children[p[i]].push_back(i);
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (!p[i]) {
        dfs(i);
        ans ^= dp[i].back();
      }
    }
    cout << (ans ? "YES" : "NO") << '\n';
  }
}