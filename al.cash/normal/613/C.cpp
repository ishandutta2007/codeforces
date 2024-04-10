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

const int N = 26;
int n, a[N], sum;

string s;

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i), sum += a[i];
  if (n == 1) {
    s = string(sum, 'a');
    printf("%d\n%s\n", sum, s.c_str());
    return 0;
  }
  int k1 = 0;
  REP(i, n) if (a[i]&1) ++k1;
  
  int g = a[0];
  REP(i, n) g = gcd(g, a[i]);
  if (k1 > 0) {
    if (k1 > 1) {
      REP(i, n) REP(j, a[i]) s += 'a' + i;
      g = 0;
    } else {
      string p(sum / g, 'a');
      int l, r;
      l = r = sz(p) / 2;
      int u = 0;
      while (~a[u]&1) ++u;
      p[l] = 'a' + u;
      a[u] -= g;
      REP(i, n) for (int j = 0; j < a[i]; j += 2 * g) {
        --l;
        ++r;
        p[l] = p[r] = 'a' + i;
      }
      REP(i, g) s += p;
    }
  } else {
    string o, r;
    REP(i, n) for (int j = 0; j < a[i]; j += g) o += 'a' + i;
    r = o;
    reverse(all(r));
    REP(u, g / 2) s += o + r;
  }
  printf("%d\n%s\n", g, s.c_str());

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}