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

const int mod = 1000000007;
void inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }
int add(int x, int y) { inc(x, y); return x; }
int mul(int x, int y) { return (ll(x) * y) % mod; }

void dec(int &x, int y) { x -= y; if (x < 0) x += mod; }
int sub(int x, int y) { dec(x, y); return x; }


typedef ll Tc;  // coordinate type
const Tc inf = INF_LL;
template<class T> int cmp(T x, T y) { return x == y ? 0 : x < y ? -1 : 1; }

struct P {
  Tc x, y;
  P() : x(0), y(0) {}
  P(Tc x, Tc y) : x(x), y(y) {}
};
typedef vector<P> Pset;  // Describes polygons etc.
typedef Pset::iterator Pit;

istream& operator >> (istream& is, P& a) { is >> a.x >> a.y; return is; }
ostream& operator << (ostream& os, P a) { os << a.x << ' ' << a.y; return os; }

int cmp(P a, P b) { int cx = cmp(a.x, b.x); return cx ? cx : cmp(a.y, b.y); }
#define COMP(v) bool operator v (P a, P b) { return cmp(a, b) v 0; }
COMP(==) COMP(!=) COMP(<) COMP(>) COMP(<=) COMP(>=)
#undef COMP

P operator - (P a) { return P(-a.x, -a.y); }
P operator + (P a, P b) { return P(a.x + b.x, a.y + b.y); }
P operator - (P a, P b) { return P(a.x - b.x, a.y - b.y); }
P operator * (Tc c, P a) { return P(c * a.x, c * a.y); }
P operator * (P a, Tc c) { return P(a.x * c, a.y * c); }
P operator / (P a, Tc c) { return P(a.x / c, a.y / c); }

Tc operator * (P a, P b) { return a.x * b.x + a.y * b.y; }
Tc operator ^ (P a, P b) { return a.x * b.y - a.y * b.x; }
Tc abs(P a) { return a * a; }
int ccw(P a, P b) { return cmp(b ^ a, (Tc)0); }  // -1 if b<-a counter-clockwise
int ccw(P o, P a, P b) { return ccw(a - o, b - o); }

bool on_seg(P x, P a, P b) {
  return cmp((x - a) * (x - b), Tc(0)) < 0;
}

bool cross_seg(P a, P ab, P c, P cd) {
  Tc d = ab ^ cd;
  if (cmp(d, Tc(0)) == 0) {
    if (ccw(ab, c - a) != 0) return false;
    P b = a + ab, d = c + cd;
    return on_seg(c, a, b) || on_seg(d, a, b) ||
        on_seg(a, c, d) || on_seg(b, c, d);
  }
  Tc di = (c - a) ^ cd, dj = (c - a) ^ ab;
  if (cmp(d, Tc(0)) < 0) d = -d, di = -di, dj = -dj;
  return 0 < di && 0 <= dj && di < d && dj <= d;
}

const int h = 222;
int n;
Pset p;
P v[h][h];
Tc s[h][h];
bool r[h][h];

int ff[h][h];

int f(int l, int m) {
//  printf("f(%d %d) = ...\n", l, m);
  if (m < 3) return 1;
  int &res = ff[l][m];
  if (res != -1) return res;
  res = 0;
  int l1 = (l + 1) % n, lm = (l + m - 1) % n;
  if (r[l][l1] && r[l1][lm] && ccw(v[l][l1], v[l][lm]) != 0) res = f(l1, m-1);
//  printf("f(%d %d) = %d...\n", l, m, res);
  FOR(i, 3, m) {
    int li = (l + i - 1) % n;
    if (r[l][li] && r[lm][li] && ccw(v[l][li], v[l][lm]) != 0)
      inc(res, mul(f(l, i), f(li, m-i+1)));
  }
//  printf("f(%d %d) = %d\n", l, m, res);
  return res;
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  p.resize(n);
  REP(i, n) cin >> p[i];
  REP(i, n) REP(j, n) v[i][j] = p[j] - p[i];

  REP(i, n) {
    s[i][i] = 0;
    int j = i;
    do {
      int k = j + 1;
      if (k == n) k = 0;
      s[i][k] = s[i][j] + (v[i][k] ^ v[i][j]);
      if (k == i) break;
      j = k;
    } while (true);
    REP(k, n) if (s[i][k] < 0) s[i][k] = -s[i][k];
  }

  CL(r, 0);
  REP(i, n) FOR(j, i+1, n) if (s[i][j] + s[j][i] == s[i][i]) {
    r[i][j] = true;
    REP(k, n) if (cross_seg(p[i], v[i][j], p[k], v[k][(k+1)%n])) {
      r[i][j] = false;
      break;
    }
    r[j][i] = r[i][j];
  }
  //REP(i, n) outp(r[i], n);

  CL(ff, -1);
  printf("%d\n", f(0, n));

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}