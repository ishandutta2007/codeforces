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

#define maxn 1005
int n, m, a[maxn], b[maxn];
vector<int> adj[maxn];
bool cap[maxn];
int pre[maxn];

bool dfs(int u, int f, ll x, vector<int> &terri, ll &val) {
  pre[u] = f;
  for (auto v : adj[u]) {
    if (v == f || a[v] >= x)
      continue;
    if (cap[v] || pre[v]) {
      vector<int> foo;
      for (int i = u; !cap[i]; i = pre[i])
        foo.push_back(i);
      for (int i = v; !cap[i]; i = pre[i])
        foo.push_back(i);
      sort(foo.begin(), foo.end());
      foo.erase(unique(foo.begin(), foo.end()), foo.end());
      for (auto i : foo) {
        terri.push_back(i);
        cap[i] = true;
        val += b[i];
      }
      return true;
    } else {
      if (dfs(v, u, x + b[v], terri, val))
        return true;
    }
  }
  return false;
}

bool expand(vector<int> &terri, ll &val) {
  memset(pre, 0, sizeof(pre));
  for (auto u : terri) {
    for (auto v : adj[u]) {
      if (!cap[v] && a[v] < val) {
        if (dfs(v, u, val + b[v], terri, val))
          return true;
      }
    }
  }
  return false;
}

bool check(ll x) {
  vector<int> terri;
  terri.push_back(1);
  memset(cap, 0, sizeof(cap));
  cap[1] = true;
  while ((int)terri.size() < n) {
    if (!expand(terri, x))
      return false;
  }
  return true;
}

void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 2; i <= n; i++)
    scanf("%d", a + i);
  for (int i = 2; i <= n; i++)
    scanf("%d", b + i);
  for (int i = 1; i <= n; i++)
    adj[i].clear();
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int lb = 1, rb = 1e9 + 1;
  while (lb < rb) {
    int mid = (lb + rb) >> 1;
    if (check(mid))
      rb = mid;
    else
      lb = mid + 1;
  }
  printf("%d\n", lb);
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