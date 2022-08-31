#include <iostream>
#include <vector>

using namespace std;

void failure () {
  cout << -1 << endl;
  exit(0);
}

const int MAX_N = 1e5 + 5;

vector<pair<int, int>> edges;
vector<int> adj [MAX_N];
int ans [MAX_N];

typedef long long ll;

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    edges.push_back({u, v});
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    ans[i] = 1;
  }

  if (adj[1].empty()) failure();

  for (int u : adj[1]) {
    ans[u] = 2;
  }

  int w = adj[1][0];
  for (int u : adj[w]) {
    if (ans[u] == 2) ans[u] = 3;
  }

  vector<int> cnt (4, 0);
  for (int i = 1; i <= n; i++) {
    cnt[ans[i]]++;
  }

  if (cnt[1] == 0 || cnt[2] == 0 || cnt[3] == 0) failure();
  
  if ((ll) cnt[1] * cnt[2] + (ll) cnt[1] * cnt[3] + (ll) cnt[2] * cnt[3] != m) failure();

  for (auto pr : edges) {
    int u = pr.first;
    int v = pr.second;
    if (ans[u] == ans[v]) failure();
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}