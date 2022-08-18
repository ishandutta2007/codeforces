#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Graph {
  int n;
  vector<vector<int> > con;

  Graph(int nsize) {
    n = nsize;
    con.resize(n);
  }

  void add_edge(int u, int v) { con[u].push_back(v); }

  void top_dfs(int pos, vector<int> &result,
    vector<bool> &explr, vector<vector<int> > &revcon) {
    if (explr[pos]) return;
    explr[pos] = true;
    for (auto next : revcon[pos])
      top_dfs(next, result, explr, revcon);
    result.push_back(pos);
  }

  vector<int> topsort() {
    vector<vector<int> > revcon(n);
    for (int u = 0; u < n; u++) {
      for (auto v : con[u]) revcon[v].push_back(u);
    }

    vector<int> result;
    vector<bool> explr(n, false);
    for (int i = 0; i < n; i++) {
      top_dfs(i, result, explr, revcon);
    }
    reverse(result.begin(), result.end());
    return result;
  }/*ly*/

  void dfs(
    int pos, vector<int> &result, vector<bool> &explr) {
    if (explr[pos]) return;
    explr[pos] = true;
    for (auto next : con[pos]) dfs(next, result, explr);
    result.push_back(pos);
  }/*ry*//*lp*/
  vector<vector<int> > scc() {
    //!pause
    // tested on
    // https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-comps/practice-problems/algorithm/a-walk-to-remember-qualifier2/
    //!unpause
    vector<int> order = topsort();
    reverse(order.begin(), order.end());
    vector<bool> explr(n, false);
    vector<vector<int> > res;
    for (auto it = order.rbegin(); it != order.rend();
         ++it) {
      vector<int> comp;
      top_dfs(*it, comp, explr, con);
      sort(comp.begin(), comp.end());
      res.push_back(comp);
    }
    sort(res.begin(), res.end());
    return res;
  }/*rp*/
};

const int L = 1000;
const int MAX_N = 5e3 + 5;

int sink [MAX_N];
int comp [MAX_N];
vector<int> adj [MAX_N];
int dist [MAX_N];

int shortest (const vector<int> &scc, int idx) {
  int ans = MAX_N;
  for (int u : scc) {
    for (int i = 0; i < MAX_N; i++) {
      dist[i] = MAX_N;
    }

    dist[u] = 0;
    queue<int> Q;
    Q.push(u);

    while (!Q.empty()) {
      int cur = Q.front();
      Q.pop();

      for (int nxt : adj[cur]) {
        if (nxt == u) {
          ans = min(ans, dist[cur] + 1);
          break;
        } else if (dist[nxt] == MAX_N) {
          dist[nxt] = dist[cur] + 1;
          Q.push(nxt);
        }
      }
    }
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  Graph G (n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;

    G.add_edge(u, v);
    adj[u].push_back(v);
  }

  vector<vector<int>> sccs = G.scc();
  for (int i = 0; i < (int) sccs.size(); i++) {
    for (int j = 0; j < (int) sccs[i].size(); j++) {
      comp[sccs[i][j]] = i;
    }
    sink[i] = 1;
    if (sccs[i].empty()) sink[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    for (int nxt : adj[i]) {
      if (comp[nxt] != comp[i]) sink[comp[i]] = 0;
    }
  }

  int ans = n;
  for (int i = 0; i < (int) sccs.size(); i++) {
    if (sink[i]) {
      if (sccs[i].size() == 1) {
        
      } else {
        int len = shortest(sccs[i], i);
        ans += 1;
        ans += len * (L - 2);
      }
    }
  }

  cout << ans << endl;
}