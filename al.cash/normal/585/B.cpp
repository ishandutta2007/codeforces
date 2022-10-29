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
           const char* delimiter = " ", const char* closing = "\n") {
  for (; begin != end; ++begin != end ? printf("%s", delimiter) : 0)
    printf(fmt, *begin);
  printf("%s", closing);
}

const int N = 111, K = 27, R = 3;
int n, k;
char s[3][N];
vector<pii> q;
bool us[3][N];

bool solve() {
  q.clear();
  REP(i, R) if (s[i][0] == 's') {
    q.eb(i, 0);
    us[i][0] = true;
    s[i][0] = '.';
  }
  CL(us, 0);
  for (int qa = 0; qa < sz(q); ++qa) {
    pii p = q[qa];
    int i = p.X, j = p.Y;
//    printf("%d %d\n", i, j);
    ++j;
    if (j >= n) return true;
    if (s[i][j] != '.') continue;
    FOR(d, -1, 2) {
      int u = i + d;
      if (u < 0 || u >= R) continue;
      bool ok = true;
      REP(m, 3) {
        if (j + m >= n) return true;
        if (s[u][j+m] != '.') {
          ok = false;
          break;
        }
      }
      if (ok && !us[u][j+2]) {
        us[u][j+2] = true;
        q.eb(u, j+2);
      }
    }
  }
  return false;
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  int t;
  for (scanf("%d", &t); t--; ) {
    scanf("%d%d", &n, &k);
    REP(i, R) scanf("%s", s+i);
    printf("%s\n", solve() ? "YES" : "NO");
  }

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}