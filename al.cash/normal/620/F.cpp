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

const int N = 5e4+5, A = 1e6+1;
int f[A];
int n, m, a[N];
vector<pii> s[N];
int opt[N];
int ans[N];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  f[0] = 0;
  FOR(i, 1, A) f[i] = f[i-1] ^ i;

  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%d", a+i);
  REP(i, m) {
    int l, r;
    scanf("%d%d", &l, &r);
    s[r-1].eb(l-1, i);
  }
  REP(i, n) sort(all(s[i]), greater<pii>());

  REP(i, n) {
    REP(j, i) {
      if (a[i] >= a[j]) smax(opt[j], f[a[i]] ^ f[a[j]-1]);
      else smax(opt[j], f[a[j]] ^ f[a[i]-1]);
    }
    opt[i] = a[i];
    int j = i, v = 0;
    for (auto p : s[i]) {
      while (j >= p.X) smax(v, opt[j]), --j;
      ans[p.Y] = v;
    }
  }

  print("%d", ans, ans + m, "\n");

#ifdef LocalHost
  cout << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}