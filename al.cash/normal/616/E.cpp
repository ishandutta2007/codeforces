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

const int module = static_cast<int>(1e9+7);
void inc(int &x, int y, int mod = module) { x += y; if (x >= mod) x -= mod; }
int add(int x, int y, int mod = module) { inc(x, y, mod); return x; }
int mul(int x, int y, int mod = module) {
  return static_cast<int>(static_cast<long long>(x) * y % mod);
}

void dec(int &x, int y, int mod = module) { x -= y; if (x < 0) x += mod; }
int sub(int x, int y, int mod = module) { dec(x, y, mod); return x; }

int arithm(ll n) {
  n %= module;
  if (n&1) return mul(n, (n + 1) / 2);
  else return mul(n / 2, n + 1);
}

ll n, m;

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%lld%lld", &n, &m);
  int ans = mul(n % module, m % module);
  smin(m, n);
  while (m > n / m) {
    ll q = n / m;
    ll l = n / (q + 1);
    inc(ans, mul(sub(arithm(l), arithm(m)), q % module));
    m = l;
  }
  for (; m > 0; --m) dec(ans, mul(m, n / m % module));
  printf("%d\n", ans);

#ifdef LocalHost
  cout << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}