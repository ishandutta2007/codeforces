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

const int h = 202;
int n, k;
int a[h];

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &k);
  REP(i, n) scanf("%d", a+i);
  vi x, y;
  int ans = -INF;
  REP(i, n) FOR(j, i+1, n+1) {
    x.clear();
    y.clear();
    FOR(u, i, j) x.pb(a[u]);
    REP(u, i) y.pb(a[u]);
    FOR(u, j, n) y.pb(a[u]);
    sort(all(x));
    sort(all(y));
    reverse(all(y));
    int m = min(k, min(sz(x), sz(y)));
    int t = 0;
    FOR(u, m, sz(x)) t += x[u];
    int ux = m-1, uy = 0;
    REP(u, m) {
      if (x[ux] > y[uy]) t += x[ux--];
      else t += y[uy++];
    }
    smax(ans, t);
  }
  printf("%d\n", ans);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}