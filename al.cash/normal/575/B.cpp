#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define eb emplace_back
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1e9;
const ll INF_LL = 4e18;
const double pi = acos(-1.0);

template<class T> T& smin(T& a, const T& b) { if (a > b) a = b; return a; }
template<class T> T& smax(T& a, const T& b) { if (a < b) a = b; return a; }
template<class T> T sqr(const T& a) { return a * a; }

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
           const char* separator = " ", const char* closing = "\n") {
  for (Iterator it = begin; it != end; printf(fmt, *it),
       printf("%s", ++it == end ? closing : separator));
}

const int N = 1e5+5, K = 1e6+6;
int n, k;
vector<pii> e[N];
vi s[N], t[N];
int cur = 0;
int a[N], b[N];

void dfs0(int v, int p) {
  a[v] = cur;
  for (auto u : e[v]) if (u.X != p) dfs0(u.X, v);
  b[v] = cur++;
}

const int mod = 1e9+7;
void inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }
int add(int x, int y) { inc(x, y); return x; }
int mul(int x, int y) { return (ll(x) * y) % mod; }

void dec(int &x, int y) { x -= y; if (x < 0) x += mod; }
int sub(int x, int y) { dec(x, y); return x; }

int p2[K];
int ans = 0;

vi st, ks, kt;

void add(vi& kk, int u) {
  int l = 0, r = sz(st);
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (a[st[m]] <= b[u] && b[u] <= b[st[m]]) l = m;
    else r = m;
  }
//  printf("%d: --kk[%d]\n", u, l);
  --kk[l];
}

void dfs(int v, int p, int w) {
//  printf("%d:\n", v);
  st.pb(v);
  ks.pb(sz(s[v]));
  kt.pb(sz(t[v]));
  for (int u : s[v]) add(ks, u);
  for (int u : t[v]) add(kt, u);

  for (auto u : e[v]) if (u.X != p) dfs(u.X, v, u.Y);
  st.pop_back();
  int ts = ks.back();
  ks.pop_back();
  int tt = kt.back();
  kt.pop_back();
  if (p != -1) {
//    printf("%d (%d, %d): %d %d\n", v, p, w, ts, tt);
    if (~w&1) inc(ans, p2[ts]);
    if (~w&2) inc(ans, p2[tt]);
    ks.back() += ts;
    kt.back() += tt;
  }
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  p2[0] = 1;
  FOR(i, 1, K) p2[i] = mul(p2[i-1], 2);
  REP(i, K) dec(p2[i], 1);

  scanf("%d", &n);
  REP(i, n-1) {
    int a, b, x;
    scanf("%d%d%d", &a, &b, &x);
    if (x == 0) {
      e[a].eb(b, 3);
      e[b].eb(a, 3);
    } else {
      e[a].eb(b, 1);
      e[b].eb(a, 2);
    }
  }

  int p = 1;
  scanf("%d", &k);
  REP(i, k) {
    int a;
    scanf("%d", &a);
    t[p].pb(a);
    s[a].pb(p);
    p = a;
  }

  dfs0(1, -1);
//  FOR(i, 1, n+1) printf("%d %d\n", a[i], b[i]);
  dfs(1, -1, 0);
  printf("%d\n", ans);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}