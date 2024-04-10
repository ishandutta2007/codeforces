/*
start thinking:
BULB:
result of thinking:

:  {1, 2, ..., 16}, min.
 (15/16)^(m^2), 100 > 99.9999%.

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 100005
int n, m, a[maxn][6], w[maxn], V, id[3915], minw[3915], chi[3915][6];
vector<int> pos[maxn * 5];

int ban[maxn];
int minId() {
  int x = 0;
  for (int i = 1; i <= n; i++) {
    if (!ban[i] && w[i] < w[x])
      x = i;
  }
  return x;
}
void build(int u, int dep) {
  id[u] = minId();
  minw[u] = w[id[u]];
  if (dep == m || !id[u])
    return;
  for (int i = 1; i <= m; i++) {
    int x = a[id[u]][i];
    for (auto j : pos[x])
      ban[j]++;
    chi[u][i] = ++V;
    build(V, dep + 1);
    for (auto j : pos[x])
      ban[j]--;
  }
}

int query(const vector<int> &b) {
  int u = 1;
  while (true) {
    if (minw[u] == INT_MAX)
      return INT_MAX;
    bool ok = false;
    for (int i = 1; i <= m; i++) {
      for (int j = 0; j < m; j++) {
        if (b[j] == a[id[u]][i]) {
          ok = true;
          u = chi[u][i];
          break;
        }
      }
      if (ok)
        break;
    }
    if (!ok)
      return minw[u];
  }
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d", &n, &m);
  vector<int> as;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      as.push_back(a[i][j]);
    }
    scanf("%d", w + i);
  }
  sort(as.begin(), as.end());
  as.erase(unique(as.begin(), as.end()), as.end());
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i][j] = lower_bound(as.begin(), as.end(), a[i][j]) - as.begin() + 1;
      pos[a[i][j]].push_back(i);
    }
  }
  w[0] = INT_MAX;
  build(++V, 0);
  int ans = INT_MAX;
  for (int i = 1; i <= n; i++) {
    vector<int> foo;
    for (int j = 1; j <= m; j++)
      foo.push_back(a[i][j]);
    int bar = query(foo);
    if (bar != INT_MAX)
      chmin(ans, bar + w[i]);
  }
  printf("%d\n", ans == INT_MAX ? -1 : ans);
  return 0;
}