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
const int N = 1e5;
int n, k, l, a[N], b[N];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &k);
  l = n / k;
  REP(i, l) scanf("%d", a+i);
  REP(i, l) scanf("%d", b+i);
  int ans = 1;
  int t = 1;
  REP(j, k) t *= 10;
  REP(i, l) {
    int x = b[i], y = b[i] + 1;
    REP(j, k-1) x *= 10, y *= 10;
    int m = (t - 1) / a[i] - (y - 1) / a[i];
    if (b[i] != 0) m += (x - 1) / a[i] + 1;
//    printf("%d %d %d\n", (t - 1) / a[i], (y - 1) / a[i], (x - 1) / a[i]);
    ans = ll(ans) * m % mod;
  }
  printf("%d\n", ans);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}