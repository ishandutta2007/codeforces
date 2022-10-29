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

const int h = 5005;
int n;
vi r[h];

bool ok[h], y[h];

int f(int v, int pr) {
  int res = 1;
  REP(i, sz(r[v])) {
    int u = r[v][i];
    if (u != pr) res += f(u, v);
  }
  return res;
}

void calc(int v) {
  CL(y, 0);
  y[0] = 1;
  REP(i, sz(r[v])) {
    int x = f(r[v][i], v);
    FORD(j, n-1, x) y[j] |= y[j-x];
  }
  REP(j, n) ok[j] |= y[j];
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
  CL(ok, 0);
  REP(i, n) calc(i);
  int k = 0;
  FOR(i, 1, n-1) if (ok[i]) ++k;
  printf("%d\n", k);
  FOR(i, 1, n-1) if (ok[i]) printf("%d %d\n", i, n-i-1);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
}