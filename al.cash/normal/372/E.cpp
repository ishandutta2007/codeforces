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
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T> T sqr(T a) { return a * a; }

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
    const char* separator = " ") {
  for (Iterator it = begin; it != end; ++it) {
    if (it != begin) printf(separator);
    printf(fmt, *it);
  }
  printf("\n");
}

const int mod = 1000000007;
void inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }
int add(int x, int y) { inc(x, y); return x; }
int mul(int x, int y) { return (ll(x) * y) % mod; }
void dec(int &x, int y) { x -= y; if (x < 0) x += mod; }
int sub(int x, int y) { dec(x, y); return x; }

struct rat {
  ll a, b;

  rat(ll a = 0, ll b = 1) : a(a), b(b) { reduce(); }

  void reduce() {
    if (b < 0) a = -a, b = -b;
    ll g = gcd(a, b);
    if (g == 0) a = 0, b = 0;
    else a /= g, b /= g;
  }

  void inp() {
    scanf("%I64d%I64d", &a, &b);
    reduce();
  }

  void outp() { printf("%I64d %I64d\n", a, b); }
};

bool operator == (const rat& a, const rat& b) {
  return a.a == b.a && a.b == b.b;
}

bool operator != (const rat& a, const rat& b) {
  return !(a == b);
}

bool operator < (const rat& a, const rat& b) {
  return a.a < b.a || (a.a == b.a && a.b < b.b);
}

rat operator + (const rat& a, const rat& b) {
  return rat(a.a * b.b + b.a * a.b, a.b * b.b);
}

rat operator - (const rat& a, const rat& b) {
  return rat(a.a * b.b - b.a * a.b, a.b * b.b);
}

rat operator * (const rat& a, const rat& b) {
  return rat(a.a * b.a, a.b * b.b);
}

rat operator / (const rat& a, const rat& b) {
  return rat(a.a * b.b, a.b * b.a);
}

const int h = 1001;
int n;
rat x[h], y[h];

typedef pair<rat, rat> prr;
typedef pair<prr, rat> ppr;
vector<ppr> o;

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) {
    x[i].inp();
    y[i].inp();
    rat d = sqr(x[i]) + sqr(y[i]);
    x[i] = x[i] / d;
    y[i] = y[i] / d;
  }

  o.reserve(n*(n-1) / 2);
  REP(i, n) FOR(j, i+1, n) {
    o.pb(ppr(prr(x[i] + x[j], y[i] + y[j]),
             (x[i] - x[j]) / (y[i] - y[j])));
  }
  sort(all(o));

  int ans = 0, k = 0;
  vi g;
  REP(i, sz(o)) {
    ++k;
    if (i + 1 == sz(o) || o[i] != o[i+1]) {
      g.pb(k);
      k = 0;
    }
    if (i + 1 == sz(o) || o[i].X != o[i+1].X) {
      int p = 1, s = 0;
      REP(j, sz(g)) p = mul(p, g[j] + 1), s += g[j];
      inc(ans, p);
      dec(ans, s + 1);
      g.clear();
    }
  }
  printf("%d\n", ans);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}