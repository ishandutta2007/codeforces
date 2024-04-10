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

const int h = 301;
int n, a[h][h];
int d[2*h][h][h];

inline void upd(int s, int i, int j, int v) {
  if (max(i, s-i) <= min(s, n-1) && max(j, s-j) <= min(s, n-1)) {
    if (i == j) smax(d[s][i][j], v + a[i][s-i]);
    else smax(d[s][i][j], v + a[i][s-i] + a[j][s-j]);
  }
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) REP(j, n) scanf("%d", &a[i][j]);
  REP(s, 2*h) REP(i, h) REP(j, h) d[s][i][j] = -INF;
  d[0][0][0] = a[0][0];
  REP(s, 2*n-2) FOR(i, max(0, s+1-n), min(s+1, n))
    FOR(j, max(0, s+1-n), min(s+1, n)) {
    //printf("%d %d %d: %d\n", s, i, j, d[s][i][j]);
    int v = d[s][i][j];
    upd(s+1, i, j, v);
    upd(s+1, i+1, j, v);
    upd(s+1, i+1, j+1, v);
    upd(s+1, i, j+1, v);
  }
  printf("%d\n", d[2*n-2][n-1][n-1]);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
}