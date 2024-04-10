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

template<class T> T qpow(const T& a, int p) {
  T res(1);
  for (T b(a); p; p >>= 1, b = mul(b, b))
    if (p & 1) res = mul(res, b);
  return res;
}

template<class T> T inv(T x) { return qpow(x, mod - 2); }

const int h = 100011;
int n, x[h];
vi r[h];
int d[h][2];

void dfs(int v, int pr) {
  int u;
  if (x[v] == 1) {
    d[v][0] = 0;
    d[v][1] = 1;
    REP(i, sz(r[v])) if ((u = r[v][i]) != pr) {
      dfs(u, v);
      d[v][1] = mul(d[v][1], d[u][0]);
    }
  } else {
    d[v][0] = 1;
    d[v][1] = 0;
    int u0 = -1;
    REP(i, sz(r[v])) if ((u = r[v][i]) != pr)  {
      dfs(u, v);
      if (d[u][0] == 0) {
        if (u0 == -1) u0 = u;
        else if (u0 >= 0) u0 = -2;
      }
      d[v][0] = mul(d[v][0], d[u][0]);
    }
    if (u0 == -1) {
      REP(i, sz(r[v])) if ((u = r[v][i]) != pr)  {
        inc(d[v][1], mul(mul(d[u][1], inv(d[u][0])), d[v][0]));
      }
    } else if (u0 >= 0) {
      d[v][1] = 1;
      REP(i, sz(r[v])) if ((u = r[v][i]) != pr)  {
        if (u == u0) d[v][1] = mul(d[v][1], d[u][1]);
        else d[v][1] = mul(d[v][1], d[u][0]);
      }
    }
  }
  inc(d[v][0], d[v][1]);
}

int main() {
#ifdef LocalHost
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  FOR(i, 1, n) {
    int p;
    scanf("%d", &p);
    r[i].pb(p);
    r[p].pb(i);
  }
  REP(i, n) scanf("%d", x+i);
  CL(d, -1);
  dfs(0, -1);
  //REP(i, n) printf("%d %d\n", d[i][0], d[i][1]);
  printf("%d\n", d[0][1]);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}