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

const int h = 42;
int n, m, q;
char s[h][h];
int a, b, c, d;

int z[h][h];
int g[h][h][h][h];

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d", &n, &m, &q);
  REP(i, n) scanf("%s", s+i);

  REP(i, n) REP(j, m) if (s[i][j] == '0')
    z[i][j] = i == 0 ? 1 : z[i-1][j] + 1;

  REP(i0, n) REP(j0, m) {
    FOR(i, i0, n) FOR(j, j0, m) {
      g[i0][j0][i+1][j+1] = g[i0][j0][i][j+1] + g[i0][j0][i+1][j]
                            - g[i0][j0][i][j];
      int w = i - i0 + 1;
      FORD(a, j, j0) {
        if (s[i][a] == '1') break;
        smin(w, z[i][a]);
        g[i0][j0][i+1][j+1] += w;
      }
    }
  }

  REP(u, q) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d\n", g[a-1][b-1][c][d]);
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}