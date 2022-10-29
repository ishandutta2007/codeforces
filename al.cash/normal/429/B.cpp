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

const int h = 1001;
int n, m;
int a[h][h];
int d00[h][h], d0m[h][h], dn0[h][h], dnm[h][h];

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  REP(i, n) REP(j, m) scanf("%d", &a[i][j]);

  REP(i, n) REP(j, m) {
    d00[i][j] = 0;
    if (i > 0) smax(d00[i][j], d00[i-1][j]);
    if (j > 0) smax(d00[i][j], d00[i][j-1]);
    d00[i][j] += a[i][j];
  }
  REP(i, n) FORD(j, m-1, 0) {
    d0m[i][j] = 0;
    if (i > 0) smax(d0m[i][j], d0m[i-1][j]);
    if (j < m-1) smax(d0m[i][j], d0m[i][j+1]);
    d0m[i][j] += a[i][j];
  }
  FORD(i, n-1, 0) REP(j, m) {
    dn0[i][j] = 0;
    if (i < n-1) smax(dn0[i][j], dn0[i+1][j]);
    if (j > 0) smax(dn0[i][j], dn0[i][j-1]);
    dn0[i][j] += a[i][j];
  }
  FORD(i, n-1, 0) FORD(j, m-1, 0) {
    dnm[i][j] = 0;
    if (i < n-1) smax(dnm[i][j], dnm[i+1][j]);
    if (j < m-1) smax(dnm[i][j], dnm[i][j+1]);
    dnm[i][j] += a[i][j];
  }

  int ans = 0;
  FOR(i, 1, n-1) FOR(j, 1, m-1) {
    smax(ans, d00[i-1][j] + dn0[i][j-1] + dnm[i+1][j] + d0m[i][j+1]);
    smax(ans, d0m[i-1][j] + d00[i][j-1] + dn0[i+1][j] + dnm[i][j+1]);
  }
  printf("%d\n", ans);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}