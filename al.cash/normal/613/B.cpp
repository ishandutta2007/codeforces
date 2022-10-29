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
void print(const char* fmt, Iterator begin, Iterator end,
           const char* delimiter = " ", const char* closing = "\n") {
  for (; begin != end; ++begin != end ? printf("%s", delimiter) : 0)
    printf(fmt, *begin);
  printf("%s", closing);
}

const int N = 1e5+5;
int n, A, cf, cm;
ll m;
int a[N], o[N];

int kA = 0;
ll ans = 0, aopt = 0;

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d%d%lld", &n, &A, &cf, &cm, &m);
  REP(i, n) scanf("%d", a+i);
  REP(i, n) o[i] = i;
  sort(o, o+n, [](int i, int j) { return a[i] < a[j]; });

  int u = 0;
  ll amin = a[o[u]];
  while (m > 0) {
    ll t = m / (u + 1);
    if (u == n-1) smin(t, A - amin);
    else smin(t, (ll)a[o[u+1]] - a[o[u]]);
    amin += t;
    m -= (u + 1) * t;
    if (u == n-1 || amin < a[o[u+1]]) break;
    ++u;
  }

  REP(i, n+1) {
    ll cur = ll(i) * cf + amin * cm;
//    printf("%d: %lld -> %lld\n", i, amin, cur);
//    printf("m = %lld, u = %d\n", m, u);
    if (cur > ans) {
      ans = cur;
      kA = i;
      aopt = amin;
    }

    if (i == n) break;
    m -= A - a[o[n-i-1]];
    if (u == n-i-1) {
      m += amin - a[o[u]];
      --u;
    }

    while (u >= 0 && m < 0) {
      ll t = (-m + u) / (u + 1);
      smin(t, amin - a[o[u]]);
      amin -= t;
      m += (u + 1) * t;
//      printf("m = %lld, u = %d, t = %lld, amin = %lld\n", m, u, t, amin);
      if (amin > a[o[u]]) break;
      --u;
    }
//    printf("m = %lld, u = %d\n", m, u);
    if (m < 0) break;
  }

  printf("%lld\n", ans);
  REP(i, kA) a[o[n-i-1]] = A;
  REP(i, n) smax(a[i], (int)aopt);
  print("%d", a, a+n);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}