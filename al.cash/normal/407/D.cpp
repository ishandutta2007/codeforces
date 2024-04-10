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

const int h = 404;
int n, m;
int a[h][h];
short u[h*h][h], t[h][h];

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  FOR(i, 1, n+1) REP(j, m) scanf("%d", a[i]+j);
  int ans = 0;
  FOR(i, 1, n+1) {
    REP(j, m) smax(t[j][j], u[a[i][j]][j]);
    FOR(k, 1, m) {
      REP(l, m-k) {
        int r = l + k;
        if (a[i][l] == a[i][r]) t[l][r] = i;
        else {
          smax(t[l][r], t[l+1][r]);
          smax(t[l][r], t[l][r-1]);
          smax(t[l][r], u[a[i][l]][r]);
          smax(t[l][r], u[a[i][r]][l]);
        }
      }
    }
    REP(l, m) FOR(r, l, m) smax(ans, (r - l + 1) * (i - t[l][r]));
//    printf("%d:\n", i);
//    REP(l, m) outp(t[l]+l, m-l);
    REP(j, m) u[a[i][j]][j] = i;
  }
  printf("%d\n", ans);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}