#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll INF = 1e14 + 5;
const int MAX_E = 2e5 + 5;
const int MAX_N = 2e5 + 5;

namespace Graph {
  ll cost [MAX_E];
  ll span [MAX_E];
  ll vis [MAX_N];

  vector<pair<ll, ll>> adj [MAX_N];

  void dfs (ll u, ll p, ll pe) {
    vis[u] = 1;
    span[pe] = 1;
    for (auto pr : adj[u]) {
      ll nxt = pr.first;
      ll e = pr.second;
      if (!vis[nxt]) {
        dfs(nxt, u, e);
      }
    }
  }
}

namespace Del {
  ll dead [MAX_N];
  ll lvl [MAX_N];
  ll onpath [MAX_N];
  ll insub [MAX_N];
  ll dp [MAX_N];
  ll pe [MAX_N];
  
  // first round of DFS to build the new tree
  // and decide the onpath and insub
  void dfs (ll u, ll p, ll t) {
    lvl[u] = lvl[p] + 1;
    if (insub[p]) {
      insub[u] = 1;
    }

    if (u == t) insub[u] = 1;
    
    for (auto pr : Graph::adj[u]) {
      ll nxt = pr.first;
      ll e = pr.second;
      if (!dead[e]) {
        if (lvl[nxt] == 0) {
          pe[nxt] = e;
          dfs(nxt, u, t);
          if (onpath[nxt]) {
            onpath[u] = 1;
          }
        }
      }
    }

    if (u == t) onpath[u] = 1;
  }

  // second round of DFS to find the answer
  void findb (ll u, ll p, pair<ll, ll> &ans) {
    for (auto pr : Graph::adj[u]) {
      ll nxt = pr.first;
      ll e = pr.second;
      if (!dead[e]) {
        if (pe[nxt] == e) {
          findb(nxt, u, ans);
          dp[u] += dp[nxt];
        } else if (pe[u] == e) {
        } else if (lvl[nxt] < lvl[u]) {
          // up-edge
          dp[u]++;
        } else if (lvl[nxt] > lvl[u]) {
          // down-edge
          dp[u]--;
        }
      }
    }

    if (p != 0 && (onpath[u] || insub[u]) && onpath[p]) {
      if (dp[u] == 0) {
        ans = min(ans, make_pair(Graph::cost[pe[u]], pe[u]));
      }
    }
  }

  ll solve (ll done, ll s, ll t, ll n) {
    dead[done] = 1;
    for (ll i = 1; i <= n; i++) {
      lvl[i] = 0;
      onpath[i] = 0;
      insub[i] = 0;
      pe[i] = 0;
      dp[i] = 0;
    }

    dfs(s, 0, t);
    if (lvl[t] == 0) {
      dead[done] = 0;
      return 0;
    }

    onpath[t] = 0;

    pair<ll, ll> ans = make_pair(INF, -1);
    findb(s, 0, ans);
    
    dead[done] = 0;
    return ans.second;
  }
}

int main () {
  ll n, m;
  cin >> n >> m;

  ll s, t;
  cin >> s >> t;

  for (ll i = 1; i <= m; i++) {
    ll u, v;
    cin >> u >> v >> Graph::cost[i];

    Graph::adj[u].push_back(make_pair(v, i));
    Graph::adj[v].push_back(make_pair(u, i));
  }
  
  Graph::dfs(s, 0, 0);

  if (!Graph::vis[t]) {
    cout << 0 << endl << 0 << endl;
    return 0;
  }
  
  pair<ll, vector<ll>> ans = make_pair(INF, vector<ll> (0));
  for (ll i = 1; i <= m; i++) {
    if (Graph::span[i]) {
      ll oth = Del::solve(i, s, t, n);
      // cerr << "  " << i << " " << oth << endl;
      if (oth != -1) {
        if (oth == 0) {
          ans = min(ans, make_pair(Graph::cost[i], vector<ll> ({i})));
        } else {
          ans = min(ans, make_pair(Graph::cost[i] + Graph::cost[oth],
                                   vector<ll> ({i, oth})));
        }
      }
    }
  }

  if (ans.first == INF) {
    cout << -1 << endl;
    return 0;
  }

  cout << ans.first << endl;
  cout << ans.second.size() << endl;
  for (ll e : ans.second) {
    cout << e << " ";
  }
  cout << endl;
}