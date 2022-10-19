#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
const int INF = 1e9+1e6;
long long s[N];
set<pair<int, int>> edges[N];
map<pair<int, int>, int> weights;
multiset<long long> s3;
set<pair<int, pair<int, int>>> good_edges;

pair<int, int> third_best_edge(int v) {
  if (edges[v].size() < 3) return make_pair(INF, -1);
  auto it = edges[v].begin();
  advance(it, 2);
  return *it;
}

inline void insert_subroutine(int u, int v, int w) {
  pair<int, int> e = make_pair(w, v);
  pair<int, int> old_e = third_best_edge(u);
  if (e < old_e) {
    int old_v = old_e.second;
    pair<int, pair<int, int>> e2 = {old_e.first, {min(old_v, u), max(old_v, u)}};
    good_edges.erase(e2);
    if ((int)edges[u].size() >= 3) s3.erase(s3.find(s[u]));
    s[u] += w-old_e.first;
    if ((int)edges[u].size() >= 2) s3.insert(s[u]);
  }
  edges[u].insert(e);
}

void check_good(int u, int v, int w) {
  assert(u < v);
  if (u < 0) return;
  if (make_pair(w, v) <= third_best_edge(u) && make_pair(w, u) <= third_best_edge(v)) {
    good_edges.insert(make_pair(w, make_pair(u, v)));
  }
}

void insert(int u, int v, int w) {
  if (u > v) swap(u, v);
  insert_subroutine(u, v, w);
  insert_subroutine(v, u, w);
  weights[make_pair(u, v)] = w;
  check_good(u, v, w);
}

inline void remove_subroutine(int u, int v, int w) {
  pair<int, int> e = make_pair(w, v);
  edges[u].erase(e);
  pair<int, int> new_e = third_best_edge(u);
  if (e < new_e) {
    int new_v = new_e.second;
    check_good(min(new_v, u), max(new_v, u), new_e.first);
    if ((int)edges[u].size() >= 2) s3.erase(s3.find(s[u]));
    s[u] += new_e.first-w;
    if ((int)edges[u].size() >= 3) s3.insert(s[u]);
  }
}

void remove(int u, int v) {
  if (u > v) swap(u, v);
  int w = weights[make_pair(u, v)];
  good_edges.erase(make_pair(w, make_pair(u, v)));
  weights.erase(make_pair(u, v));
  remove_subroutine(u, v, w);
  remove_subroutine(v, u, w);
}

void answer() {
  long long ans = (s3.size() ? *s3.begin() : 3LL*INF);
  int k = min(6, (int)good_edges.size());
  auto it = good_edges.begin();
  advance(it, k);
  vector<pair<int, pair<int, int>>> edge_list(good_edges.begin(), it);

  for (int i = 0; i < k; i++) {
    for (int j = i+1; j < k; j++) {
      pair<int, pair<int, int>> e1 = edge_list[i];
      pair<int, pair<int, int>> e2 = edge_list[j];
      long long cost = e1.first+e2.first;
      if (cost >= ans) break;
      int a = e1.second.first;
      int b = e1.second.second;
      int c = e2.second.first;
      int d = e2.second.second;
      if (a == c || a == d || b == c || b == d) continue;
      ans = cost;
      break;
    }
  }
  cout << ans << '\n';
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int v = 1; v <= n; v++) {
    s[v] = 3LL*INF;
  }

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    insert(u, v, w);
  }
  
  int q;
  cin >> q;

  answer();
  while (q--) {
    int k, u, v;
    cin >> k >> u >> v;
    if (k) {
      int w;
      cin >> w;
      insert(u, v, w);
    }
    else {
      remove(u, v);
    }
    answer();
  }
}