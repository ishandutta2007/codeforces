#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <complex>
#include <numeric>
#include <bitset>
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
#define FORE(e, v) for (int e = head[v]; e >= 0; e = E[e].next)
#define UN(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
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
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T> T sqr(T a) { return a * a; }

template<class T1, class T2>
ostream& operator << (ostream& out, const pair<T1, T2>& p) {
  out << p.X << ',' << p.Y;
  return out;
}
template<class T> void outp(const vector<T>& v) {
  cout << sz(v) << ":";
  REP(i, sz(v)) cout << " " << v[i];
  cout << endl;
}
template<class T> void outp(T* v, int n) {
  cout << n << ":";
  REP(i, n) cout << " " << *v++;
  cout << endl;
}

// All the primes <= n - sieve of Eratosthenes O (n log log n)
template<int N>
vi gen_primes(int n) {
  bitset<N/2> y;
  vi p;
  if (n >= 2) p.pb(2);
  y.set();
  REP(i, (n-1)/2) if (y[i]) {
    int v = 2*i+3;
    p.pb(v);
    for (int u = v, m = n/v; u <= m; u += 2) y.reset((v*u-3)>>1);
  }
  return p;
}

const int h = 5005, S = 31627;
int n, m;
int a[h];

set<int> b;
vi p;
vector<bool> bp;

int f(int x) {
  int res = 0;
  REP(i, sz(p)) {
    if (p[i] * p[i] > x) break;
    if (x % p[i] == 0) {
      int k = 0;
      while (x % p[i] == 0) x /= p[i], ++k;
      if (bp[i]) res -= k;
      else res += k;
    }
  }
  if (x != 1) {
    if (b.count(x)) --res;
    else ++res;
  }
  return res;
}

int g[h], d[h];
vi x;

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%d", a+i);
  int t;
  REP(j, m) {
    scanf("%d", &t);
    b.insert(t);
  }
  p = gen_primes<S>(S);
  REP(i, sz(p)) bp.pb(b.count(p[i]));

  int ans = 0;
  REP(i, n) ans += f(a[i]);
  g[0] = a[0];
  FOR(i, 1, n) g[i] = gcd(g[i-1], a[i]);
  REP(i, n) if (i == 0 || g[i] != g[i-1] || i == n-1 || g[i] != g[i+1])
    x.pb(i);
//  outp(g, n);
//  outp(x);
  FORD(i, sz(x)-1, 0) {
    int u = x[i];
    d[i] = (u + 1) * f(g[u]);
    FOR(j, i+1, sz(x))
      smin(d[i], d[j] + (u + 1) * f(g[u]/g[x[j]]));
  }
//  outp(d, sz(x));
  printf("%d\n", ans - *min_element(d, d+sz(x)+1));

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}