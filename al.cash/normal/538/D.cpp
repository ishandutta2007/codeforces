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

const int N = 55;
int n;
char b[N][N];
char m[N*2][N*2];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) scanf("%s", b[i]);
  int c = n - 1;
  REP(x, 2*n-1) REP(y, 2*n-1) m[x][y] = 'x';
  m[c][c] = 'o';

  REP(i, n) REP(j, n) if (b[i][j] == 'o') {
    REP(u, n) REP(v, n) if (b[u][v] == '.') m[c+u-i][c+v-j] = '.';
  }

  REP(i, n) REP(j, n) if (b[i][j] == 'o') {
    REP(u, n) REP(v, n) if (b[u][v] == 'x') {
      if (m[c+u-i][c+v-j] == 'x') b[u][v] = '.';
    }
  }
//  REP(i, n) printf("%s\n", b[i]);

  bool ok = true;
  REP(i, n) REP(j, n) if (b[i][j] == 'x') ok = false;

  if (ok) {
    printf("YES\n");
    REP(i, 2*n-1) printf("%s\n", m[i]);
  } else {
    printf("NO\n");
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}