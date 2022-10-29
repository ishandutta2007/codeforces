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
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
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

const int N = 200022;
int n, m, k;
int s[N], l[N], ua[N], ub[N];

int t[2*2*N];

void add(int x, int v) {
  x += k;
  while (x > 0) {
    t[x] += v;
    x >>= 1;
  }
}

int sum(int x, int y) {
  int res = 0;
  for (x += k, y += k; x <= y; x = x+1>>1, y = y-1>>1) {
    if (x&1) res += t[x];
    if (~y&1) res += t[y];
  }
  return res;
}

vi r[N];

void dfs(int v, int cl) {
  if (l[v] != -1) return;
  l[v] = cl;
  ua[v] = k++;
  REP(i, sz(r[v])) dfs(r[v][i], cl+1);
  ub[v] = k++;
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%d", s+i);
  int a, b;
  REP(i, n-1) {
    scanf("%d%d", &a, &b);
    --a;
    --b;
    r[a].pb(b);
    r[b].pb(a);
  }

  k = 0;
  CL(t, 0);
  CL(l, -1);
  dfs(0, 0);

  REP(i, m) {
    scanf("%d%d", &a, &b);
    --b;
    if (a == 1) {
      int v;
      scanf("%d", &v);
      if (l[b]&1) v = -v;
      add(ua[b], v);
      add(ub[b], -v);
    } else {
      printf("%d\n", s[b] + sum(0, ua[b]) * ((l[b]&1) ? -1 : 1));
    }
//    outp(t, 2*k);
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}