#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<vector<pii>> nbrs;
int l, n;

int timer;
vector<int> tin, tout;
vector<vector<pii>> up;

void dfs(int v, int p, int t) {
  tin[v] = ++timer;
  up[v][0] = {p, t};
  for (int i = 1; i <= l; ++i)
    up[v][i] = {
      up[up[v][i-1].first][i-1].first,
      max(up[v][i-1].second, up[up[v][i-1].first][i-1].second)
    };

  for (pii u : nbrs[v]) {
    if (u.first != p)
      dfs(u.first, v, u.second);
  }

  tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int maxcost(int u, int v) {
  int ans = 0;
  for (int i = l; i >= 0; --i) {
    if (!is_ancestor(up[u][i].first, v)) {
      ans = max(ans, up[u][i].second);
      u = up[u][i].first;
    }
    if (!is_ancestor(up[v][i].first, u)) {
      ans = max(ans, up[v][i].second);
      v = up[v][i].first;
    }
  }
  if (!is_ancestor(u, v)) {
    ans = max(ans, up[u][0].second);
  }
  if (!is_ancestor(v, u)) {
    ans = max(ans, up[v][0].second);
  }
  return ans;
}

void preprocess(int root) {
  tin.resize(n);
  tout.resize(n);
  timer = 0;
  l = ceil(log2(n));
  up.assign(n, vector<pii>(l + 1));
  dfs(root, root, 0);
}

class dsu {
  public:
    vector<int> parents;
    vector<int> ranks;
    vector<int> enjoyment;
    vector<int> argenj;
    vector<int> tol;
    dsu (int n, vector<int>& e) {
      parents.resize(n);
      iota(parents.begin(), parents.end(), 0);
      argenj.resize(n);
      iota(argenj.begin(), argenj.end(), 0);
      ranks.resize(n);
      tol.resize(n);
      enjoyment = e;
    }
    int root(int u) {
      return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v, int t) {
      int a = root(u);
      int b = root(v);
      if (a == b) return 0;
      if (ranks[a] > ranks[b]) swap(a, b);
      // b has higher rank
      parents[a] = b;
      if (ranks[a] == ranks[b]) ranks[b]++;
      if (enjoyment[b] < enjoyment[a]) {
        tol[b] = tol[a];
        argenj[b] = argenj[a];
        enjoyment[b] = enjoyment[a];
      }
      else if (enjoyment[b] == enjoyment[a]) {
        tol[b] = max({tol[a], tol[b], maxcost(argenj[a], v), maxcost(argenj[b], v)});
      }
      return 1;
    }
    int get_enjoyment(int v) {
      return enjoyment[root(v)];
    }
    int get_argenj(int v) {
      return argenj[root(v)];
    }
    int get_tol(int v) {
      return tol[root(v)];
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> n >> q;
  vector<int> enjoyment(n);
  for (int i = 0; i < n; i++) cin >> enjoyment[i];

  vector<tuple<int, int, int, int>> edges(n-1);
  nbrs.resize(n);
  for (int i = 0; i < n-1; i++) {
    int a, b, c, t;
    cin >> a >> b >> c >> t;
    a--, b--;
    edges[i] = {c, a, b, t};
    nbrs[a].push_back({b, t});
    nbrs[b].push_back({a, t});
  }
  preprocess(0);

  vector<tuple<int, int, int>> queries(q);
  vector<pii> answers(q);
  for (int i = 0; i < q; i++) {
    int v, x;
    cin >> v >> x;
    x--;
    queries[i] = {v, x, i};
  }
  sort(queries.begin(), queries.end(), greater<tuple<int, int, int>>());

  sort(edges.begin(), edges.end(), greater<tuple<int, int, int, int>>());

  dsu d(n, enjoyment);
  int nextedge = 0;
  for (tuple<int, int, int> query: queries) {
    int v, x, i;
    tie(v, x, i) = query;
    while (nextedge < n-1 && get<0>(edges[nextedge]) >= v) {
      d.join(get<1>(edges[nextedge]), get<2>(edges[nextedge]), get<3>(edges[nextedge]));
      nextedge++;
    }
    answers[i].first = d.get_enjoyment(x);
    answers[i].second = max(d.get_tol(x), maxcost(x, d.get_argenj(x)));
  }
  for (pii ans: answers) {
    cout << ans.first << ' ' << ans.second << '\n';
  }
}