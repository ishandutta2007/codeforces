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

const int N = 500005;
const int NODE = 50000 * 20;

struct node { int l, r, id; };
vector<node> ask[3 * N];
char a[N], b[N];
int go[N];
pii ans[N];
int n, m, q;

int rt[3 * N], ls[NODE], rs[NODE], tot;
int maxx[NODE], id[NODE];
void pushup(int u) {
  if (maxx[ls[u]] >= maxx[rs[u]]) maxx[u] = maxx[ls[u]], id[u] = id[ls[u]];
  else maxx[u] = maxx[rs[u]], id[u] = id[rs[u]];
}
void ins(int &u, int l, int r, int pos) {
  if (!u) u = ++tot;
  if (l == r) { maxx[u]++, id[u] = l; return ; }
  int mid = l + r >> 1;
  if (pos <= mid) ins(ls[u], l, mid, pos);
  else ins(rs[u], mid + 1, r, pos);
  pushup(u);
}
void merge(int &u, int v, int l, int r) {
  if (!u || !v) { u += v; return ; }
  if (l == r) {
    maxx[u] += maxx[v], id[u] = l;
    return ;
  }
  int mid = l + r >> 1;
  merge(ls[u], ls[v], l, mid);
  merge(rs[u], rs[v], mid + 1, r);
  pushup(u);
}
int _max, _id;
void query(int u, int l, int r, int ql, int qr) {
  if (!u) return ;
  if (ql <= l && r <= qr) {
    if (maxx[u] > _max) _max = maxx[u], _id = id[u];
    return ;
  }
  int mid = l + r >> 1;
  if (ql <= mid) query(ls[u], l, mid, ql, qr);
  if (qr > mid) query(rs[u], mid + 1, r, ql, qr);
}

struct SAM {
  int ch[3 * N][27], fail[3 * N], len[3 * N], sz[3 * N];
  vector<int> adds[3 * N];
  int tot, lst;
  SAM() {
    lst = tot = 1;
  }
  void extend(int x, int who) {
    int u = lst; lst = ++tot;
    len[lst] = len[u] + 1; if (who) adds[lst].pb(who);
    for (; !ch[u][x]; u = fail[u]) ch[u][x] = lst;
    if (!u) {
      fail[lst] = 1;
      return ;
    }
    int v = ch[u][x];
    if (len[v] == len[u] + 1) {
      fail[lst] = v;
      return ;
    }
    int w = ++tot;
    len[w] = len[u] + 1, fail[w] = fail[v], mcpy(ch[w], ch[v]);
    fail[v] = fail[lst] = w;
    for (; ch[u][x] == v; u = fail[u]) ch[u][x] = w;
  }
  vector<int> adj[3 * N];
  int f[3 * N][18];
  void dfs1(int u) {
    rep(j, 1, 17) f[u][j] = f[f[u][j - 1]][j - 1];
    for (auto v: adj[u]) {
      f[v][0] = u;
      dfs1(v);
    }
  }
  void build() {
    rep(i, 2, tot) adj[fail[i]].pb(i);
    dfs1(1);
  }
  void dfs2(int u) {
    for (auto it: adds[u]) ins(rt[u], 1, m, it);
    for (auto v: adj[u]) {
      dfs2(v);
      merge(rt[u], rt[v], 1, m);
    }
    for (auto it: ask[u]) {
      _max = 0, _id = it.l;
      query(rt[u], 1, m, it.l, it.r);
      ans[it.id] = make_pair(_id, _max);
    }
  }
} sam;

int main() {
#ifdef xay
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  scanf("%s", a + 1), n = strlen(a + 1);
  rep(j, 1, n) sam.extend(a[j] - 'a', 0);
  sam.extend(26, 0);
  scanf("%d", &m);
  rep(i, 1, m) {
    scanf("%s", b + 1);
    int len = strlen(b + 1);
    rep(j, 1, len) sam.extend(b[j] - 'a', i)/*, printf("now = %d\n", sam.lst)*/;
    if (i != m) sam.extend(26, 0);
//    if (i % 100 == 0) D("i = %d, now tot = %d\n", i, sam.tot);
  }
  sam.build();
//  D("ok!\n");
  int now = 1;
  rep(i, 1, n) {
    now = sam.ch[now][a[i] - 'a'];
    if (!now) break;
    go[i] = now;
//    printf("go[%d] = %d\n", i, go[i]);
  }
//  D("sam tot = %d\n", sam.tot);
  scanf("%d", &q);
  rep(i, 1, q) {
    int x = read(), y = read(), l = read(), r = read();
    if (!go[r] || sam.len[go[r]] < r - l + 1) {
      ans[i] = {x, 0};
      continue;
    }
    int u = go[r];
//    int _ = u;
//    while (_) {
//      printf("u = %d, len = %d\n", _, sam.len[_]);
//      _ = sam.fail[_];
//    }
    per(j, 17, 0) if (sam.len[sam.fail[sam.f[u][j]]] >= r - l + 1) u = sam.f[u][j];
    if (sam.len[sam.fail[u]] >= r - l + 1) u = sam.fail[u];
//    printf("u = %d\n", u);
    ask[u].pb({x, y, i});
  }
  sam.dfs2(1);
  rep(i, 1, q) {
    print(ans[i].fir, ' '), print(ans[i].sec, '\n');
  }
  return 0;
}