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
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a%b); }

const int h = 66;
int n,m, r;
int a[h][h][h];
int d[h][h][h];

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d", &n, &m, &r);
  REP(u, m) {
    REP(i, n) REP(j, n) scanf("%d", &a[u][i][j]);
    REP(k, n) REP(i, n) REP(j, n) smin(a[u][i][j], a[u][i][k] + a[u][k][j]);
  }
  REP(i, n) REP(j, n) {
    d[0][i][j] = INF;
    REP(u, m) smin(d[0][i][j], a[u][i][j]);
  }
  REP(k, n) REP(i, n) REP(j, n) {
    d[k+1][i][j] = INF;
    REP(u, n) smin(d[k+1][i][j], d[0][i][u] + d[k][u][j]);
  }
  int s,t, c;
  REP(i, r) {
    scanf("%d%d%d", &s, &t, &c);
    smin(c, n);
    printf("%d\n", d[c][s-1][t-1]);
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}