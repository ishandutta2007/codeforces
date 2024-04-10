#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <complex>
#include <numeric>
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
#define UN(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T> T sqr(T a) { return a * a; }

template<class T> void outp(const vector<T>& v) {
  REP(i, sz(v)) cout << v[i] << (i + 1 == sz(v) ? '\n' : ' ');
}
template<class T> void outp(T* v, int n) {
  REP(i, n) cout << *v++ << (i + 1 == n ? '\n' : ' ');
}

int m;

int mul(int a, int b) { return ll(a) * b % m; }
void inc(int& a, int b) { a += b; if (a >= m) a -= m; }

const int h = 2;
struct M {
  int m[h][h];
  M() { CL(m, 0); }
};

M mul(const M& A, const M& B) {
  M C;
  REP(i, h) REP(j, h) REP(k, h)
      inc(C.m[i][j], mul(A.m[i][k], B.m[k][j]));
  return C;
}

M qpow(M A, ll p) {
  M res;
  res.m[0][0] = res.m[1][1] = 1 % m;
  while (p) {
    if (p & 1) res = mul(res, A);
    A = mul(A, A);
    p >>= 1;
  }
  return res;
}

ll l, r, k;

ll f(ll n, ll d) {
  return n / d;
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  cin >> m >> l >> r >> k;

  ll x = (r - l) / (k - 1);
  if (x <= 1000000) {
    while (f(r, x) - f(l - 1, x) < k) --x;
  }
  else {
    ll a = 1;
    do {
      x = r / (a + k - 1);
      ++a;
    } while (f(r, x) - f(l - 1, x) < k);
  }

  M A;
  A.m[0][0] = A.m[0][1] = A.m[1][0] = 1 % m;
  A = qpow(A, x);

  //cout << x << endl;
  cout << A.m[0][1] << endl;

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}