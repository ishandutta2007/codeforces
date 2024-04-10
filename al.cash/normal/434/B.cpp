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

const int h = 1011;
int n, m, q;
int a[h][h];
int ra[h][h], rb[h][h], ca[h][h], cb[h][h];

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d", &n, &m, &q);
  REP(i, n) REP(j, m) scanf("%d", a[i]+j);
  REP(i, n) REP(j, m) if (a[i][j] == 0) {
    ra[i][j] = rb[i][j] = i;
    ca[i][j] = cb[i][j] = j;
  }
  REP(i, n) REP(j, m) if (a[i][j] == 1 && rb[i][j] == 0) {
    int x = i+1;
    while (x < n && a[x][j] == 1) ++x;
    FOR(u, i, x) ra[u][j] = i, rb[u][j] = x;
  }
  REP(i, n) REP(j, m) if (a[i][j] == 1 && cb[i][j] == 0) {
    int y = j+1;
    while (y < m && a[i][y] == 1) ++y;
    FOR(u, j, y) ca[i][u] = j, cb[i][u] = y;
  }
  REP(t, q) {
    int o, x, y;
    scanf("%d%d%d", &o, &x, &y);
    --x; --y;
    if (o == 1) {
      int xa = x, xb = x+1;
      while (0 < xa && a[xa-1][y] == 1) --xa;
      while (xb < n && a[xb][y] == 1) ++xb;

      int ya = y, yb = y+1;
      while (0 < ya && a[x][ya-1] == 1) --ya;
      while (yb < m && a[x][yb] == 1) ++yb;

      if (a[x][y] == 1) {
        a[x][y] = 0;
        ra[x][y] = rb[x][y] = x;
        ca[x][y] = cb[x][y] = y;
        FOR(i, xa, x)   ra[i][y] = xa,  rb[i][y] = x;
        FOR(i, x+1, xb) ra[i][y] = x+1, rb[i][y] = xb;
        FOR(j, ya, y)   ca[x][j] = ya,  cb[x][j] = y;
        FOR(j, y+1, yb) ca[x][j] = y+1, cb[x][j] = yb;
      } else {
        a[x][y] = 1;
        FOR(i, xa, xb) ra[i][y] = xa, rb[i][y] = xb;
        FOR(j, ya, yb) ca[x][j] = ya, cb[x][j] = yb;
      }
//      REP(i, n) print("%d", r[i], r[i]+m); printf("\n");
//      REP(i, n) print("%d", c[i], c[i]+m); printf("\n");
    } else {
      int ans = 0;
      int ya = 0, yb = m;
      for (int i = x; i < n && ya < yb; ++i) {
        smax(ya, ca[i][y]);
        smin(yb, cb[i][y]);
        smax(ans, (yb - ya) * (i - x + 1));
      }
      ya = 0, yb = m;
      for (int i = x; i >= 0 && ya < yb; --i) {
        smax(ya, ca[i][y]);
        smin(yb, cb[i][y]);
        smax(ans, (yb - ya) * (x - i + 1));
      }
      int xa = 0, xb = n;
      for (int j = y; j < m && xa < xb; ++j) {
        smax(xa, ra[x][j]);
        smin(xb, rb[x][j]);
        smax(ans, (xb - xa) * (j - y + 1));
      }
      xa = 0, xb = n;
      for (int j = y; j >= 0 && xa < xb; --j) {
        smax(xa, ra[x][j]);
        smin(xb, rb[x][j]);
        smax(ans, (xb - xa) * (y - j + 1));
      }
      printf("%d\n", ans);
    }
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}