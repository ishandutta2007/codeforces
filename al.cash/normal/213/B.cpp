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
#define REP(i, n) FOR (i, 0, n)
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
template<class T> T sqr(T a) { return a * a; }

template<class T> void outp(const vector<T>& v) {
  REP(i, sz(v)) cout << v[i] << (i + 1 == sz(v) ? '\n' : ' ');
}
template<class T> void outp(T* v, int n) {
  REP(i, n) cout << *v++ << (i + 1 == n ? '\n' : ' ');
}

const int mod = 1000000007;
void inc(int& a, int b) { a += b; if (a >= mod) a -= mod; }
void dec(int& a, int b) { a -= b; if (a < 0) a -= mod; }
int sum(int a, int b) { inc(a, b); return a; }
int mul(int a, int b) { return ll(a) * b % mod; }

const int h = 111;
int C[2*h][h];
int f(int m, int n) {
  if (m < 0) return 0;
  return C[m+n][n];
}

int n, a[10];
int d[11][h];

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  CL(C, 0);
  C[0][0] = 1;
  FOR(i, 1, 2*h) REP(j, h) {
    C[i][j] = C[i-1][j];
    if (j) inc(C[i][j], C[i-1][j-1]);
  }

  scanf("%d", &n);
  FORD(i, 9, 0) scanf("%d", a+i);
  CL(d, 0);
  d[0][0] = 1;
  REP(u, 10) REP(i, n+1) FOR(j, a[u], n-i+1) {
    if (u == 9) inc(d[u+1][i+j], mul(d[u][i], f(i-1, j)));
    else inc(d[u+1][i+j], mul(d[u][i], f(i, j)));
  }
  int ans = 0;
  FOR(i, 1, n+1) inc(ans, d[10][i]);
  printf("%d\n", ans);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
}