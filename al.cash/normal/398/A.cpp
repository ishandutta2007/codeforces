#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <complex>
#include <numeric>
#include <bitset>
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
#define FORE(e, v) for (int e = head[v]; e >= 0; e = E[e].next)
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

template<class T1, class T2>
ostream& operator << (ostream& out, const pair<T1, T2>& p) {
  out << p.X << ',' << p.Y;
  return out;
}
template<class T> void outp(const vector<T>& v) {
  cout << sz(v) << ":";
  REP(i, sz(v)) cout << " " << v[i];
  cout << endl;
}
template<class T> void outp(T* v, int n) {
  cout << n << ":";
  REP(i, n) cout << " " << *v++;
  cout << endl;
}

ll sqr(ll x) { return x * x; }

int a, b, ga, gb;
ll ans;

ll f(ll gb) {
  if (gb > b) return INF_LL;
  if (b == 0) return 0;
  if (gb == 0) return INF_LL;
  int k1 = b % gb;
  int k0 = gb - k1;
  ll x = b / gb;
  return k0 * sqr(x) + k1 * sqr(x+1);
}

void outp(char c, int n) {
  REP(i, n) printf("%c", c);
}

int main() {
#ifdef LocalHost
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &a, &b);
  if (a == 0) {
    ans = -sqr(b);
    ga = 0;
    gb = 1;
  } else {
    ans = -INF_LL;
    FOR(i, 1, a+1) {
      ll ca = i-1 + sqr(a-i+1), c;
      c = ca - f(i-1);
      if (c > ans) smax(ans, c), ga = i, gb = i-1;
      c = ca - f(i);
      if (c > ans) smax(ans, c), ga = i, gb = i;
      c = ca - f(i+1);
      if (c > ans) smax(ans, c), ga = i, gb = i+1;
    }
  }
  printf("%I64d\n", ans);
  int k1 = gb == 0 ? 0 : b % gb;
  int k0 = gb - k1;
  ll x = gb == 0 ? 0 : b / gb;
  //printf("%d %d\n", ga, gb);
  if (gb > ga) {
    outp('x', x); --k0;
  }
  REP(i, ga) {
    if (i == 0) outp('o', a - ga + 1);
    else outp('o', 1);
    if (k0 > 0) outp('x', x), --k0;
    else if (k1 > 0) outp('x', x+1), --k1;
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}