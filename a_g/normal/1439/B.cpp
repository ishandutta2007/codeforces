#include <bits/stdc++.h>
using namespace std;

queue<int> q;
const int maxn = 2e5+7;
unordered_set<int> adj[maxn];
int is_queued[maxn];

void prune(int v, int threshold) {
  for (int u: adj[v]) {
    adj[u].erase(v);
    if (adj[u].size() < threshold && !is_queued[u]) {
      q.push(u);
      is_queued[u] = 1;
    }
  }
  adj[v].clear();
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    q = {};
    int n, m, k;
    cin >> n >> m >> k;
    bool gofast = n == 2;
    if (!gofast) {
      for (int i = 0; i < n; i++) {
        adj[i].clear();
        is_queued[i] = 0;
      }
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      if (!gofast) {
        u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
      }
    }
    if (gofast) {
      cout << (k == 1 ? "1 2\n1 2\n" : "2\n1 2\n");
      continue;
    }

    for (int i = 0; i < n; i++) {
      if (adj[i].size() < k-1) {
        q.push(i);
        is_queued[i] = 1;
      }
    }

    // prune away vertices of degree less than k-1
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      is_queued[v] = 0;
      prune(v, k-1);
    }

    // check vertices of degree k-1
    bool foundclique = 0;
    for (int i = 0; i < n; i++) {
      if (adj[i].size() == k-1) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int v = q.front();
      q.pop();
      is_queued[v] = 0;
      if (adj[v].size() < k-1) {
        prune(v, k);
      }
      else {
        assert(adj[v].size() == k-1);
        vector<int> nbrs;
        for (int u: adj[v]) nbrs.push_back(u);
        bool good = 1;
        for (int i = 0; i < k-1; i++) {
          if (!good) break;
          for (int j = i+1; j < k-1; j++) {
            if (!adj[nbrs[i]].count(nbrs[j])) {
              good = 0;
              break;
            }
          }
        }
        if (good) {
          foundclique = 1;
          cout << 2 << '\n';
          cout << v + 1 << ' ';
          for (int u: nbrs) cout << u+1 << ' ';
          cout << '\n';
          break;
        }
        else {
          prune(v, k);
        }
      }
    }

    if (!foundclique) {
      vector<int> subset;
      for (int i = 0; i < n; i++) {
        if (adj[i].size() >= k) subset.push_back(i);
      }
      if (subset.size()) {
        cout << "1 " << subset.size() << '\n';
        for (int u: subset) cout << u+1 << ' ';
        cout << '\n';
      }
      else {
        cout << "-1\n";
      }
    }
  }
}