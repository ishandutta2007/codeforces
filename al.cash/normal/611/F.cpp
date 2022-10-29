#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define eb emplace_back
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1e9;
const ll INF_LL = 4e18;
const double pi = acos(-1.0);

template <class T> T& smin(T& x, const T& y) { if (x > y) x = y; return x; }
template <class T> T& smax(T& x, const T& y) { if (x < y) x = y; return x; }
template <class T> T sqr(const T& x) { return x * x; }

template <typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
           const char* delimiter = " ", const char* closing = "\n") {
  for (; begin != end; ++begin != end ? printf("%s", delimiter) : 0)
    printf(fmt, *begin);
  printf("%s", closing);
}

const int mod = 1e9+7;
void inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }
int add(int x, int y) { inc(x, y); return x; }
int mul(int x, int y) { return (long long)x * y % mod; }

void dec(int &x, int y) { x -= y; if (x < 0) x += mod; }
int sub(int x, int y) { dec(x, y); return x; }

const int N = 5e5+5;
int n, h, w;
char o[N];

int xa[N], xb[N], ya[N], yb[N];
vi c;
bool ok[N];

int solve(int x, int y) {
  int xl = 0, xr = 0, yl = 0, yr = 0;
  int dx = 0, dy = 0;
  int ans = 0;
  REP(u, N) {
//    printf("%d: ", u); print("%d", all(c));
    int m = sz(c);
    fill_n(ok, m, true);
    REP(j, m) {
      int i = c[j]+1;
      bool cx = false, cy = false;
      if (xl > xa[i] + dx) cx = true, xl = xa[i] + dx;
      if (xr < xb[i] + dx) cx = true, xr = xb[i] + dx;
      if (yl > ya[i] + dy) cy = true, yl = ya[i] + dy;
      if (yr < yb[i] + dy) cy = true, yr = yb[i] + dy;
//      printf("%d: x[%d,%d] y[%d,%d]\n", i-1, xl, xr, yl, yr);
      int k = 0;
      if (cx) k = w - (yr-yl);
      if (cy) k = h - (xr-xl);
      if (k == 0) {
        ok[j] = false;
      } else {
        inc(ans, mul(k, add(mul(u, n), i)));
      }
      if (xr-xl >= h || yr-yl >= w) return ans;
    }
    dx += x;
    dy += y;
    vi t;
    REP(j, m) if (ok[j]) t.pb(c[j]);
    c.swap(t);
  }
  return ans;
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d%s", &n, &h, &w, o);
  int x = 0, y = 0;
  xa[0] = xb[0] = ya[0] = yb[0] = 0;
  REP(i, n) {
    switch (o[i]) {
      case 'U': --x; break;
      case 'D': ++x; break;
      case 'L': --y; break;
      case 'R': ++y; break;
    }
    xa[i+1] = min(xa[i], x);
    xb[i+1] = max(xb[i], x);
    ya[i+1] = min(ya[i], y);
    yb[i+1] = max(yb[i], y);
    if (xa[i+1] != xa[i] || xb[i+1] != xb[i] ||
        ya[i+1] != ya[i] || yb[i+1] != yb[i]) c.pb(i);
  }
  if (x == 0 && y == 0 && xb[n]-xa[n] < h && yb[n]-ya[n] < w) {
    printf("-1\n");
  } else {
    printf("%d\n", solve(x, y));
  }

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}