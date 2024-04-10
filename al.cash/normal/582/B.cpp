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

const int N = 111;
int n, t, a[N*N], d[N*N], de[N*N];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &t);
  REP(i, n) scanf("%d", a+i);
  int m = min(t, n);
  FOR(i, n, n*m) a[i] = a[i%n];
  REP(i, n*m) {
    d[i] = 0;
    REP(j, min(n, i)+1) if (a[i-j] <= a[i]) smax(d[i], d[i-j]);
    d[i]++;
  }
  int me = min(n, t-m);
  FORD(i, n*me-1, 0) {
    de[i] = 0;
    REP(j, n+1) if (i+j < n*me && a[i+j] >= a[i]) smax(de[i], de[i+j]);
    de[i]++;
  }
  int ans = 0;
  FOR(i, n*(m-1), n*m) {
    int k = 0;
    REP(j, n) if (a[i] == a[j]) ++k;
    smax(ans, d[i] + k * (t - m));
    if (me > 0) REP(j, n) if (a[j] == a[i]) smax(ans, d[i] + de[j] + k * (t - m - me));
  }
  printf("%d\n", ans);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}