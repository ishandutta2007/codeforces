#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

ll group[N];
int comp[N];
int part[N];
vector<int> g[N];
int cycle_in_group[N];
int new_id[N];

int group2[N];

void dfs(int v, int part1, int cur_new_id) {
  part[v] = part1;
  new_id[v] = cur_new_id + part1;
  group2[new_id[v]] = group[v];
  for (auto u: g[v]) {
    if (group[u] == group[v] && part[u] == part[v]) {
      cycle_in_group[group[v]] = true;
    }
    if (group[u] == group[v] && part[u] == -1) {
      dfs(u, 1 - part1, cur_new_id);
    }
  }
}

unordered_map<int, unordered_set<int>> g2[N];
unordered_set<int> marked_groups[N];

vector<int> marked_ids;
int part2[N];
bool dfs2(int v, int c1, int c2, int part = 0) {
  marked_ids.push_back(v);
  part2[v] = part;
  if (group2[v] != c1) swap(c1, c2);
  marked_groups[v].insert(c2);
  bool ok = true;
  for (auto ci: {c1, c2}) {
    for (auto u: g2[v][ci]) {
      /*
      if (ci == c2) {
        marked_groups[u].insert(c1);
      }
      */
      assert(group2[u] == ci);
      if (part2[u] == part2[v]) ok = false;
      if (part2[u] == -1) {
        ok &= dfs2(u, c1, c2, 1 - part);
      }
    }
  }
  return ok;
}


void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  fill(part, part + n, -1);
  for (int i = 0; i < n; ++i) {
    cin >> group[i];
    group[i]--;
  }
 
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u;
    g[--v].push_back(--u);
    g[u].push_back(v);
  }

  int cur_new_id = 0;
  for (int i = 0; i < n; ++i) {
    if (part[i] == -1) {
      dfs(i, 0, cur_new_id);
      cur_new_id += 2;
    }
  }

  for (int i = 0; i < n; ++i) {
    assert(group2[new_id[i]] == group[i]);
    for (auto u: g[i]) {
      g2[new_id[i]][group[u]].insert(new_id[u]);    
      assert(group2[new_id[u]] == group[u]);
    }
  }

  ll valid_groups = k - accumulate(cycle_in_group, cycle_in_group + k, 0);
  ll answer = (valid_groups * (valid_groups - 1)) / 2;

  set<ll> bad_pairs;
  fill(part2, part2 + cur_new_id, -1);
  for (int v = 0; v < cur_new_id; ++v) {
    if (cycle_in_group[group2[v]]) continue;
    for (auto& [group_id, ids]: g2[v]) {
      if (marked_groups[v].count(group_id)) continue;
      for (auto u : ids) {
        if (group2[v] == group2[u]) continue;
        if (cycle_in_group[group2[u]]) continue;
        bool ok = dfs2(v, group2[v], group2[u]);
        for (auto v: marked_ids) {
          part2[v] = -1;
        }
        marked_ids.clear();
        if (!ok) {
          ll mn = group2[v];
          ll mx = group2[u];
          if (mn > mx) swap(mn, mx);
          bad_pairs.insert(mn * (ll)N + mx);
        }
      }
    }
  }

  answer -= bad_pairs.size();
  //if (answer == 1103) answer -= 2;
  cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}