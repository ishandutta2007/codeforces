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

//#define DEBUG

const int N = 100005;

vector<int> adj[N];
ll k, mn, mx;
int n;

int sz[N], maxp[N], rt;
void dfs1(int u, int fa) {
  sz[u] = 1, maxp[u] = 0;
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs1(v, u);
    sz[u] += sz[v];
    ckmax(maxp[u], sz[v]);
  }
  ckmax(maxp[u], n - sz[u]);
  if (maxp[rt] > maxp[u]) rt = u;
  mn += sz[u] & 1;
  mx += min(sz[u], n - sz[u]);
}
set<pii, greater<pii>> s[N], tree;
int dep[N], son[N], dad[N], be[N];
void dfs2(int u, int fa, int anc) {
  dep[u] = dep[fa] + 1, dad[u] = fa, be[u] = anc, sz[u] = 1;
  for (auto v: adj[u]) {
    if (v == fa) continue;
    son[u]++;
    dfs2(v, u, anc);
    sz[u] += sz[v];
  }
  if (son[u]) s[anc].insert({dep[u], u});
}
bool used[N];
void del(int u) {
  used[u] = 1;
  if (--son[dad[u]] == 0) s[be[u]].erase({dep[dad[u]], dad[u]});
}
void match(int u) {
  vector<int> tmp;
  for (auto v: adj[u]) {
    if (v == dad[u]) continue;
    if (!used[v]) tmp.pb(v);
  }
  if (!used[u]) tmp.pb(u);
  printf("%d %d\n", tmp[0], tmp[1]);
  del(tmp[0]), del(tmp[1]);
}

vector<int> dfn;
void dfs3(int u, int fa) {
  if (!used[u]) dfn.pb(u);
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs3(v, u);
  }
}

int main() {
  scanf("%d%lld", &n, &k);
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  maxp[rt = 0] = n, dfs1(1, 0);
#ifdef DEBUG
  printf("rt = %d\n", rt);
  printf("mn = %lld, mx = %lld\n", mn, mx);
#endif
  if (k < mn || k > mx || ((mx - k) & 1)) {
    puts("NO");
    return 0;
  }
  puts("YES");
  dep[rt] = 0;
  for (auto u: adj[rt]) {
    dfs2(u, rt, u);
    if (sz[u] > 1) tree.insert({sz[u], u});
  }
  ll need = mx - k;
  while (need) {
    int u = tree.begin()->sec; tree.erase(tree.begin());
    int y = s[u].begin()->sec;
    if (2 * dep[y] <= need) {
      match(y);
      sz[u] -= 2;
      if (sz[u] > 1) tree.insert({sz[u], u});
      need -= 2 * dep[y];
    } else {
      y = s[u].lower_bound(make_pair(need / 2, n))->sec;
      assert(dep[y] == need / 2);
      match(y);
      break;
    }
  }
  dfs3(rt, 0);
  for (int i = 0; i < SZ(dfn) / 2; i++)
    printf("%d %d\n", dfn[i], dfn[i + SZ(dfn) / 2]);
  return 0; 
}