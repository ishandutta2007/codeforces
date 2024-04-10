#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdarg>
#include <cstdio>
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

template<class T, class Tmul>
struct Modular {
  static T module;
  T v;

  Modular(const T& x = 0) : v(x % module) { if (v < 0) v += module; }
  operator T () const { return v; }

  Modular& operator += (const Modular& b) {
    v += b.v; if (v >= module) v -= module;
    return *this;
  }
  Modular& operator -= (const Modular& b) {
    v -= b.v; if (v < 0) v += module;
    return *this;
  }
  Modular& operator *= (const Modular& b) {
    return *this = *this * b;
  }
  friend Modular operator + (Modular a, const Modular& b) { a += b; return a; }
  friend Modular operator - (Modular a, const Modular& b) { a -= b; return a; }
  friend Modular operator * (const Modular& a, const Modular& b) {
    return Tmul(a.v) * b.v % module;
  }
};

typedef Modular<int, ll> Mi;
template<> int Mi::module = 1e9+7;

template<class T>
T qpow(T a, ll p) {
  T res = 1;
  for (; p; p >>= 1, a *= a) if (p & 1) res *= a;
  return res;
}

template<class T> T inv(const T& a) { return qpow(a, a.module - 2); }

const int A = 1e6;
int lp[A+1];
vi p;
Mi pinv[A];
int last[A];

const int N = 2e6;
int n, q, a[N];
int l[N], r[N], o[N];
int ans[N];

Mi t[2*N];

Mi query(int p) {
  Mi res = 1;
  for (p += n; p; p >>= 1) res *= t[p];
  return res;
}

void modify(int l, int r, Mi value) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] *= value;
    if (r&1) t[--r] *= value;
  }
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  for (int i = 2; i <= A; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      p.pb(i);
      pinv[i] = inv(Mi(i)) * Mi(i - 1);
    }
    for (int j = 0; j < sz(p) && p[j] <= lp[i] && i * p[j] <= A; ++j)
      lp[i * p[j]] = p[j];
  }

  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);
  REP(i, 2*n) t[i] = 1;
  scanf("%d", &q);
  REP(i, q) {
    scanf("%d%d", l+i, r+i);
    --l[i];
    --r[i];
    o[i] = i;
  }
  sort(o, o+q, [](int i, int j) { return r[i] < r[j]; });
  CL(last, -1);
  int u = 0;
  REP(i, n) {
    int v = a[i];
    while (v != 1) {
      int p = lp[v], m = 1;
      do {
        m *= p;
        v /= p;
      } while (lp[v] == p);
      if (last[p] >= 0) modify(0, last[p]+1, m);
      modify(last[p]+1, i+1, pinv[p] * Mi(m));
      last[p] = i;
    }
    for (; u < q && r[o[u]] == i; ++u)
      ans[o[u]] = query(l[o[u]]);
  }
  print("%d", ans, ans+q, "\n");

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}