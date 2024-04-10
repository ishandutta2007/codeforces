#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a%b); }

const int h = 100011;
int n, g,r, q, mod;
int d[h];
ll s[h], ans[h];

vi t[3*h];

void build(int l, int r, int v = 1) {
  if(l>=r) return;
  if(l==r-1) {
    t[v].pb(s[r] % mod);
  } else {
    int m = (l+r) / 2;
    build(l, m, 2*v);
    build(m, r, 2*v+1);
    t[v].resize(sz(t[2*v]) + sz(t[2*v+1]));
    t[v].resize(set_union(all(t[2*v]), all(t[2*v+1]), t[v].begin())
        - t[v].begin());
  }
  //printf("%d (%d,%d):", v, l, r); REP(i, sz(t[v])) printf(" %d", t[v][i]); printf("\n");
}

int get(int a, int b, int l, int r, int tl = 0, int tr = n, int v = 1) {
  if(l>=r) return n;
  if(l==tl && r==tr) {
    int p = lower_bound(all(t[v]), a) - t[v].begin();
    if(p<sz(t[v]) && t[v][p]<b) {
      if(l==r-1) return l;
      int m = (l+r) / 2;
      int res = get(a, b, l, m, l, m, 2*v);
      if(res != n) return res;
      else return get(a, b, m, r, m, r, 2*v+1);
    } else return n;
  } else {
    int m = (tl+tr) / 2;
    int res = n;
    if(l<m) res = get(a, b, l, min(m,r), tl, m, 2*v);
    if(res != n) return res;
    if(r>m) res = get(a, b, max(l,m), r, m, tr, 2*v+1);
    return res;
  }
}

int a, b;

ll ceil(ll x) {
  ll r = x % mod;
  return r == 0 ? x : x + mod - r;
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d", &n, &g, &r);
  mod = g + r;
  REP(i, n+1) scanf("%d", d+i);
  s[0] = 0;
  REP(i, n+1) s[i+1] = s[i] + d[i];
  //REP(i, n+2) cout << s[i] << ' '; cout << endl;
  build(0, n);
  ans[n] = 0;
  FORD(i, n-1, 0) {
    b = s[i+1] % mod;
    a = b + g;
    if(a>=mod) a -= mod;
    int w;
    if(a<=b) w = get(a, b, i+1, n);
    else w = min(get(0, b, i+1, n), get(a, mod, i+1, n));
    //printf("%d %d: %d\n", a, b, w);
    if(w==n) ans[i] = s[w+1] - s[i+1];
    else ans[i] = ceil(s[w+1] - s[i+1]) + ans[w];
  }
  //REP(i, n+1) cout << ans[i] << ' '; cout << endl;
  scanf("%d", &q);
  int t;
  REP(i, q) {
    scanf("%d", &t);
    b = mod - (t % mod);
    if(b>=mod) b -= mod;
    a = b + g;
    if(a>=mod) a -= mod;
    int w;
    if(a<=b) w = get(a, b, 0, n);
    else w = min(get(0, b, 0, n), get(a, mod, 0, n));
    //printf("%d %d: %d\n", a, b, w);
//    cout << ans[w] << "!" << endl;
    if(w==n) printf("%I64d\n", t + s[w+1]);
    else printf("%I64d\n", ceil(t + s[w+1]) + ans[w]);
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}