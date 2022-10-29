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

const int N = 1e5+5;
int n;
struct P {
  int x, y, i;
  void inp(int j) {
    scanf("%d%d", &x, &y);
    i = j;
  }
} p[N];

bool operator < (const P& a, const P& b) {
  return pii(a.x, a.y) < pii(b.x, b.y);
}

ll area(const P& a, const P& b, const P& c) {
  return abs(ll(b.x - a.x) * ll(c.y - a.y) - ll(c.x - a.x) * (b.y - a.y));
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) p[i].inp(i+1);
  sort(p, p + n);
  int i3 = -1;
  ll opt = 0;
  FOR(i, 2, n) {
    ll cur = area(p[0], p[1], p[i]);
    if (cur == 0) continue;
    if (i3 == -1 || cur < opt) {
      i3 = i;
      opt = cur;
    }
  }
  printf("%d %d %d\n", p[0].i, p[1].i, p[i3].i);

#ifdef LocalHost
  cout << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}