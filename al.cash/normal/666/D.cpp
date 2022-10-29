#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <memory>
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
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), b_(b); i >= b_; --i)
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
template <class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;

const int INF = static_cast<int>(1e9);
const long long INF_LL = static_cast<long long>(4e18);
const double pi = acos(-1.0);

template <class T> T& smin(T& x, const T& y) { if (x > y) x = y; return x; }
template <class T> T& smax(T& x, const T& y) { if (x < y) x = y; return x; }
template <class T> T sqr(const T& x) { return x * x; }

template <class T> T gcd(T a, T b) {
  for (a = abs(a), b = abs(b); a && b; a >= b ? a %= b : b %= a);
  return a + b;
}

template <typename Iterator>
void print(const char* format, Iterator first, Iterator last,
           const char* delimiter = " ", const char* closing = "\n") {
  for (; first != last; ++first != last ? printf("%s", delimiter) : 0)
    printf(format, *first);
  printf("%s", closing);
}

int x[4], y[4];
int xt[4], yt[4];
int ans, cur;
int xa[4], ya[4];

void update(bool rev) {
  if (ans != -1 && cur > ans) return;
  ans = cur;
  REP(i, 4) {
    xa[i] = xt[i];
    ya[i] = yt[i];
    if (rev) swap(xa[i], ya[i]);
  }
//  printf("tmp %d\n", ans);
//  REP(i, 4) printf("%d %d\n", xa[i], ya[i]);
}

void move(int i, int xx, int yy) {
  smax(cur, abs(x[i] - xx) + abs(y[i] - yy));
  xt[i] = xx;
  yt[i] = yy;
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  int t;
  for (scanf("%d", &t); t--; ) {
    REP(i, 4) scanf("%d%d", x+i, y+i);
    ans = -1;
    REP(m, 1<<4) {
      vector<pii> fx, fy;
      REP(i, 4) {
        if (m>>i&1) fx.eb(x[i], i);
        else fy.eb(y[i], i);
      }
      bool rev = sz(fy) > sz(fx);
      if (sz(fy) == sz(fx)) {
        bool diffx = fx[0].X != fx[1].X;
        bool diffy = fy[0].X != fy[1].X;
        if (!diffy && !diffx) continue;
        if (diffy && !diffx) rev = true;
      }
      if (rev) {
        swap(fx, fy);
        REP(i, 4) swap(x[i], y[i]);
      }

      sort(all(fx));
//      printf("%d %d:\n", sz(fx), sz(fy));
      switch (sz(fx)) {
        case 4: {
          if (fx[0].X != fx[1].X || fx[1].X == fx[2].X || fx[2].X != fx[3].X)
            break;
          if (y[fx[0].Y] > y[fx[1].Y]) swap(fx[0], fx[1]);
          if (y[fx[2].Y] > y[fx[3].Y]) swap(fx[2], fx[3]);
//          REP(i, 4) printf("%d %d\n", x[fx[i].Y], y[fx[i].Y]);
          int l = fx[2].X - fx[1].X;
          auto calc = [&](int yy) -> int {
            int res = 0;
            REP(i, 4) smax(res, abs(y[fx[i].Y] - ((i&1) ? yy + l : yy)));
            return res;
          };

          int yl = -INF, yr = INF;
          while (yl + 1 < yr) {
            int ym = (yl + yr) / 2 - 1;
            int cym = calc(ym), cym1 = calc(ym+1);
            if (cym == cym1) { yl = ym; break; }
            if (cym < cym1) yr = ym + 1;
            else yl = ym + 1;
          }
//          FOR(d, -1, 4) printf("%d: %d\n", yl+d, calc(yl+d));
          REP(i, 4) {
            xt[fx[i].Y] = fx[i].X;
            yt[fx[i].Y] = (i&1) ? yl + l : yl;
          }
          cur = calc(yl);
          update(rev);
          break;
        } case 3: {
          if (fx[0].X == fx[1].X) {
            if (fx[1].X == fx[2].X) break;
          } else {
            if (fx[1].X == fx[2].X) swap(fx[0], fx[2]);
            else break;
          }
          if (y[fx[0].Y] > y[fx[1].Y]) swap(fx[0], fx[1]);
          int x0 = fx[0].X, x2 = fx[2].X;
          int y0 = fy[0].X;
          int l = abs(x2 - x0);
//          printf("x0 = %d\n", x0);
//          printf("x2 = %d\n", x2);
//          printf("y0 = %d\n", y0);
          for (int y2 = y0 - l; y2 <= y0 + l; y2 += 2 * l) {
//            printf("y2 = %d ", y2);
            cur = 0;
            move(fx[0].Y, x0, min(y0, y2));
            move(fx[1].Y, x0, max(y0, y2));
            move(fx[2].Y, x2, y2);
            move(fy[0].Y, x2, y0);
            update(rev);
          }
//          printf("\n");
          break;
        } case 2: {
          if (fy[0].X == fy[1].X) {
            if (x[fy[0].Y] > x[fy[1].Y]) swap(fy[0], fy[1]);
            int x0 = fx[0].X, x1 = fx[1].X;
            int l = abs(x1 - x0);
            int y0 = fy[0].X;
            for (int y1 = y0 - l; y1 <= y0 + l; y1 += 2 * l) {
              cur = 0;
              move(fx[0].Y, x0, y1);
              move(fx[1].Y, x1, y1);
              move(fy[0].Y, min(x0, x1), y0);
              move(fy[1].Y, max(x0, x1), y0);
              update(rev);
            }
          } else {
            int x0 = fx[0].X, x1 = fx[1].X;
            int y0 = fy[0].X, y1 = fy[1].X;
            if (abs(x0 - x1) != abs(y0 - y1)) break;
            cur = 0;
            move(fx[0].Y, x0, y0);
            move(fx[1].Y, x1, y1);
            move(fy[0].Y, x1, y0);
            move(fy[1].Y, x0, y1);
            update(rev);
            cur = 0;
            move(fx[0].Y, x0, y1);
            move(fx[1].Y, x1, y0);
            move(fy[0].Y, x0, y0);
            move(fy[1].Y, x1, y1);
            update(rev);
          }
          break;
        }
      }

      if (rev) {
        REP(i, 4) swap(x[i], y[i]);
      }
    }
    printf("%d\n", ans);
    if (ans != -1) REP(i, 4) printf("%d %d\n", xa[i], ya[i]);
  }

#ifdef LocalHost
  cerr << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}