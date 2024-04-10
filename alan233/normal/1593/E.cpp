// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 400005;

vector<int> adj[N];
int deg[N], n, k;

void solve() {
  n = read(), k = read();
  rep(i, 1, n) adj[i].clear(), deg[i] = 0;
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
    deg[u]++, deg[v]++;
  }
  vector<int> go;
  rep(i, 1, n) if (deg[i] <= 1) go.pb(i);
  int ans = 0;
  while (k-- && SZ(go)) {
    vector<int> nxt;
    for (auto u: go) {
      ans++;
      for (auto v: adj[u]) if (--deg[v] == 1) nxt.pb(v);
    }
    go = nxt;
  }
  print(n - ans, '\n');
}

int main() {
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}