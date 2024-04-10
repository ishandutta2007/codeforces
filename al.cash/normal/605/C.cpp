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

template<class T> T& smin(T& a, const T& b) { if (a > b) a = b; return a; }
template<class T> T& smax(T& a, const T& b) { if (a < b) a = b; return a; }
template<class T> T sqr(const T& a) { return a * a; }

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
           const char* delimiter = " ", const char* closing = "\n") {
  for (; begin != end; ++begin != end ? printf("%s", delimiter) : 0)
    printf(fmt, *begin);
  printf("%s", closing);
}

ll f(ll x1, ll y1, ll x2, ll y2) {
  return x1 * y2 - y1 * x2;
}

ll f(const pii& a, const pii& b) {
  return f(a.X, a.Y, b.X, b.Y);
}

const int N = 1e5+1;
int n, p, q, a, b;

double ternary_search(int l, int r, double (*f)(int)) {
  while (l + 10 < r) {
    int lt = (l * 2 + r + 1) / 3;
    int rt = (l + 2 * r + 1) / 3;
    if (f(lt) > f(rt)) l = lt;  // > if \/, < if /\.
    else r = rt;
  }
  double ans = 1e100;
  FOR(i, l, r) smin(ans, f(i));
  return ans;
}

vector<pii> vl, vr, t;
bool cmp(const pii& a, const pii& b) {
  return f(a, b) < 0;
}

bool bad(const pii& a, const pii& b) {
  return a.X <= b.X && a.Y <= b.Y;
}

pii cl;
double calc(int i) {
  ld d = f(cl, vr[i]);
  ld d1 = f({p, q}, vr[i]);
  ld d2 = f(cl, {p, q});
  return (d1 + d2) / d;
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  double ans = 1e100;
  scanf("%d%d%d", &n, &p, &q);
  REP(i, n) {
    scanf("%d%d", &a, &b);
    ll o = f(a, b, p, q);
    smin(ans, max(double(p) / a, double(q) / b));
    if (o > 0) {
      vr.eb(a, b);
    } else if (o < 0) {
      vl.eb(a, b);
    }
  }

  if (!vl.empty() && !vr.empty()) {
    sort(all(vl), cmp);
    sort(all(vr), cmp);

    FOR(i, 0, sz(vr)) {
      while (!t.empty() && bad(t.back(), vr[i])) t.pop_back();
      if (t.empty() || !bad(vr[i], t.back())) t.pb(vr[i]);
    }

    vr.swap(t);
    REP(i, sz(vl)) {
      cl = vl[i];
      smin(ans, ternary_search(0, sz(vr), calc));
    }
  }

  printf("%.9lf\n", (double)ans);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}