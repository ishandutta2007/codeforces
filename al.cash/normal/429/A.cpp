#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cmath>
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

const int h = 100011;
int n;
vi r[h];

int s[h], g[h];
vi ans;

void dfs(int v, int pr, bool sw, bool swp) {
  if (sw) s[v] = 1-s[v];
  if (s[v] != g[v]) {
    ans.pb(v+1);
    sw = !sw;
  }
  REP(i, sz(r[v])) if (r[v][i] != pr)
    dfs(r[v][i], v, swp, sw);
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  int a, b;
  REP(i, n-1) {
    scanf("%d%d", &a, &b);
    --a;
    --b;
    r[a].pb(b);
    r[b].pb(a);
  }
  REP(i, n) scanf("%d", s+i);
  REP(i, n) scanf("%d", g+i);
  dfs(0, -1, false, false);
  printf("%d\n", sz(ans));
  REP(i, sz(ans)) printf("%d\n", ans[i]);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}