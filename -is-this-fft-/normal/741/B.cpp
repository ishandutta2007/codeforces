#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e3 + 5;
const int MAX_W = 1e3 + 5;
const int INF = 1e9 + 5;

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

int cost [MAX_N];
int beauty [MAX_N];

vector<int> grp [MAX_N];
int gr_cost [MAX_N];
int gr_beauty [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m, W;
  cin >> n >> m >> W;

  for (int i = 1; i <= n; i++) {
    root[i] = i;
  }
  
  for (int i = 1; i <= n; i++) {
    cin >> cost[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> beauty[i];
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    merge(u, v);
  }

  for (int i = 1; i <= n; i++) {
    grp[find(i)].push_back(i);
    gr_cost[find(i)] += cost[i];
    gr_beauty[find(i)] += beauty[i];
  }

  // max total beauty you can get at i
  vector<int> cur (W + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (!grp[i].empty()) {
      vector<int> nxt = cur;
      for (int j = 0; j + gr_cost[i] <= W; j++) {
        nxt[j + gr_cost[i]] = max(nxt[j + gr_cost[i]], cur[j] + gr_beauty[i]);
      }

      for (int u : grp[i]) {
        for (int j = 0; j + cost[u] <= W; j++) {
          nxt[j + cost[u]] = max(nxt[j + cost[u]], cur[j] + beauty[u]);
        }
      }
      cur = nxt;
    }
  }

  int ans = 0;
  for (int b : cur) {
    ans = max(ans, b);
  }
  cout << ans << endl;
}