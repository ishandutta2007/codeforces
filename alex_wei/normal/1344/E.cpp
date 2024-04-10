#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
inline int read() {
  int x = 0;
  char s = getchar();
  while(!isdigit(s)) s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return x;
}
inline void print(int x) {
  if(x < 0) return putchar('-'), print(-x);
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
constexpr int N = 1e5 + 5;
constexpr int K = N << 5;
constexpr int inf = 0x3f3f3f3f;
ll dep[N];
int n, m, node, lst[N], R[N];
vector<int> buc[N];
vector<pii> e[N];
vector<pll> I;
int ls[K], rs[K], laz[K];
struct dat {
  int fst, nxt, col;
  dat operator + (const dat &x) const {
    if(!col) return x;
    if(!x.col) return *this;
    if(nxt != inf) return *this;
    return (dat) {fst, col == x.col ? x.nxt : x.fst, col};
  }
} val[K];
void tag(int x, int v) {
  if(!x) return;
  laz[x] = v;
  val[x] = {val[x].fst, inf, v};
}
void down(int x) {
  if(laz[x]) {
    tag(ls[x], laz[x]);
    tag(rs[x], laz[x]);
    laz[x] = 0;
  }
}
void modify(int l, int r, int p, int &x, int v) {
  if(!x) x = ++node;
  if(l == r) return val[x] = (dat) {p, inf, v}, void();
  down(x);
  int m = l + r >> 1;
  if(p <= m) modify(l, m, p, ls[x], v);
  else modify(m + 1, r, p, rs[x], v);
  val[x] = val[ls[x]] + val[rs[x]];
}
dat query(int l, int r, int ql, int qr, int x) {
  if(ql <= l && r <= qr) return val[x];
  int m = l + r >> 1;
  dat ans = {0, 0, 0};
  down(x);
  if(ql <= m) ans = query(l, m, ql, qr, ls[x]);
  if(m < qr) ans = ans + query(m + 1, r, ql, qr, rs[x]);
  return ans;
}
int pre(int l, int r, int p, int x) {
  if(!x) return -1;
  if(l == r) return l;
  int m = l + r >> 1;
  down(x);
  if(m < p) {
    int res = pre(m + 1, r, p, rs[x]);
    if(res != -1) return res;
  }
  return pre(l, m, p, ls[x]);
}
int merge(int x, int y) {
  if(!x || !y) return x | y;
  down(x), down(y);
  ls[x] = merge(ls[x], ls[y]);
  rs[x] = merge(rs[x], rs[y]);
  return val[x] = val[ls[x]] + val[rs[x]], x;
}
void dfs(int id) {
  for(pii _ : e[id]) {
    int it = _.first;
    dep[it] = dep[id] + _.second, dfs(it);
    for(int t : buc[it]) modify(1, inf, t, R[it], it);
    tag(R[it], it), R[id] = merge(R[id], R[it]);
  }
  if(!R[id]) return;
  auto add = [&](ll l, ll r) {
    I.push_back({l + dep[id], r + dep[id]});
  };
  int curpos = val[R[id]].fst;
  if(lst[id] != val[R[id]].col) add(1 - dep[id], curpos); // add -dep[id]
  while(1) {
    dat res = query(1, inf, curpos, inf, R[id]);
    if(res.nxt == inf) break;
    int prev = pre(1, inf, res.nxt - 1, R[id]);
    add(prev + 1, curpos = res.nxt);
  }
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].push_back({v, w});
    lst[u] = v;
  }
  for(int i = 1; i <= m; i++) {
    int dest, t;
    cin >> dest >> t;
    buc[dest].push_back(t);
  }
  dfs(1);
  sort(I.begin(), I.end());
  I.push_back({LLONG_MAX, LLONG_MAX});
  priority_queue<ll, vector<ll>, greater<ll>> q;
  ll explode = -1;
  for(int i = 0; i < I.size() && explode == -1; i++) {
    ll lst = i ? I[i - 1].first : 1, cur = I[i].first;
    while(lst < cur && !q.empty()) {
      ll t = q.top();
      if(t < lst) {
        explode = t;
        break;
      }
      q.pop(), lst++;
    }
    q.push(I[i].second);
  }
  cout << explode << " ";
  if(explode == -1) explode = LLONG_MAX;
  int cnt = 0;
  for(pll it : I) cnt += it.second < explode;
  cout << cnt << "\n";
  return 0;
}
/*
2022/9/6
author: Alex_Wei
start coding at 11:24
finish debugging at 13:29
*/