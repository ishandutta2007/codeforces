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
#define FOR(i, a, b) for(int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i(a), _b(b); i >= _b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;

const int h = 100011, T = 20;

int n, m, k;
vi r[h];
int t[h], mn[h], c[h];

int tt;
bool us[h];

void dfs(int v, int pr) {
  us[v] = true;
  t[v] = mn[v] = tt++;
  c[v] = v;
  REP(i, sz(r[v])) {
    int u = r[v][i];
    if (!us[u]) dfs(u, v);
    if (u != pr && mn[u] < mn[v]) {
      mn[v] = mn[u];
      c[v] = c[u];
    }
  }
}

vi g[h];
int l[h], p[h][T];

void dfsp(int v, int pr) {
  l[v] = pr==-1 ? 0 : l[pr] + 1;
  p[v][0] = pr;
  REP(i, T-1) {
    if (p[v][i] == -1) break;
    p[v][i+1] = p[p[v][i]][i];
  }
  REP(i, sz(g[v])) if(g[v][i] != pr) dfsp(g[v][i], v);
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  int a,b;
  REP(i, m) {
    scanf("%d%d", &a, &b);
    --a;
    --b;
    r[a].pb(b);
    r[b].pb(a);
  }
  CL(us, 0);
  tt = 0;
  dfs(0, -1);
  REP(v, n) {
    int u = v;
    vi l;
    while(c[u] != u) {
      l.pb(u);
      u = c[u];
    }
    REP(i, sz(l)) c[l[i]] = u;
  }
  //REP(v, n) printf("%d ", c[v]); printf("\n");
  REP(v, n) REP(i, sz(r[v])) {
    int u = r[v][i];
    if (c[u] != c[v]) g[c[v]].pb(c[u]);
  }
  REP(v, n) {
    sort(all(g[v]));
    g[v].resize(unique(all(g[v])) - g[v].begin());
  }
//  REP(v, n) if(!g[v].empty()) {
//    printf("%d: ", v);
//    REP(i, sz(g[v])) printf("%d ", g[v][i]);
//    printf("\n");
//  }
  CL(p, -1);
  dfsp(0, -1);

  scanf("%d", &k);
  REP(kk, k) {
    scanf("%d%d", &a, &b);
    a = c[a-1];
    b = c[b-1];

    int res = 0;
    if (l[a] < l[b]) swap(a, b);
    FORD(i, T-1, 0) if (l[a] - (1<<i) >= l[b]) {
      a = p[a][i];
      res += 1<<i;
    }
    FORD(i, T-1, 0) {
      if (p[a][i] != p[b][i]) {
        a = p[a][i];
        b = p[b][i];
        res += 1<<(i+1);
      }
    }
    if (a != b) res += 2;
    printf("%d\n", res);
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}