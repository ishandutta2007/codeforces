#include <bits/stdc++.h>
 
// #define DEBUG
 
using namespace std;
 
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;
 
int n, m, k;
int d[N], vis[N];
vector<int> e[N];
 
inline void solve() {
  queue<int> q;
  vector<int> clique;
  cin >> n >> m >> k;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
    ++d[u];
    ++d[v];
  }
  int r = n;
  for (int i = 1; i <= n; ++i) {
    if (d[i] < k) q.push(i);
    sort(e[i].begin(), e[i].end());
  }
  while (q.size()) {
    int u = q.front();
    q.pop();
    --r;
    vis[u] = 1;
    if (d[u] == k-1 && k*(k-1ll)/2 <= m) {
      clique = vector<int>(1, u);
      for (const int &i : e[u]) if (!vis[i]) clique.emplace_back(i);
      int flag = 1;
      for (int &i : clique) {
        for (int &j : clique) {
          if (i == j) break;
          auto it=lower_bound(e[i].begin(), e[i].end(), j);
          if (*it!=j||it==e[i].end()) flag=0;
        }
      }
      if (flag) {
        cout << 2 << endl;
        for (int &i : clique) cout << i << " ";
        cout << endl;
        return;
      }
    }
    for (const int &v : e[u]) {
      if (d[v]-- == k) q.push(v);
    }
  }
  if (r) {
    cout << 1 << " " << r << endl;
    for (int i = 1; i <= n; ++i) if (!vis[i]) {
      cout << i << " ";
    }
    cout << endl;
  } else {
    cout << -1 << endl;
  }
}
 
signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i = 1; i <= n; ++i) {
      e[i].clear();
      d[i] = vis[i] = 0;
    }
  }
  return 0;
}