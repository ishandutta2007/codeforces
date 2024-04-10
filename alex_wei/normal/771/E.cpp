#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
namespace IO {
  char buf[1 << 21], *p1 = buf, *p2 = buf, Obuf[1 << 24], *O = Obuf;
  #define gc (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
  #define pc(x) (*O++ = x)
  inline int read() {
    int x = 0, sgn = 0;
    char s = gc;
    while(!isdigit(s)) sgn |= s == '-', s = gc;
    while(isdigit(s)) x = x * 10 + s - '0', s = gc;
    return sgn ? -x : x;
  }
  template <class T>
    inline void rprint(T x) {if(x >= 10) rprint(x / 10); pc(x % 10 + '0');}
  template <class T>
    inline void print(T x) {if(x < 0) pc('-'), x = -x; rprint(x);}
}
using namespace IO;
using ll = long long;
using pii = pair<int, int>;
bool Mbe;
constexpr int N = 3e5 + 5;
int type, n, m, ans[N], f[N];
ll sum, X[N], Y[N];
vector<pii> u[N], d[N];
map<ll, int> up, dn, to;
struct solver {
  ll sum;
  int limit, fa[N], bel[N], val[N], laz[N];
  vector<int> S[N];
  int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
  void init() {
    for(int i = 0; i <= n; i++) fa[i] = i;
    S[0].push_back(0);
  }
  void merge(int x, int y) {
    if(S[x].empty() && S[y].empty()) return;
    if(S[x].size() < S[y].size()) swap(S[x], S[y]), swap(laz[x], laz[y]);
    bel[S[x].front()] = x;
    if(S[y].empty()) return;
    fa[S[y].front()] = S[x].front();
    for(int it : S[y]) val[it] += laz[y] - laz[x], S[x].push_back(it);
    vector<int> ().swap(S[y]);
  }
  void flush(int p, int k) {
    while(limit <= p) merge(k, limit++);
    laz[k]++, sum += S[k].size();
  }
  int query(int x) {return val[x] + laz[bel[find(x)]];}
} A, B;
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  // FILE* CSYAKIOI = freopen("zero.in", "r", stdin);
  // FILE* CSYAKUOI = freopen("zero.out", "w", stdout);
  cin >> n;
  for(int i = 1; i <= n; i++) X[i] = read(), X[i] += X[i - 1];
  for(int i = 1; i <= n; i++) Y[i] = read(), Y[i] += Y[i - 1];
  up[0] = dn[0] = to[0] = 0;
  A.init(), B.init();
  for(int k = 1; k <= n; k++) {
    int x = -1, y = -1, z = -1;
    auto it = up.find(X[k]);
    if(it != up.end()) x = it->second;
    up[X[k]] = k;
    it = dn.find(Y[k]);
    if(it != dn.end()) y = it->second;
    dn[Y[k]] = k;
    it = to.find(X[k] + Y[k]);
    if(it != to.end()) z = it->second;
    to[X[k] + Y[k]] = k;
    A.flush(x, k), B.flush(y, k);
    f[k] = z == -1 ? 0 : f[z] + 1;
    f[k] = max(f[k], f[k - 1]);
    f[k] = max(f[k], A.query(k - 1));
    f[k] = max(f[k], B.query(k - 1));
    if(x != -1) f[k] = max(f[k], B.query(x) + 1);
    if(y != -1) f[k] = max(f[k], A.query(y) + 1);
    sum += A.sum + B.sum + f[k];
    A.sum += f[k];
    B.sum += f[k];
    int l = A.limit, r = k;
    while(l < r) {
      int m = l + r >> 1;
      if(B.query(m) < f[k]) l = m + 1;
      else r = m;
    }
    if(!A.S[l].empty()) A.fa[k] = A.S[l].front();
    else A.bel[k] = l; // add this line
    A.S[l].push_back(k);
    A.val[k] = f[k] - A.laz[l]; // add this line
    l = B.limit, r = k;
    while(l < r) {
      int m = l + r >> 1;
      if(A.query(m) < f[k]) l = m + 1;
      else r = m;
    }
    if(!B.S[l].empty()) B.fa[k] = B.S[l].front();
    else B.bel[k] = l; // add this line
    B.S[l].push_back(k);
    B.val[k] = f[k] - B.laz[l]; // add this line
    for(pii it : u[k]) ans[it.se] = A.query(it.fi);
    for(pii it : d[k]) ans[it.se] = B.query(it.fi);
  }
  print(f[n]), pc('\n');
  cerr << TIME << " ms\n";
  return fwrite(Obuf, 1, O - Obuf, stdout), 0;
}
/*
good problem
*/