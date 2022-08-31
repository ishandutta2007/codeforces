#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

typedef unsigned long long ull;

const int MAX_N = 1e5 + 5;

vector<int> adj_sets [MAX_N];
ull cur_bits [MAX_N];
void build_cur_bits (int u, int offset, int cap) {
  cur_bits[u] = 0;
  while (!adj_sets[u].empty() && adj_sets[u].back() < cap) {
    cur_bits[u] |= 1ULL << (adj_sets[u].back() - offset);
    adj_sets[u].pop_back();
  }
}

int n, qc;
pair<int, int> qs [MAX_N];
int ans [MAX_N];

void solve_block (int offset, int cap) {
  for (int i = 1; i <= n; i++) {
    build_cur_bits(i, offset, cap);
  }
  for (int i = 0; i < qc; i++) {
    ans[i] += __builtin_popcountll(cur_bits[qs[i].first] & cur_bits[qs[i].second]);
  }
}

void solve () {
  for (int i = 0; i < 2 * MAX_N; i += 64) {
    solve_block(i, i + 64);
  }
}

map<int, vector<int>> adj [MAX_N];
void add_edge (int u, int v, int co) {
  if (adj[u].count(co) == 0) {
    adj[u][co] = vector<int> (0);
  }
  adj[u][co].push_back(v);
}

set<int> vis [MAX_N];
void dfs (int u, int co, int idx) {
  adj_sets[u].push_back(idx);
  vis[u].insert(co);
  for (int nxt : adj[u][co]) {
    if (!vis[nxt].count(co)) {
      dfs(nxt, co, idx);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  int m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;

    add_edge(u, v, c);
    add_edge(v, u, c);
  }

  int cur = 0;
  for (int i = 1; i <= n; i++) {
    for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
      int co = it->first;
      if (!vis[i].count(co)) {
        dfs(i, co, cur);
        cur++;
      }
    }
  }
  
  // after dfs
  for (int i = 1; i <= n; i++) {
    reverse(adj_sets[i].begin(), adj_sets[i].end());
  }
  
  cin >> qc;
  for (int i = 0; i < qc; i++) {
    int u, v;
    cin >> u >> v;

    qs[i] = make_pair(u, v);
  }

  solve();
  for (int i = 0; i < qc; i++) {
    cout << ans[i] << '\n';
  }
}