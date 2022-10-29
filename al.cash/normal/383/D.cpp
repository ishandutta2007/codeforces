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

const int mod = 1000000007;
void inc(int& x, int y) { x += y; if (x >= mod) x -= mod; }
void dec(int& x, int y) { if (y != 0) inc(x, mod - y); }
int sum(int x, int y) { inc(x, y); return x; }
int mul(int x, int y) { return (ll(x) * y) % mod; }

const int N = 1011, M = 10011;
int n, a[N], s;
int f[2][M];

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", a+i);
    s += a[i];
  }

  int ans = 0;
  REP(i, n) {
    REP(j, s+1) f[0][j] = f[1][j];
    inc(f[0][s/2], 1);
    CL(f[1], 0);
    FOR(j, a[i], s+1) inc(f[1][j-a[i]], f[0][j]);
    REP(j, s+1-a[i])  inc(f[1][j+a[i]], f[0][j]);
    inc(ans, f[1][s/2]);
  }

  printf("%d\n", ans);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}