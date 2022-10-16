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
ll read() {
  ll x = 0, f = 0; char ch = getchar();
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

const int N = 55;
const int M = 50005;
const int NODE = 2 * N * M;

struct Data {
  ll l, r; int t;
  bool operator < (const Data &rhs) const {
    return r < rhs.r;
  }
} qj[M];
ll askl[M], askr[M];
int opt[M];
int n, m, cnt;

vector<int> item[M]; // !!!

vector<vector<int>> adj; //  
vector<int> tim;
int tot; // !!!
int newnode(int t) {
  adj.push_back({});
  tim.push_back({});
  tim[++tot] = t, item[t].pb(tot);
  return tot;
}
vector<Data> solve(ll l, ll r, int ql, int qr) {
  if (ql > qr) return {{l, r, newnode(m + 1)}};
  if (ql == qr && qj[ql].l <= l && r <= qj[ql].r) return {{l, r, newnode(qj[ql].t)}};
  ll mid = l + r >> 1;
  int go = ql - 1;
  while (go + 1 <= qr && qj[go + 1].l <= mid) ++go;
  vector<Data> L = solve(l, mid, ql, go);
  go = qr + 1;
  while (go - 1 >= ql && qj[go - 1].r > mid) --go;
  vector<Data> R = solve(mid + 1, r, go, qr);
  
  ll h = mid - l + 1;
  int x = 0, y = 0;
  while (x < SZ(L) && y < SZ(R)) {
    int u = L[x].t, v = R[y].t;
    if (tim[u] < tim[v]) adj[u].pb(v);
    else adj[v].pb(u);
    if (L[x].r == (R[y].r ^ h)) x++, y++;
    else if (L[x].r < (R[y].r ^ h)) x++;
    else y++;
  }
  for (auto v: R) L.pb(v);
  return L;
}

vector<Data> all;
int calc_node(ll x) {
  return lower_bound(all.begin(), all.end(), Data{x, x, 0}) -> t; 
}
int f[NODE];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void merge(int x, int y) {
  f[find(x)] = find(y);
}

int main() {
  adj.push_back({}), tim.push_back({});
  n = read(), m = read();
  rep(i, 1, m) {
    char _[5]; scanf("%s", _);
    opt[i] = _[0] == 'a';
    if (!opt[i]) qj[++cnt] = {read(), read(), i};
    else askl[i] = read(), askr[i] = read();
  }
  sort(qj + 1, qj + cnt + 1);
  all = solve(0, (1ll << n) - 1, 1, cnt);
//  for (auto v: all) printf("(%lld, %lld, %d)\n", v.l, v.r, v.t);
  iota(f + 1, f + tot + 1, 1);
  stack<int> res;
  per(i, m + 1, 1) {
    if (i == m + 1 || SZ(item[i])) {
      for (auto u: item[i]) {
        for (auto v: adj[u])
          merge(u, v);
      }
    } else {
      int u = calc_node(askl[i]), v = calc_node(askr[i]);
      res.push(find(u) == find(v));
    }
  }
  while (!res.empty()) {
    print(res.top(), '\n'), res.pop();
  }
  return 0;
}