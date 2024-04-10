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
const ll INF_LL = 8e18;
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

const int N = 1e5+5;
int n, k;
bool us[N];
pii x[N], y[N];

ll f(int d) { return max(1, (d + 1) / 2); }

ll goy(int k) {
  ll ans = INF_LL;
  int il = 0;
  REP(l, k+1) {
    while (us[y[il].Y]) ++il;
    int ir = n;
    REP(r, k-l+1) {
      --ir;
      while (us[y[ir].Y]) --ir;
    }
//    printf("y: %d %d\n", y[il].X, y[ir].X);
    smin(ans, f(y[ir].X - y[il].X));
    ++il;
  }
  return ans;
}

ll gox() {
  ll ans = INF_LL;
  REP(l, k+1) {
    if (l) us[x[l-1].Y] = true;
    REP(r, k-l+1) {
      if (r) us[x[n-r].Y] = true;
//      printf("x: %d %d (k = %d)\n", x[l].X, x[n-r-1].X, k - l - r);
      smin(ans, f(x[n-r-1].X - x[l].X) * goy(k - l - r));
    }
    FORD(r, k-l, 1) us[x[n-r].Y] = false;
  }
  FORD(l, k+1, 1) us[x[l-1].Y] = false;
  return ans;
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &k);
  REP(i, n) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x[i] = {x1 + x2, i};
    y[i] = {y1 + y2, i};
  }
  sort(x, x+n);
  sort(y, y+n);
  cout << gox() << endl;

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}