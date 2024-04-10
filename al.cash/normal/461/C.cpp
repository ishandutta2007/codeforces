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

const int h = 100011;

template<int N, class T>
struct TreeSum {
  int n;
  T t[2*N];

  T& operator [](int p) { return t[n+p]; }

  void build(int nn = 0) {
    if (nn != 0) n = nn;
    FORD(i, n-1, 1) t[i] = t[i*2] + t[i*2+1];
  }

  void inc(int p, T delta) {
    for (p += n; p > 0; p /= 2) t[p] += delta;
  }

  void upd(int p, T newv) {
    for (t[p += n] = newv; p > 1; p /= 2) t[p/2] = t[p] + t[p^1];
  }

  T sum(int l, int r) {
    T res = 0;
    for (l += n, r += n-1; l <= r; l = (l+1)/2, r = (r-1)/2) {
      if ( l&1) res += t[l];
      if (~r&1) res += t[r];
    }
    return res;
  }
};

TreeSum<h, int> t;
int n, q;

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &q);
  int cl = 0, cr = n;
  bool rev = false;
  t.n = n;
  FOR(i, cl, cr) t[i] = 1;
  t.build();
  int o, p, l, r;
  REP(u, q) {
    scanf("%d", &o);
    if (o == 1) {
      scanf("%d", &p);
      int d = cr - cl;
      if (p > d / 2) {
        p = d - p;
        rev = !rev;
      }
      if (!rev) {
        REP(i, p) {
          t.inc(cl+p+p-i-1, t[cl+i]);
          t.upd(cl+i, 0);
        }
        cl += p;
      } else {
        REP(i, p) {
          t.inc(cr-p-p+i, t[cr-i-1]);
          t.upd(cr-i-1, 0);
        }
        cr -= p;
      }
//      printf("%d %d (%d)\n", cl, cr, int(rev));
//      REP(i, n) printf("%d ", t[i]); printf("\n");
    } else {
      scanf("%d%d", &l, &r);
      int ans;
      if (!rev) ans = t.sum(cl + l, cl + r);
      else ans = t.sum(cr - r, cr - l);
      printf("%d\n", ans);
    }
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}