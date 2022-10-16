// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
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

const int N = 200005;

vector<int> adj[N];
int n, group, dot, leaf;

bool dfs(int u, int fa) { //  u 
  bool ok = 0;
  int son = 0;
  for (auto v: adj[u]) {
    if (v == fa) continue;
    bool t = dfs(v, u);
    if (!t) ok = 1, son++;
  }
  if (!son) leaf++;
  if (ok) group++;
  return ok;
}
void solve() {
  n = read(), group = 0, dot = 0, leaf = 0;
  rep(i, 1, n) adj[i].clear();
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  for (auto son: adj[1]) {
    dot += !dfs(son, 1);
  }
//  printf("group = %d, dot = %d, leaf = %d\n", group, dot, leaf);
  if (dot) printf("%d\n", leaf - group);
  else printf("%d\n", leaf - max(0, group - 1));
}

int main() {
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}