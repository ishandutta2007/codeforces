#include <stdexcept>
#include <iostream>
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
#define sz(a) int((a).size())
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

const int N = 2001;
int n, s;
pii a[N];
vi b;

inline int dist(int i, int j) {
  int l = abs(i - j);
//  printf("%d %d: %d\n", i, j, min(l, n-l));
  return min(l, n - l);
}

struct S {
  int t;
  int u, x, y, cl;

  S(int t0 = INF) : t(t0) {}
  void upd(int tt, int uu, int xx, int yy, int ccl) {
    if (t > tt) t = tt, u = uu, x = xx, y = yy, cl = ccl;
  }
};
vector<vector<vector<vector<S>>>> d;

void outp(int i, int j) {
  int cl = j - i;
  if (cl < 0) cl += n;
  int ccl = i - j;
  if (ccl < 0) ccl += n;
  if (cl <= ccl) printf("+%d\n", cl);
  else printf("-%d\n", ccl);
}

inline int trim(int x, int k) {
  if (x < 0) return x + k;
  if (x >= k) return x - k;
  return x;
}

void answer() {
  vi o;
  int t = INF, u = sz(d)-1, x, y, cl;
  int k = b.back() - b[sz(b)-2];
  REP(j, k) {
    if (d[u][j][trim(j+1, k)][0].t < t)
      t = d[u][j][trim(j+1, k)][0].t, x = j, y = trim(j+1, k), cl = 0;
    if (d[u][j][trim(j-1, k)][1].t < t)
      t = d[u][j][trim(j-1, k)][1].t, x = j, y = trim(j-1, k), cl = 1;
  }
  printf("%d\n", t);
  while (u != -1) {
//    printf("%d %d %d %d\n", u, x, y, cl);
    o.pb(a[b[u]+x].Y);
//    printf("pos: %d\n", o.back());
    const S& c = d[u][x][y][cl];
    u = c.u;
    x = c.x;
    y = c.y;
    cl = c.cl;
  }
  o.pb(s);
  reverse(all(o));
  REP(i, sz(o)-1) outp(o[i], o[i+1]);
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &s);
  --s;
  REP(i, n) {
    scanf("%d", &a[i].X);
    a[i].Y = i;
  }
  sort(a, a+n);
  b = {0};
  FOR(i, 1, n+1) if (i == n || a[i-1].X != a[i].X) {
    int u = sz(d);
    int l = b.back(), k = i - l;
    d.pb(vector<vector<vector<S>>>(k, vector<vector<S>>(k, vector<S>(2))));

//    REP(j, k) printf("%d,%d ", a[l+j].X, a[l+j].Y); printf("\n");

    REP(j, k) {
      if (u == 0) {
        d[u][j][j][0].upd(dist(a[l+j].Y, s), -1, 0, 0, 0);
      } else {
        int pl = b[sz(b)-2], pk = l - pl;
        REP(p, pk) {
          int y0 = trim(p+1, pk), y1 = trim(p-1, pk);
          d[u][j][j][0].upd(d[u-1][p][y0][0].t + dist(a[l+j].Y, a[pl+p].Y),
                            u-1, p, y0, 0);
          d[u][j][j][0].upd(d[u-1][p][y1][1].t + dist(a[l+j].Y, a[pl+p].Y),
                            u-1, p, y1, 1);
        }
      }
      const S& c = d[u][j][j][0];
      d[u][j][j][1].upd(c.t, c.u, c.x, c.y, c.cl);
    }

    FOR(r, 0, k-1) {
      REP(j, k) {
        int y0 = trim(j-r, k), y1 = trim(j+r, k), w;
        w = trim(j+1, k);
        d[u][w][y0][0].upd(d[u][j][y0][0].t + dist(a[l+j].Y, a[l+w].Y),
                           u, j, y0, 0);
        w = trim(y0-1, k);
        d[u][w][j][1].upd(d[u][j][y0][0].t + dist(a[l+j].Y, a[l+w].Y),
                          u, j, y0, 0);
        w = trim(j-1, k);
        d[u][w][y1][1].upd(d[u][j][y1][1].t + dist(a[l+j].Y, a[l+w].Y),
                           u, j, y1, 1);
        w = trim(y1+1, k);
        d[u][w][j][0].upd(d[u][j][y1][1].t + dist(a[l+j].Y, a[l+w].Y),
                          u, j, y1, 1);
      }
    }
//    printf("%d:\n", u);
//    REP(x, k) REP(y, k) REP(cl, 2) {
//      S& c = d[u][x][y][cl];
//      printf("%d %d %d: %d %d %d %d %d\n", x, y, cl, c.t, c.u, c.x, c.y, c.cl);
//    }

    b.pb(i);
  }

  answer();

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}