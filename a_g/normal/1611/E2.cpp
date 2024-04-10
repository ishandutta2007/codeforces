#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;

unordered_set<int> friends;
vector<vector<int>> adj;
vector<int> times;
int ans;

void update_times(unordered_set<int>& positions, int t) {
  unordered_set<int> nextpos;
  for (int x: positions) {
    times[x] = t;
    for (int u: adj[x]) {
      if (times[u] == INF && !positions.count(u)) {
        nextpos.insert(u);
      }
    }
  }
  if (!nextpos.empty()) update_times(nextpos, t+1);
}

bool dfs(int v, int p, int t) {
  if (times[v] <= t) {
    ans++;
    return 0;
  }
  if (adj[v].size() == 1 && v != 0) {
    return 1;
  }
  for (int u: adj[v]) {
    if (u != p && dfs(u, v, t+1)) return 1;
  }
  return 0;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    friends.clear();
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      x--;
      friends.insert(x);
    }
    times.clear();
    times.resize(n, INF);
    adj.clear();
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    update_times(friends, 0);
    ans = 0;
    cout << (dfs(0, 0, 0) ? -1 : ans) << '\n';
  }
}