#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Graph {
  int n;
  vector<vector<int>> adj;

  void top_dfs (int pos, vector<int> &result,
                vector<bool> &explr, vector<vector<int>> &revadj) {
    if (explr[pos]) return;
    explr[pos] = true;
    for (auto next : revadj[pos]) {
      top_dfs(next, result, explr, revadj);
    }
    result.push_back(pos);
  }
  
public:
  Graph (int _n) : n(_n), adj(_n, vector<int> (0)) {}

  void add_edge (int u, int v) {
    adj[u].push_back(v);
  }

  vector<int> topsort () {
    vector<vector<int>> revadj (n);
    for (int u = 0; u < n; u++) {
      for (auto v : adj[u]) {
        revadj[v].push_back(u);
      }
    }

    vector<int> result;
    vector<bool> explr (n, false);
    for (int i = 0; i < n; i++) {
      top_dfs(i, result, explr, revadj);
    }
    reverse(result.begin(), result.end());
    return result;
  }
  
  vector<vector<int>> scc () {
    vector<int> order = topsort();
    reverse(order.begin(), order.end());
    vector<bool> explr (n, false);
    vector<vector<int>> res;
    for (auto it = order.rbegin(); it != order.rend();
         ++it) {
      vector<int> comp;
      top_dfs(*it, comp, explr, adj);
      sort(comp.begin(), comp.end());
      res.push_back(comp);
    }
    sort(res.begin(), res.end());
    return res;
  }
};

typedef long long ll;

const int MAX_N = 2e5 + 5;

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

int scid [MAX_N];
vector<pair<int, ll>> adj [MAX_N];

int vis [MAX_N];
ll pot [MAX_N];
void dfs (int u, ll &gc) {
  vis[u] = true;
  for (auto e : adj[u]) {
    int v = e.first;
    if (scid[v] != scid[u]) continue;
    ll w = e.second;
    if (vis[v]) {
      gc = gcd(gc, pot[u] - pot[v] + w); 
    } else {
      pot[v] = pot[u] + w;
      dfs(v, gc);
    }
  }
}

ll cmod [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  Graph G (n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;

    G.add_edge(u, v);
    adj[u].push_back(make_pair(v, w));
  }

  auto scc = G.scc();
  for (const auto &vec : scc) {
    if (vec.empty()) {
      continue;
    }
    
    int id = vec[0];
    for (int u : vec) {
      scid[u] = id;
    }
  }

  for (const auto &vec : scc) {
    if (vec.empty()) {
      continue;
    }

    ll gc = 0;
    dfs(vec[0], gc);
    cmod[vec[0]] = gc;
  }

  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    int u, s, t;
    cin >> u >> s >> t;
    u--;

    auto step = gcd(t, cmod[scid[u]]);
    if ((t - s) % step == 0) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}