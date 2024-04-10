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
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define FORE(e, v) for (int e = head[v]; e >= 0; e = E[e].next)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
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
const double pi = acos(-1.0);

template<class T> T& smin(T& a, const T& b) { if (a > b) a = b; return a; }
template<class T> T& smax(T& a, const T& b) { if (a < b) a = b; return a; }
template<class T> T gcd(T a, T b) {
  if (a < 0) a = -a; if (b < 0) b = -b;
  while (a && b) { if (a >= b) a %= b; else b %= a; } return a + b; }
template<class T> T sqr(const T& a) { return a * a; }

template<typename Iterator> void print(const char* fmt,
    Iterator begin, Iterator end, const char* separator = " ") {
  for (Iterator it = begin; it != end; ++it) {
    if (it != begin) printf("%s", separator);
    printf(fmt, *it);
  }
  printf("\n");
}

const int N = 200022;
int n;
int k[N], l[N], p[N];
int a[N][2], b[N][2];
int q[N];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  p[0] = -1;
  fill(k, k+n, 0);
  REP(i, n-1) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u; --v;
    p[v] = u;
    ++k[u];
  }

  int qa = 0, qb = 0;
  REP(i, n) if (k[i] == 0) {
    q[qb++] = i;
    l[i] = 1;
    REP(t, 2) a[i][t] = b[i][t] = 0;
  } else {
    a[i][0] = -INF;
    a[i][1] = 0;
    b[i][0] = 0;
    b[i][1] = INF;
  }
  for (; qa < qb; ++qa) {
    int v = q[qa];
//    printf("%d: a(%d,%d) b(%d,%d)\n", v+1, a[v][0], a[v][1], b[v][0], b[v][1]);
    if (v == 0) break;
    int u = p[v];
    l[u] += l[v];
    smax(a[u][0], a[v][1] - l[v] + 1);
    a[u][1] += a[v][0];
    b[u][0] += b[v][1] - l[v] + 1;
    smin(b[u][1], b[v][0]);
    --k[u];
    if (k[u] == 0) {
      a[u][0] += l[u] - 1;
      b[u][0] += l[u] - 1;
      q[qb++] = u;
    }
  }

  printf("%d %d\n", a[0][0] + 1, b[0][0] + 1);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}