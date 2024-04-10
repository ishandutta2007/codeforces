// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
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
const int M = 80 * N;
const int inf = 1e9;

int lst[N], T, n;
pii seg[N];

struct node {
  int ls, rs;
  ll tagk, tagb;
  ll sumk, sumb; 
} tr[M];
int tot;

void ins(int &u, int v, int l, int r, int ql, int qr, ll k, ll b) {
  int cross = min(qr, r) - max(ql, l) + 1;
  u = ++tot, tr[u] = tr[v], tr[u].sumk += 1ll * cross * k, tr[u].sumb += 1ll * cross * b;
  if (ql <= l && r <= qr) {
    tr[u].tagk += k;
    tr[u].tagb += b;
    return ;
  }
  int mid = l + r >> 1;
  if (ql <= mid) ins(tr[u].ls, tr[v].ls, l, mid, ql, qr, k, b);
  if (qr > mid) ins(tr[u].rs, tr[v].rs, mid + 1, r, ql, qr, k, b);
}
ll qry(int u, int l, int r, int ql, int qr) {
  if (!u) return 0ll;
  if (ql <= l && r <= qr) {
    return 1ll * T * tr[u].sumk + tr[u].sumb;
  }
  int mid = l + r >> 1;
  int cross = min(qr, r) - max(ql, l) + 1;
  ll ans = 1ll * T * cross * tr[u].tagk + 1ll * cross * tr[u].tagb;
  if (ql <= mid) ans += qry(tr[u].ls, l, mid, ql, qr);
  if (qr > mid) ans += qry(tr[u].rs, mid + 1, r, ql, qr);
  return ans;
}

set<pii> rts[N]; int rt[N << 2], rtot;
void add(int x, int l, int r) { // time T, add [l, r], mex = x
  // printf("add x = %d, l = %d, r = %d\n", x, l, r);
  ++rtot;
  if (rts[x].empty()) ins(rt[rtot], 0, 1, n, l, r, 1, - (T - 1));
  else ins(rt[rtot], rt[(--rts[x].end())->sec], 1, n, l, r, 1, - (T - 1));
  rts[x].insert({T, rtot});
}
void del(int x, int l, int r) { // time T, del [l, r], mex = x
  // printf("del x = %d, l = %d, r = %d\n", x, l, r);
  ++rtot;
  ins(rt[rtot], rt[(--rts[x].end())->sec], 1, n, l, r, -1, (T - 1));
  rts[x].insert({T, rtot});
}
ll query(int x, int l, int r) {
  T = r;
  // for (auto v: rts[x]) printf("(%d, %d)\n", v.fir, v.sec);
  auto it = rts[x].upper_bound(make_pair(r, inf));
  if (it == rts[x].begin()) return 0ll;
  it--;
  // printf("(%d,%d), T=%d\n",it->fir,it->sec,T);
  return qry(rt[it->sec], 1, n, l, r);
}

void push(int x) { // append x
  int l = seg[x].fir, r = seg[x].sec;
  if (l > r) return ;
  del(x, l, r);
  seg[x] = {0, -1};
  while (1) {
    ++x;
    int p = lst[x];
    if (p < l) {
      add(x, l, r);
      if (seg[x].sec == -1) seg[x] = make_pair(l, r);
      else seg[x].sec = r;
      break;
    } else if (p < r) {
      add(x, p + 1, r);
      if (seg[x].sec == -1) seg[x] = make_pair(p + 1, r);
      else seg[x].sec = r;
      r = p;
    }
  }
}

int main() {
  n = read();
  rep(i, 0, n + 1) seg[i] = {0, -1};
  ll lastans = 0;
  rep(i, 1, n) {
    int a = read(), l = read(), r = read(), k = read();
    a = (a + lastans) % (n + 1), l = (l + lastans) % i + 1, r = (r + lastans) % i + 1, k = (k + lastans) % (n + 1);
    if (l > r) swap(l, r);
    // printf("a = %d, l = %d, r = %d, k = %d\n", a, l, r, k);
    T = i, lst[a] = i;
    push(a);
    // cerr << "finished!\n";
    if (!a) {
      if (seg[1].sec == -1) seg[1] = make_pair(i, i);
      else seg[1].sec = i;
      add(1, i, i);
    } else {
      if (seg[0].sec == -1) seg[0] = make_pair(i, i);
      else seg[0].sec = i;
      add(0, i, i);
    }
    /* printf("after time = %d\n", i);
    rep(i, 0, n) {
      if (seg[i].fir <= seg[i].sec)
        printf("num %d: [%d, %d]\n", i, seg[i].fir, seg[i].sec);
    } */
    print(lastans = query(k, l, r), '\n');
  }
  return 0;
}