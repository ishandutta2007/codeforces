#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ldb long double

#define endl '\n'

vector<vector<int>> g;
vector<vector<pair<int, int>>> qq;
vector<int> ans;

vector<int> add;

int cur = 0;

void dfs(int v, int d = 0, int p = -1) {
  for (auto &el : qq[v]) {
    add[d] += el.second;
    if (d + el.first + 1 < (int) add.size())
      add[d + el.first + 1] -= el.second;
  }
  cur += add[d];
  ans[v] = cur;
  for (int u : g[v]) {
    if (u != p) {
      dfs(u, d + 1, v); 
    }
  }
  cur -= add[d];
  for (auto &el : qq[v]) {
    add[d] -= el.second;
    if (d + el.first + 1 < (int) add.size())
      add[d + el.first + 1] += el.second;
  }
}

void solve() {
  int n;
  cin >> n;
  g.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  qq.resize(n);
  int m;
  cin >> m;
  while (m--) {
    int v, d, x;
    cin >> v >> d >> x;
    v--;
    qq[v].emplace_back(d, x);
  }
  ans.resize(n);
  add.resize(n + 1);
  dfs(0);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--)
    solve();
}