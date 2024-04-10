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

const int N = 22;
int n;
int a[N][N], b[N][N];
int E[N][N];

int p2[N], way[N];
int u[N], v[N], minv[N];
bool used[N];
int ans;

void go(int i, int ka, int kb) {
//  printf("%d %d,%d: %d\n", i, ka, kb, v[0]);
  if (i == n) {
    smax(ans, v[0]);
    return;
  }
  REP(what, 2) {
    if (what == 0 && ka == n/2) continue;
    if (what == 1 && kb == n/2) continue;
    int pp2[N], pway[N], pu[N], pv[N];
    REP(j, n+1) {
      pp2[j] = p2[j];
      pway[j] = way[j];
      pu[j] = u[j];
      pv[j] = v[j];
    }
    REP(j, n) E[i][j] = what == 0 ? a[i][j] : b[i][j];

    fill_n(minv, n+1, INF);
    fill_n(used, n+1, 0);
    int j0 = 0;
    p2[0] = i+1;
    do {
      used[j0] = true;
      int i0 = p2[j0], j1 = 0;
      int delta = INF;
      FOR(j, 1, n+1) if (!used[j]) {
        int cur = E[i0-1][j-1] - u[i0] - v[j];
        if (cur < minv[j]) minv[j] = cur, way[j] = j0;
        if (minv[j] < delta) delta = minv[j], j1 = j;
      }
      REP(j, n+1) {
        if (used[j]) u[p2[j]] += delta, v[j] -= delta;
        else minv[j] -= delta;
      }
      j0 = j1;
    } while (p2[j0] != 0);
    do {
      p2[j0] = p2[way[j0]];
      j0 = way[j0];
    } while (j0);
    go(i+1, ka + (what == 0), kb + (what == 1));

    REP(j, n+1) {
      p2[j] = pp2[j];
      way[j] = pway[j];
      u[j] = pu[j];
      v[j] = pv[j];
    }
  }
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) REP(j, n) scanf("%d", a[i]+j);
  REP(i, n) REP(j, n) scanf("%d", b[i]+j);
  REP(i, n) REP(j, n) {
    a[i][j] = -a[i][j];
    b[i][j] = -b[i][j];
  }
  go(0, 0, 0);
  printf("%d\n", ans);
  
#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}