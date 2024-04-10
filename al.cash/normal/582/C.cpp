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

const int N = 2e5+5;
int n, a[N], m[N];
bool y[N];
ll s[N];
vi q[N];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);
//  n = 151200;
//  REP(i, n) a[i] = 1;
  FOR(s, 1, n) {
    int g = __gcd(s, n);
    q[g].pb(s / g);
  }
  ll ans = 0;
  FOR(d, 1, n) if (n % d == 0) {
    REP(i, d) m[i] = 0;
    REP(i, n) smax(m[i%d], a[i]);
    int k = 0;
    REP(i, d) if (a[i] >= m[i]) ++k;
    REP(i, n) {
      y[i] = k == d;
      if (a[i] >= m[i%d]) --k;
      int j = i + d;
      if (j >= n) j -= n;
      if (a[j] >= m[j%d]) ++k;
    }
//    printf("%d:\n", d);
//    print("%d", m, m+d);
//    REP(i, n) printf("%d", (int)y[i]); printf("\n");
    CL(s, 0);
    int o = 0;
    REP(r, d) {
      bool all = true;
      for (int i = r; i < n; i += d) if (!y[i]) {
        all = false;
        break;
      }
      if (all) {
        ++o;
        continue;
      }
      for (int i = r; i < n; i += d) if (y[i]) {
        int l = 1;
        int j = i + d;
        while (j < n && y[j]) j += d, ++l;
        if (i == r) {
          int b = i - d + n;
          while (y[b]) y[b] = false, b -= d, ++l;
        }
        i = j;
//        printf("%d: start %d len %d\n", r, i, l);
        ++s[l];
      }
    }
    k = 0;
    FORD(i, n, 0) {
      k += s[i];
      s[i] = s[i+1] + k;
    }
//    printf("%d: %d\n", d, o);
    for (int v : q[d]) {
//      printf("%d: +%d\n", v * d, (int)(s[v] + o * ll(n / d)));
      ans += s[v] + o * ll(n / d);
    }
//    REP(i, n) printf("%d", y[i]); printf("\n");
  }
  cout << ans << endl;

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}