#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;
const ll INF = 1e18 + 5;
const int MAX_LG = 18;

namespace Tree {
  vector<pair<int, ll>> adj [MAX_N];
  
  void add_edge (int u, int v, ll w) {
    //  cerr << u << " " << v << " " << w << endl;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  int jmp [MAX_N][MAX_LG];
  ll jmpmax [MAX_N][MAX_LG];
  int lvl [MAX_N];

  void build (int u, int par, ll parw) {
    lvl[u] = lvl[par] + 1;
    jmp[u][0] = par;
    jmpmax[u][0] = parw;
    for (int i = 1; i < MAX_LG; i++) {
      jmp[u][i] = jmp[jmp[u][i - 1]][i - 1];
      jmpmax[u][i] = max(jmpmax[u][i - 1], jmpmax[jmp[u][i - 1]][i - 1]);
    }

    for (auto nxt : adj[u]) {
      if (nxt.first != par) {
        build(nxt.first, u, nxt.second);
      }
    }
  }

  ll maxup (int u, int diff) {
    ll ans = 0;
    for (int i = 0; i < MAX_LG; i++) {
      if (diff & 1 << i) {
        ans = max(ans, jmpmax[u][i]);
        u = jmp[u][i];
      }
    }
    return ans;
  }
  
  int lca (int u, int v) {
    if (lvl[u] < lvl[v]) {
      swap(u, v);
    }

    int diff = lvl[u] - lvl[v];
    for (int i = 0; i < MAX_LG; i++) {
      if (diff & 1 << i) {
        u = jmp[u][i];
      }
    }

    if (u == v) {
      return u;
    }
    
    for (int i = MAX_LG - 1; i >= 0; i--) {
      if (jmp[u][i] != jmp[v][i]) {
        u = jmp[u][i];
        v = jmp[v][i];
      }
    }

    return jmp[u][0];
  }

  ll maxp (int u, int v) {
    int lc = lca(u, v);
    return max(maxup(u, lvl[u] - lvl[lc]),
               maxup(v, lvl[v] - lvl[lc]));
  }
}

vector<pair<int, ll>> adj [MAX_N];

int root [MAX_N];

int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  root[u] = v;
}

int src [MAX_N];
ll dist [MAX_N];
int vis [MAX_N];
pair<ll, int> closest [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  for (int i = 0; i < MAX_N; i++) {
    root[i] = i;
  }

  int vertexc, edgec, specc, queryc;
  cin >> vertexc >> edgec >> specc >> queryc;

  for (int i = 0; i < edgec; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  int compc = specc;
  while (compc > 1) {
    for (int i = 1; i <= vertexc; i++) {
      src[i] = 0;
      dist[i] = INF;
      vis[i] = 0;
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    for (int i = 1; i <= specc; i++) {
      src[i] = find(i);
      dist[i] = 0;
      closest[i] = make_pair(INF, 0);
      Q.push({0, i});
    }

    while (!Q.empty()) {
      int qtop = Q.top().second;
      Q.pop();

      if (!vis[qtop]) {
        vis[qtop] = 1;

        for (pair<int, ll> nxt : adj[qtop]) {
          if (dist[nxt.first] > dist[qtop] + nxt.second) {
            dist[nxt.first] = dist[qtop] + nxt.second;
            src[nxt.first] = src[qtop];
            Q.push(make_pair(dist[nxt.first], nxt.first));
          }
        }
      }
    }

    for (int i = 1; i <= vertexc; i++) {
      for (pair<int, ll> nxt : adj[i]) {
        if (src[i] != src[nxt.first]) {
          ll d = dist[i] + dist[nxt.first] + nxt.second;
          closest[src[i]] = min(closest[src[i]], {d, src[nxt.first]});
          closest[src[nxt.first]] = min(closest[src[nxt.first]], {d, src[i]});
        }
      }
    }

    for (int i = 1; i <= specc; i++) {
      if (src[i] == i) {
        if (find(i) != find(closest[i].second)) {
          merge(i, closest[i].second);
          compc--;
          Tree::add_edge(i, closest[i].second, closest[i].first);
        }
      }
    }
  }

  Tree::build(1, 1, 0);
  
  for (int i = 0; i < queryc; i++) {
    int u, v;
    cin >> u >> v;

    cout << Tree::maxp(u, v) << '\n';
  }
}