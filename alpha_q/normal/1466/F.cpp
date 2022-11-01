#include <bits/stdc++.h>

using namespace std;

const int N = 500010;
const int MOD = 1e9 + 7;

int n, m, p[N];

inline int find (int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}

bool unite (int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return 0;
  if (rand() & 1) swap(x, y);
  return p[x] = y, 1;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i <= m; ++i) p[i] = i;
  int tot = 1;
  vector <int> ans;
  for (int i = 1; i <= n; ++i) {
    int sz, x, y; 
    scanf("%d", &sz);
    if (sz == 1) {
      scanf("%d", &x);
      if (unite(0, x)) tot = 2 * tot % MOD, ans.emplace_back(i);
    } else {
      scanf("%d %d", &x, &y);
      if (unite(x, y)) tot = 2 * tot % MOD, ans.emplace_back(i);
    }
  }
  cout << tot << " " << ans.size() << '\n';
  for (int x : ans) printf("%d ", x); puts("");
  return 0;
}