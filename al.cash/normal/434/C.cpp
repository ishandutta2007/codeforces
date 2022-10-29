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
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T> T sqr(T a) { return a * a; }

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
    const char* separator = " ") {
  for (Iterator it = begin; it != end; ++it) {
    if (it != begin) printf(separator);
    printf(fmt, *it);
  }
  printf("\n");
}

const int mod = 1000000007;
void inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }
int add(int x, int y) { inc(x, y); return x; }
int mul(int x, int y) { return (ll(x) * y) % mod; }

void dec(int &x, int y) { x -= y; if (x < 0) x += mod; }
int sub(int x, int y) { dec(x, y); return x; }

template<int N, int A>
struct AhoCorasick {
  int t[N][A], nv;
  int end[N];
  int link[N], q[N];  // after build q - link to v with end = true

  int addv() {
    CL(t[nv], 0);
    end[nv] = false;
    return nv++;
  }

  void init() {
    nv = 0;
    addv();
  }

  void add_string(const vi& s, int val) {
    int v = 0;
    REP(i, sz(s)) {
      int c = s[i];
      if (!t[v][c]) t[v][c] = addv();
      v = t[v][c];
    }
    end[v] += val;
  }

  void build() {
    q[0] = 0;
    link[0] = 0;
    for (int qa = 0, qb = 1; qa < qb; ++qa) {
      int v = q[qa];
      end[v] += end[link[v]];
      REP(i, A)
        if (t[v][i]) {
          int u = link[v];
          while (u != 0 && !t[u][i]) u = link[u];
          link[t[v][i]] = v == 0 ? 0 : t[u][i];
          q[qb++] = t[v][i];
        } else t[v][i] = t[link[v]][i];
    }
//    q[0] = 0;
//    FOR(v, 1, nv) q[v] = end[v] ? v : q[link[v]];
  }
};

const int N = 201, M = 20, K = 501;
int n, m, k;
vi l, r, w;

void inp(vi& v) {
  int k;
  scanf("%d", &k);
  v.resize(k);
  REP(i, k) scanf("%d", &v[i]);
}

AhoCorasick<N, M> ac;

int de[2][N][K], dl[2][N][K];

int f(const vi& v) {
  int (*dec)[K] = de[0], (*dep)[K] = de[1];
  int (*dlc)[K] = dl[0], (*dlp)[K] = dl[1];
  REP(i, ac.nv) REP(j, k+1) dec[i][j] = dlc[i][j] = 0;
  REP(o, sz(v)) {
    swap(dec, dep);
    swap(dlc, dlp);
    REP(i, ac.nv) REP(j, k+1) dec[i][j] = dlc[i][j] = 0;
    REP(i, ac.nv) REP(j, k+1) inc(dec[ac.t[i][v[o]]][j], dep[i][j]);
    REP(u, v[o]) {
      REP(i, ac.nv) REP(j, k+1) inc(dlc[ac.t[i][u]][j], dep[i][j]);
    }
    REP(u, m) {
      REP(i, ac.nv) REP(j, k+1) inc(dlc[ac.t[i][u]][j], dlp[i][j]);
    }

    if (o == 0) {
      inc(dec[ac.t[0][v[o]]][0], 1);
      FOR(u, 1, v[o]) inc(dlc[ac.t[0][u]][0], 1);
    } else {
      FOR(u, 1, m) inc(dlc[ac.t[0][u]][0], 1);
    }

    REP(i, ac.nv) FORD(j, k+1, 0) {
      int x = j + ac.end[i];
      if (x <= k && x != j) {
        inc(dec[i][x], dec[i][j]);
        inc(dlc[i][x], dlc[i][j]);
      }
      if (x != j) {
        dec[i][j] = 0;
        dlc[i][j] = 0;
      }
    }

//    printf("%d:\n", o);
//    REP(i, ac.nv) print("%d", dec[i], dec[i]+k+1); printf("\n");
//    REP(i, ac.nv) print("%d", dlc[i], dlc[i]+k+1); printf("\n");
  }
  int ans = 0;
  REP(i, ac.nv) REP(j, k+1) {
    inc(ans, dec[i][j]);
    inc(ans, dlc[i][j]);
  }
//  print("%d", all(v));
//  printf("%d\n", ans);
  return ans;
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d", &n, &m, &k);
  inp(l);
  int u = sz(l)-1;
  while (l[u] == 0) l[u--] = m-1;
  --l[u];
  while (!l.empty() && l[0] == 0) l.erase(l.begin());
  inp(r);

  ac.init();
  REP(i, n) {
    inp(w);
    int v;
    scanf("%d", &v);
    ac.add_string(w, v);
  }
  ac.build();
//  REP(i, ac.nv) printf("%d ", ac.end[i]); printf("\n");

  printf("%d\n", sub(f(r), f(l)));

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}