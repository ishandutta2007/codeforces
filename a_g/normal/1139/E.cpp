#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
vector<int> G[N];
int match[N];
bool used[N];

bool dfs(int v) {
  if (used[v]) return 0;
  used[v] = 1;
  for (int u: G[v]) {
    if (match[u] == -1 || dfs(match[u])) {
      match[u] = v;
      return 1;
    }
  }
  return 0;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> p(n), c(n);
  for (int& x: p) cin >> x;
  for (int& x: c) cin >> x, x--;

  int q;
  cin >> q;
  vector<int> a(q), leave(n), ans(q);
  for (int i = 0; i < q; i++) {
    cin >> a[i];
    a[i]--;
    leave[a[i]] = i+1;
  }
  for (int i = 0; i < n; i++) {
    if (!leave[i]) {
      G[p[i]].emplace_back(c[i]);
    }
  }

  int mex = 0;
  fill(match, match+N, -1);
  while (dfs(mex)) {
    mex++;
    fill(used, used+N, 0);
  }
  fill(used, used+N, 0);
  for (int i = q-1; i >= 0; i--) {
    ans[i] = mex;
    G[p[a[i]]].emplace_back(c[a[i]]);
    while (dfs(mex)) {
      mex++;
      fill(used, used+N, 0);
    }
    fill(used, used+N, 0);
  }
  for (int x: ans) cout << x << '\n';
}