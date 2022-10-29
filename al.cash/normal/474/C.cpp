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
ll sqr(ll a) { return a * a; }

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
    const char* separator = " ") {
  for (Iterator it = begin; it != end; ++it) {
    if (it != begin) printf(separator);
    printf(fmt, *it);
  }
  printf("\n");
}

const int h = 411;
int n, x[4], y[4], a[4], b[4];

void rot(int &x, int &y, int a, int b) {
  int t = x;
  x = a - (y - b);
  y = b + (t - a);
}

ll dist(int i, int j) {
  return sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
}

bool square() {
  vector<ll> d;
  REP(i, 4) FOR(j, i+1, 4) d.pb(dist(i, j));
  sort(all(d));
  if (d[0] == 0) return false;
  FOR(i, 1, 4) if (d[i] != d[0]) return false;
  if (d[4] != d[5]) return false;
  return true;
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) {
    REP(j, 4) scanf("%d%d%d%d", x+j, y+j, a+j, b+j);
    int ans = INF;
    REP(r0, 4) {
      REP(r1, 4) {
        REP(r2, 4) {
          REP(r3, 4) {
            if (square()) smin(ans, r0 + r1 + r2 + r3);
            rot(x[3], y[3], a[3], b[3]);
          }
          rot(x[2], y[2], a[2], b[2]);
        }
        rot(x[1], y[1], a[1], b[1]);
      }
      rot(x[0], y[0], a[0], b[0]);
    }
    printf("%d\n", ans == INF ? -1 : ans);
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}