#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

vector<vector<int>> g;
int st;
vector<pair<int, int>> ans;

void dfs(int v, int p = -1) {
  if (g[v].size() == 1 && p != -1) {
    ans.push_back({st + 1, v + 1});
  }
  for (int u : g[v]) {
    if (u != p) 
      dfs(u, v);
  }
}

void solve() {
  int n;
  cin >> n;
  g.resize(n);
  vector<int> cnt(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    cnt[a]++;
    cnt[b]++;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int cnt1 = 0;
  st = 0;
  for (int i = 0; i < n; i++) {
    if (cnt[i] > 2) {
      cnt1++;
      st = i;
    }
  }
  if (cnt1 > 1) {
    cout << "No" << endl;
    return;
  }
  cout << "Yes" << endl;
  dfs(st, -1);
  cout << ans.size() << endl;
  for (auto &el : ans) {
    cout << el.first << " " << el.second << endl;
  }
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}