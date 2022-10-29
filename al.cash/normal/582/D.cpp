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

const int mod = 1e9+7;
void inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }
int add(int x, int y) { inc(x, y); return x; }
int mul(int x, int y) { return (ll(x) * y) % mod; }

void dec(int &x, int y) { x -= y; if (x < 0) x += mod; }
int sub(int x, int y) { dec(x, y); return x; }

const int N = 3500, base = 1e9;
int p, alpha;
char s[N];
vi a, b;

int fe(int s, bool nr) {
  return nr ? p - fe(s, 0) : s + 1;
}

int fl(int s) {
   if (s&1) return mul(s, (s + 1) / 2);
   else return mul(s + 1, s / 2);
}

int fl(int s, bool r, bool nr) {
  int res = fl(s - r);
  return nr ? sub(mul(s, p), res) : res;
}

int dp[N][N][4];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%s", &p, &alpha, s);
  for (int l = strlen(s), i = 0, v = 0; i < l; ++i) {
    v = 10 * v + s[i] - '0';
    if ((l - i) % 9 == 1) a.pb(v), v = 0;
  }
  reverse(all(a));
  do {
    ll r = 0;
    FORD(i, sz(a)-1, 0) {
      r = base * r + a[i];
      a[i] = r / p;
      r %= p;
    }
    b.pb(r);
    while (!a.empty() && a.back() == 0) a.pop_back();
  } while (!a.empty());

  int n = sz(b);
  if (alpha > n) {
    printf("0\n");
    return 0;
  }

  reverse(all(b));
  dp[0][0][2] = 1;
  REP(i, n) REP(j, alpha+1) REP(m, 4) if (dp[i][j][m]) REP(r, 2) {
    int v = dp[i][j][m];
    int jj = min(j + r, alpha);
    if (m&2) {
      if (b[i] > 0) inc(dp[i+1][jj][r], mul(fl(b[i], r, m&1), v));
      inc(dp[i+1][jj][r|2], mul(fe(b[i]-r, m&1), v));
    } else {
      inc(dp[i+1][jj][r], mul(fl(p, r, m&1), v));
    }
  }

  printf("%d\n", add(dp[n][alpha][0], dp[n][alpha][2]));

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}