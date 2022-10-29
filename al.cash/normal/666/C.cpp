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

const int module = static_cast<int>(1e9+7);
void inc(int &x, int y, int mod = module) { x += y; if (x >= mod) x -= mod; }
int add(int x, int y, int mod = module) { inc(x, y, mod); return x; }
int mul(int x, int y, int mod = module) {
  return static_cast<int>(static_cast<long long>(x) * y % mod);
}

void dec(int &x, int y, int mod = module) { x -= y; if (x < 0) x += mod; }
int sub(int x, int y, int mod = module) { dec(x, y, mod); return x; }

int inv(int x, int mod = module) {  // x < mod
  return x < 2 ? x : mod - static_cast<long long>(inv(mod % x, x)) * mod / x;
}

template <int N>
class Combinatorics {
  int fact[N+1], factInv[N+1];

public:
  Combinatorics() {
    for (int i = 0; i <= N; ++i) {
      fact[i] = i == 0 ? 1 : mul(fact[i-1], i);
      factInv[i] = inv(fact[i]);
    }
  }

  int factorial(int n) { return fact[n]; }
  int Anm(int n, int m) { return mul(fact[n], factInv[n-m]); }
  int Cnm(int n, int m) { return mul(fact[n], mul(factInv[m], factInv[n-m])); }
  int Cnm(const vi& a) {  // C({n = sum a_i}, a_0, a_1, ...)
    int n = 0, res = 1;
    for (int ai : a) n += ai, res = mul(res, factInv[ai]);
    return mul(fact[n], res);
  }
  int Catalan(int n) { return mul(fact[2*n], mul(factInv[n], factInv[n+1])); }
};


const int N = 1e5+5;
int m, n, l;
char s[N];
vector<pii> q[N];
int ans[N];

Combinatorics<N> C;
int p25[N];
int f[N];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  p25[0] = 1;
  FOR(i, 1, N) p25[i] = mul(p25[i-1], 25);

  scanf("%d%s", &m, s);
  l = strlen(s);
  int k2 = 0;
  REP(i, m) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%s", s);
      l = strlen(s);
    } else {
      scanf("%d", &n);
      q[l].eb(n, k2++);
    }
  }
  FOR(l, 1, N) if (!q[l].empty()) {
    fill_n(f, l, 0);
    FOR(n, l, N) f[n] = add(mul(26, f[n-1]), mul(C.Cnm(n-1, l-1), p25[n-l]));
    for (pii p : q[l]) ans[p.Y] = f[p.X];
  }
  print("%d", ans, ans + k2, "\n");

#ifdef LocalHost
  cerr << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}