/******************************************************************************
 *          How can I feel abandoned even when the world surrounds me         *
 *       How can I bite the hand that feeds the strangers all around me       *
 *             How can I know so many never really knowing anyone             *
 *               If I seem superhuman I have been misunderstood               *
 ******************************************************************************/

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
void print(const char* fmt, Iterator first, Iterator last,
           const char* delimiter = " ", const char* closing = "\n") {
  for (; first != last; ++first != last ? printf("%s", delimiter) : 0)
    printf(fmt, *first);
  printf("%s", closing);
}

struct S {
  int i, j, sum;
  S(int i = 0, int j = 0, int s = 0) : i(i), j(j), sum(s) {}
};

bool operator < (const S& a, const S& b) {
  return a.sum < b.sum;
}

const int N = 2002;
int n, m, a[N], b[N];
ll asum, bsum;

ll opt;
vector<pii> ans;

vector<S> sa, sb;

ll f(ll da, ll db) { return abs(asum - bsum + 2 * (db - da)); }

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);
  scanf("%d", &m);
  REP(i, m) scanf("%d", b+i);

  asum = accumulate(a, a + n, ll(0));
  bsum = accumulate(b, b + m, ll(0));
  opt = abs(asum - bsum);

  REP(i, n) REP(j, m) {
    ll cur = f(a[i], b[j]);
    if (cur < opt) {
      opt = cur;
      ans = {{i, j}};
    }
  }

  sa.reserve(N * N / 2);
  sb.reserve(N * N / 2);
  REP(i, n) FOR(j, i + 1, n) sa.eb(i, j, a[i] + a[j]);
  REP(i, m) FOR(j, i + 1, m) sb.eb(i, j, b[i] + b[j]);
  sort(all(sa));
  sort(all(sb));

  int ia = 0, ib = 0;
  while (ia < sz(sa) && ib < sz(sb)) {
    ll cur = f(sa[ia].sum, sb[ib].sum);
//    printf("%d(%d) %d(%d): %lld\n", ia, sa[ia].sum, ib, sb[ib].sum, cur);
    if (cur < opt) {
      opt = cur;
      ans = {{sa[ia].i, sb[ib].i}, {sa[ia].j, sb[ib].j}};
    }
    if (ia + 1 == sz(sa)) ++ib;
    else if (ib + 1 == sz(sb)) ++ia;
    else {
      if (f(sa[ia+1].sum, sb[ib].sum) < f(sa[ia].sum, sb[ib+1].sum)) ++ia;
      else ++ib;
    }
  }

  printf("%lld\n", opt);
  printf("%d\n", sz(ans));
  for (pii p : ans) printf("%d %d\n", p.X + 1, p.Y + 1);

#ifdef LocalHost
  cout << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}