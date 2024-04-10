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

const int h = 100001;
int n, m;
vi x[h], y[h];
int ans = 0;

bool find(int qx, int qy) {
  return binary_search(all(x[qy]), qx);
}

void solve() {
  REP(u, h) if (!x[u].empty()) sort(all(x[u]));
  REP(u, h) if (!x[u].empty() && sz(x[u]) < m) {
    REP(i, sz(x[u])) FOR(j, i+1, sz(x[u])) {
      int d = x[u][j] - x[u][i];
      if (u >= d  && find(x[u][i], u-d) && find(x[u][j], u-d)) ++ans;
      if (u+d < h && find(x[u][i], u+d) && find(x[u][j], u+d)) ++ans;
    }
    x[u].clear();
  }
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  int a, b;
  scanf("%d", &n);
  m = (int)sqrt(double(n)) + 2;
  REP(i, n) {
    scanf("%d%d", &a, &b);
    x[b].pb(a);
  }
  solve();
  REP(u, h) if (!x[u].empty())
    REP(i, sz(x[u])) y[x[u][i]].pb(u);
  REP(u, h) swap(x[u], y[u]);
  solve();
  printf("%d\n", ans);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}