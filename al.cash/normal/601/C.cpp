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

const int N = 101, M = 1001;
int n, m, x[N];
double p[N][N*M];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  if (m == 1) {
    printf("1\n");
    return 0;
  }
  REP(i, n) scanf("%d", x+i);
//  n = 100; m = 1000;
//  REP(i, n) x[i] = 320;
  p[0][0] = 1;
  REP(i, n) {
    double s = 0;
    FOR(j, 1, (i+1)*m+1) {
      s += p[i][j-1];
      if (j > m) s -= p[i][j-m-1];
      if (j > x[i]) s += p[i][j-x[i]-1];
      if (j >= x[i]) s -= p[i][j-x[i]];
      p[i+1][j] = s / (m - 1);
    }
//    print("%lf", p[i+1], p[i+1] + (i+1)*m+1);
  }
  int sx = 0;
  REP(i, n) sx += x[i];
  double ans = 0;
  REP(j, sx) ans += p[n][j];
  printf("%.12lf\n", 1 + ans * (m - 1));

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}