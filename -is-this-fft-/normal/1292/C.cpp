#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 3e3 + 5;

vector<int> adj [MAX_N];
ll sub_sz [MAX_N][MAX_N]; // subtree size from u in dir of v
int dist [MAX_N][MAX_N];

ll dfs (int u, int p, int src, int cur_dist) {
  ll sz = 1;
  dist[src][u] = cur_dist;

  for (int nxt : adj[u]) {
    if (nxt != p) {
      ll csz = dfs(nxt, u, src, cur_dist + 1);
      sz += csz;
    }
  }

  sub_sz[src][u] = sz;
  return sz;
}

void prop (int u, int p, int src) {
  if (p != src) {
    sub_sz[src][u] = sub_sz[src][p];
  }
  
  for (int nxt : adj[u]) {
    if (nxt != p) {
      prop(nxt, u, src);
    }
  }
}

int n;
ll subt_oth (int u, int x) {
  return n - sub_sz[u][x];
}

ll dp [MAX_N][MAX_N];
int vis [MAX_N][MAX_N];

int main () {
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    dfs(i, i, i, 0);
    prop(i, i, i);
  }

  vector<pair<int, int>> Q;
  for (int u = 1; u <= n; u++) {
    for (int v : adj[u]) {
      if (u < v) {
        dp[u][v] = subt_oth(u, v) * subt_oth(v, u);
        Q.push_back({u, v});
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i < (int) Q.size(); i++) {
    int u = Q[i].first;
    int v = Q[i].second;

    // extend u-side
    if (!vis[u][v]) {
      vis[u][v] = 1;
      for (int w : adj[u]) {
        if (dist[w][v] > dist[u][v]) {
          if (w < v) {
            dp[w][v] = max(dp[w][v], dp[u][v] + subt_oth(w, v) * subt_oth(v, w));
            Q.push_back({w, v});
          } else {
            dp[v][w] = max(dp[v][w], dp[u][v] + subt_oth(w, v) * subt_oth(v, w));
            Q.push_back({v, w});
          }
        }
      }

      // extend v-side
      for (int w : adj[v]) {
        if (dist[u][w] > dist[u][v]) {
          if (u < w) {
            dp[u][w] = max(dp[u][w], dp[u][v] + subt_oth(u, w) * subt_oth(w, u));
            Q.push_back({u, w});
          } else {
            dp[w][u] = max(dp[w][u], dp[u][v] + subt_oth(u, w) * subt_oth(w, u));
            Q.push_back({w, u});
          }
        }
      }
    }
    ans = max(ans, dp[u][v]);
  }

  cout << ans << endl;
}