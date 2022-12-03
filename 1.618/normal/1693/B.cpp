/*
start thinking:
BULB:
result of thinking:

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
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 200005
int n, l[maxn], r[maxn], a[maxn], ans;
vector<int> chi[maxn];

void dfs(int u) {
  a[u] = 0;
  for (auto v : chi[u]) {
    dfs(v);
    a[u] += a[v];
    chmin(a[u], r[u]);
  }
  if (a[u] < l[u]) {
    a[u] = r[u];
    ans++;
  }
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    chi[i].clear();
  for (int i = 2; i <= n; i++) {
    int p;
    scanf("%d", &p);
    chi[p].push_back(i);
  }
  for (int i = 1; i <= n; i++)
    scanf("%d%d", l + i, r + i);
  ans = 0;
  dfs(1);
  printf("%d\n", ans);
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}