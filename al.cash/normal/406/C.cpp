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

const int h = 100011;
int n, m;
vi r[h];

struct Edge {
  int s;
  bool used;
} e[h];

int dfs(int v) {
  vi c;
  REP(i, sz(r[v])) if (!e[r[v][i]].used) {
    c.pb(r[v][i]);
    e[r[v][i]].used = true;
  }
  int l = 0;
  REP(i, sz(c)) {
    int u = e[c[i]].s - v;
    int w = dfs(u);
    if (w == 0) {
      if (l == 0) l = u;
      else {
        printf("%d %d %d\n", l, v, u);
        l = 0;
      }
    } else {
      printf("%d %d %d\n", w, u, v);
    }
  }
  return l;
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  if (m&1) {
    printf("No solution\n");
    return 0;
  }
  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    e[i].s = a + b;
    e[i].used = false;
    r[a].pb(i);
    r[b].pb(i);
  }
  dfs(1);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}