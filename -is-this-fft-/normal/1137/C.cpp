#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define ran(i, a, b) for (auto i = (a); i < (b); i++)

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
    ran(u, 0, n) {
      for (auto v : con[u]) revcon[v].push_back(u);
    }

    vector<int> result;
    vector<bool> explr(n, false);
    ran(i, 0, n) top_dfs(i, result, explr, revcon);
    reverse(result.begin(), result.end());
    return result;
  }

  void dfs(
    int pos, vector<int> &result, vector<bool> &explr) {
    if (explr[pos]) return;
    explr[pos] = true;
    for (auto next : con[pos]) dfs(next, result, explr);
    result.push_back(pos);
  }
  vector<vector<int> > scc() {
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
  }
};

int gcd (int p, int q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];
string open [MAX_N];

int vis [MAX_N];
int scc_id [MAX_N];
int pot [MAX_N];

void proc_scc_dfs (int u, int _pot) {
  pot[u] = _pot;
  vis[u] = 1;

  for (int nxt : adj[u]) {
    if (scc_id[nxt] == scc_id[u]) {
      if (!vis[nxt]) {
        proc_scc_dfs(nxt, _pot + 1);
      }
    }
  }
}

const int MAX_D = 55;

int maxm [MAX_N][MAX_D];
int period [MAX_N];

int d;
void proc_scc (const vector<int> &scc) {
  for (int u : scc) {
    scc_id[u] = scc[0];
  }

  proc_scc_dfs(scc[0], 0);
  int prd = d;
  for (int u : scc) {
    for (int v : adj[u]) {
      if (scc_id[v] == scc[0]) {
        prd = gcd(prd, abs(pot[u] + 1 - pot[v]));
      }
    }
  }
  
  for (int u : scc) {
    pot[u] %= prd;
  }

  for (int i = 0; i < prd; i++) {
    for (int u : scc) {
      int add = 0;
      for (int j = (i + pot[u]) % prd; j < d; j += prd) {
        if (open[u][j] == '1') add = 1;
      }

      maxm[scc[0]][i] += add;
    }
  }

  for (int i = prd; i < d; i++) {
    maxm[scc[0]][i] = maxm[scc[0]][i - prd];
  }

  if (scc[0] == 0) {
    for (int i = 1; i < d; i++) {
      maxm[scc[0]][i] = 0;
    }
  }

  period[scc[0]] = prd;
}

vector<pair<int, int>> scc_adj [MAX_N]; // <nxt, offset>

void make_links (const vector<int> &scc) {
  for (int u : scc) {
    for (int nxt : adj[u]) {
      if (scc_id[nxt] != scc_id[u]) {
        int mod = gcd(period[scc_id[nxt]], period[scc_id[u]]);
        //int mod = d;
        int offs = (pot[u] + 1 - pot[nxt]) % mod;
        if (offs < 0) offs += mod;
        scc_adj[scc_id[nxt]].push_back({scc_id[u], offs});
        // cerr << " " << scc_id[u] << " -> " << scc_id[nxt] << " " << offs << endl;
      }
    }
  }
}

const int INF = 1 << 30;

int dp [MAX_N][MAX_D];
int svis [MAX_N];
void calc_dp (int u) {
  svis[u] = 1;
  if (u == 0) {
    for (int i = 0; i < d; i++) {
      dp[u][i] = -INF;
    }
    for (int i = 0; i < d; i += period[0]) {
      dp[u][i] = maxm[0][0];
    }
    return;
  }

  for (int i = 0; i < d; i++) {
    dp[u][i] = -INF;
  }
  
  for (auto pr : scc_adj[u]) {
    int prv = pr.first;
    if (!svis[prv]) calc_dp(prv);
    for (int i = 0; i < d; i++) {
      dp[u][i] = max(dp[u][i], dp[prv][(i + d - pr.second) % d]);
    }
  }

  for (int i = 0; i < d; i++) {
    dp[u][i] += maxm[u][i];
  }

  for (int i = period[u]; i < d; i++) {
    dp[u][i] = max(dp[u][i], dp[u][i - period[u]]);
  }
  for (int i = d - period[u] - 1; i >= 0; i--) {
    dp[u][i] = max(dp[u][i], dp[u][i + period[u]]);
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m >> d;

  for (int i = 0; i < n; i++) {
    scc_id[i] = -1;
  }

  Graph G (n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;v--;

    adj[u].push_back(v);
    G.add_edge(u, v);
  }

  for (int i = 0; i < n; i++) {
    cin >> open[i];
  }

  vector<vector<int>> sccs = G.scc();
  for (int i = 0; i < (int) sccs.size(); i++) {
    sort(sccs[i].begin(), sccs[i].end());
  }

  for (int i = 0; i < (int) sccs.size(); i++) {
    if (!sccs[i].empty()) 
      proc_scc(sccs[i]);
  }

  for (int i = 0; i < (int) sccs.size(); i++) {
    if (!sccs[i].empty())
      make_links(sccs[i]);
  }

  for (int i = 0; i < (int) sccs.size(); i++) {
    if (!sccs[i].empty()) {
      if (!svis[sccs[i][0]]) {
        calc_dp(sccs[i][0]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d; j++) {
      ans = max(ans, dp[i][j]);
    }
  }
  
  cout << ans << endl;

  /*
  for (int i = 0; i < n; i++) {
    cout << i << " " << scc_id[i] << " " << pot[i] << endl;
  }
  */
}