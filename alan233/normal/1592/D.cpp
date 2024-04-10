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

const int N = 1005;

int ask(vector<int> zyk) {
  printf("? %d", SZ(zyk));
  for(auto v: zyk) printf(" %d", v);
  puts(""), fflush(stdout);
  int x = read(); return x;
}

vector<int> adj[N];
int n;

int dfn[N], did[N], dtot, sz[N], dad[N];
void dfs1(int u, int fa) {
  dad[u] = fa;
  dfn[u] = ++dtot, did[dtot] = u, sz[u] = 1;
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs1(v, u);
    sz[u] += sz[v];
  }
}


int main() {
  n = read();
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  vector<int> zyk; rep(i, 1, n) zyk.pb(i);
  int maxx = ask(zyk);
  dfs1(1, 0);
  int l = 2, r = n;
  while (l < r) {
    int mid = l + r >> 1;
    zyk.clear();
    rep(i, 1, mid) zyk.pb(did[i]);
    if (ask(zyk) == maxx) r = mid;
    else l = mid + 1;
  }
  printf("! %d %d\n", dad[did[l]], did[l]), fflush(stdout);
  return 0;
}