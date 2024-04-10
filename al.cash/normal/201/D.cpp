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

const int h = 500005, N = 15;
int n, pm, m, k;
char s[N];
vi a;
int r[h][N];
int d[1<<N][N*(N-1)/2+1];

const int V = 15*10*2;
int t[V][26], p[V], nv = 1;

int solve() {
  k = sz(a);
  if(k==0) return -1;
  REP(i, n) r[k][i] = k;
  FORD(j, k-1, 0) {
    REP(i, n) r[j][i] = r[j+1][i];
    r[j][a[j]] = j;
  }
  REP(u, 1<<n) REP(c, pm+1) d[u][c] = k;
  d[0][0] = 0;
  REP(u, (1<<n)-1) REP(c, pm+1) if(d[u][c] != k) {
    int l = 0;
    REP(i, n) if(u&1<<i) ++l;
    REP(i, n)
      if(~u&1<<i) smin(d[u|1<<i][c+l], r[d[u][c]][i]);
      else --l;
  }
  REP(c, pm+1) if(d[(1<<n)-1][c] != k) return pm - c + 1;
  return -1;
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  pm = n*(n-1)/2;
  REP(i, n) {
    scanf("%s", s);
    int v = 0;
    REP(c, strlen(s)) {
      int e = s[c] - 'a';
      if(!t[v][e]) t[v][e] = nv++;
      v = t[v][e];
    }
    p[v] = i + 1;
  }
  int pr, ans = 0;
  scanf("%d", &m);
  REP(im, m) {
    scanf("%d", &k);
    a.clear();
    REP(j, k) {
      scanf("%s", s);
      int v = 0;
      REP(c, strlen(s)) {
        int e = s[c] - 'a';
        v = t[v][e];
        if(!v) break;
      }
      if(p[v]) a.pb(p[v]-1);
    }
    int cur = solve();
    if (cur > ans) ans = cur, pr = im + 1;
  }
  if (!ans) printf("Brand new problem!\n");
  else {
    printf("%d\n", pr);
    printf("[:");
    REP(i, ans) printf("|");
    printf(":]\n");
  }

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
}