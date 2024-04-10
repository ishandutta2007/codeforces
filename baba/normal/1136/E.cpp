// LastDay@TB
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long int LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(), a.end()
#define SET(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define si(n) scanf("%d", &n)
#define dout(n) printf("%d\n", n)
#define sll(n) scanf("%lld", &n)
#define lldout(n) printf("%lld\n", n)
#define fast_io                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

// FILE *fin = freopen("in","r",stdin);
// FILE *fout = freopen("out","w",stdout);
const int N = 1e5 + 10;
const LL INF = 1e18;
LL K[N];
LL ST[4 * N], MAX[4 * N], lazy[4 * N], A[N];
#define lc (x << 1)
#define rc (x << 1) | 1
void push(int x, int l, int r) {
  if (lazy[x] == INF) return;
  ST[x] = lazy[x] * (r - l);  // Operation of lazy
  MAX[x] = lazy[x];
  if (l == r - 1) {
  lazy[x] = INF;
  return;
  }
  lazy[lc] = lazy[x];
  lazy[rc] = lazy[x];
  lazy[x] = INF;  // Propagate Lazy
}
void up(int x) {  // Operation of Segtree
  ST[x] = ST[lc] + ST[rc];
  MAX[x] = max(MAX[lc], MAX[rc]);
}
void build(int l = 0, int r = N, int x = 1) {
  lazy[x] = INF;  // clear lazy
  if (l == r - 1) return void((ST[x] = A[l], MAX[x] = A[l]));
  int m = (l + r) / 2;
  build(l, m, lc);
  build(m, r, rc);
  up(x);
}
void update(int L, int R, LL val, int l = 0, int r = N, int x = 1) {
  push(x, l, r);
  int m = (l + r) / 2;
  if (l >= R || r <= L) return;
  if (l >= L && r <= R) {
    lazy[x] = val;  // operation of lazy update
    return push(x, l, r);
  }
  update(L, R, val, l, m, lc);
  update(L, R, val, m, r, rc);
  up(x);
}
LL query_sum(int L, int R, int l = 0, int r = N, int x = 1) {
  push(x, l, r);
  int m = (l + r) / 2;
  if (l >= R || r <= L) return 0;  // nothing here
  if (l >= L && r <= R) return ST[x];
  LL la = query_sum(L, R, l, m, lc);
  LL ra = query_sum(L, R, m, r, rc);
  return la + ra;  // operation of segtree
}
LL query_max(int L, int R, int l = 0, int r = N, int x = 1) {
  push(x, l, r);
  int m = (l + r) / 2;
  if (l >= R || r <= L) return -INF;  // nothing here
  if (l >= L && r <= R) return MAX[x];
  LL la = query_max(L, R, l, m, lc);
  LL ra = query_max(L, R, m, r, rc);
  return max(la, ra);  // operation of segtree
}
int main() {
  int n;
  si(n);
  REP(i, n) { sll(A[i]); }
  REP(i, n - 1) {
    sll(K[i]);
  }
  REP(i, n - 2) { K[i + 1] += K[i]; }
  REP(i, n -1 ){
    A[i + 1] -= K[i];
  }
  REP(i, n - 2) { K[i + 1] += K[i]; }
  build(0, n);
  int q;
  si(q);
  while (q--) {
    char s[10];
    scanf("%s", s);
    if (s[0] == '+') {
      int pos, val;
      si(pos);
      si(val);
      pos--;
      LL curr_val = query_sum(pos, pos + 1, 0, n);
      curr_val += val;
      int low = pos + 1, high = n, ans = -1;
      while (low <= high) {
        int mid = (low + high) >> 1;
        auto val = query_max(pos, mid, 0, n);
        if(val <= curr_val){
          ans = mid;
          low = mid + 1;
        }
        else {
          high = mid - 1;
        }
      }
      assert(ans != -1);
      update(pos, ans, curr_val, 0, n);
    }
    else {
      int l, r;
      si(l);si(r);
      l--;r--;
      LL ans = query_sum(l, r + 1, 0, n);
      l--;
      r--;
      ans += (r >= 0 ? K[r] : 0);
      ans -= (l > 0 ? K[l - 1] : 0);
      lldout(ans);
    }
  }
  return 0;
}