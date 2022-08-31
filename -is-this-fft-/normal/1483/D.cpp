#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll INF = 1e18 + 2000;
const int MAX_N = 605;

ll dist [MAX_N][MAX_N];

vector<pair<int, ll>> adj [MAX_N];
vector<pair<int, ll>> trip [MAX_N];

void add_edge (int u, int v, ll w) {
  adj[u].push_back(make_pair(v, w));
  adj[v].push_back(make_pair(u, w));

  dist[u][v] = w;
  dist[v][u] = w;
}

void add_trip (int u, int v, ll w) {
  trip[u].push_back(make_pair(v, w));
  trip[v].push_back(make_pair(u, w));
}

bool useful [MAX_N][MAX_N];

ll mn [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = INF;
    }
    dist[i][i] = 0;
  }

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    add_edge(u, v, w);
  }

  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    add_trip(u, v, w);
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
      }
    }
  }

  for (int u = 1; u <= n; u++) {
    for (int b = 1; b <= n; b++) {
      mn[b] = -INF;
      for (auto v : trip[u]) {
        mn[b] = max(mn[b], v.second - dist[b][v.first]);
      }
    }

    for (int a = 1; a <= n; a++) {
      for (auto e : adj[a]) {
        int b = e.first;
        ll w = e.second;

        if (dist[u][a] + w <= mn[b]) {
          useful[a][b] = true;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (useful[i][j] || useful[j][i]) {
        ans++;
      }
    }
  }

  cout << ans << endl;
}