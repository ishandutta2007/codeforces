#include <bits/stdc++.h>

using namespace std;

const int N = 7;
const int M = 123;

vector <int> col[M], opt[69];
int t, n, m, a[N][M], id[M], ans, lim;

void backtrack (int at = 1) {
  if (at > lim) {
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      int mx = 0;
      for (int j = 1; j <= lim; ++j) mx = max(mx, opt[j][i]);
      cur += mx;
    }
    ans = max(ans, cur);
    return;
  }
  for (int i = 0; i < n; ++i) {
    int x = opt[at].back(); 
    opt[at].pop_back();
    opt[at].insert(opt[at].begin(), x);
    backtrack(at + 1);
  }
}

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        scanf("%d", a[i] + j);
      }
    }
    for (int i = 1; i <= m; ++i) {
      id[i] = i, col[i].clear();
      for (int j = 1; j <= n; ++j) col[i].emplace_back(a[j][i]);
      sort(col[i].begin(), col[i].end());
      reverse(col[i].begin(), col[i].end());
    }
    sort(id + 1, id + m + 1, [] (int i, int j) {return col[i] > col[j];});
    lim = min(n, m);
    for (int i = 1; i <= lim; ++i) {
      int j = id[i]; opt[i].clear();
      for (int k = 1; k <= n; ++k) opt[i].emplace_back(a[k][j]);
    }
    ans = 0; backtrack();
    printf("%d\n", ans);
  }
  return 0;
}