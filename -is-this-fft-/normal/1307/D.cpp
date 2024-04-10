#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> adj [MAX_N];

void bfs (int src, vector<int> &ans) {
  for (int i = 0; i < (int) ans.size(); i++) {
    ans[i] = MAX_N;
  }

  queue<int> Q;
  Q.push(src);
  ans[src] = 0;
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();

    for (int nxt : adj[cur]) {
      if (ans[nxt] == MAX_N) {
        ans[nxt] = ans[cur] + 1;
        Q.push(nxt);
      }
    }
  }
}

vector<int> dist1;
vector<int> distn;

int main () {
  ios::sync_with_stdio(false);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> spec (k);
  for (int i = 0; i < k; i++) {
    cin >> spec[i];
  }
  
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dist1 = vector<int> (n + 1);
  distn = vector<int> (n + 1);
  bfs(1, dist1);
  bfs(n, distn);

  vector<pair<int, int>> ordspec;
  for (int u : spec) {
    ordspec.push_back(make_pair(dist1[u] - distn[u], u));
  }
  sort(ordspec.begin(), ordspec.end());

  int sp = dist1[n];
  int maxd1 = -MAX_N;
  int ans = 0;
  for (auto pr : ordspec) {
    int u = pr.second;

    ans = max(ans, min(sp, maxd1 + distn[u] + 1));
    maxd1 = max(maxd1, dist1[u]);
  }

  cout << ans << endl;
}