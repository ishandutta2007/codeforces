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

const int mod = 1000000007;
void inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }
int add(int x, int y) { inc(x, y); return x; }
int mul(int x, int y) { return (ll(x) * y) % mod; }

const int N = 1002, K = 45;
int C[N+K][K];
int d[2][N][N];
int s[K][N];
int ans[K][N];

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  C[0][0] = 1;
  FOR(i, 1, N+K) {
    C[i][0] = 1;
    FOR(j, 1, K) C[i][j] = add(C[i-1][j-1], C[i-1][j]);
  }

  int (*di)[N] = d[0], (*dp)[N] = d[1];
  REP(k, N) di[0][k] = 1;
  FOR(i, 1, K) {
    swap(di, dp);
    CL(di, 0);
    REP(j, N) {
      di[j][0] = 0;
      FOR(k, 1, j+1) di[j][k] = add(di[j][k-1], mul(dp[j-k][k-1], i));
      FOR(k, j+1, N) di[j][k] = di[j][k-1];
    }
    FOR(j, 1, N) s[i][j] = di[j][j];
  }

  FOR(k, 1, K) FOR(n, k*(k+1)/2, N) {
    FOR(l, k*(k+1)/2, n+1) inc(ans[k][n], mul(s[k][l], C[n-l+k][k]));
  }

  int t, n, k;
  scanf("%d", &t);
  REP(i, t) {
    scanf("%d%d", &n, &k);
    printf("%d\n", k*(k+1) > 2*n ? 0 : ans[k][n]);
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}