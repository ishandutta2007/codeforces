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

const int N = 1e5+5;
int n, q, a[N], d[N];
typedef pair<int, ll> pil;
vector<pil> s;

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &q);
  REP(i, n) scanf("%d", a+i);
//  n = 100000; q = 100;
//  REP(i, n) a[i] = rand() % int(1e8+1);
  REP(i, n) d[i+1] = abs(a[i] - a[i+1]);
  s.reserve(n);
  REP(u, q) {
    int l, r;
    scanf("%d%d", &l, &r);
//    l = 1, r = n;
    s.clear();
    s.pb({l-1, 0});
    ll ans = 0;
    FOR(i, l, r) {
      while (sz(s) > 1 && d[s.back().X] < d[i]) s.pop_back();
      ll cur = s.back().Y + d[i] * ll(i - s.back().X);
      s.eb(i, cur);
//      printf("%d: ", i);
//      for (auto p : s) printf("%d,%lld ", p.X, p.Y);
//      printf("\n");
      ans += cur;
    }
    cout << ans << endl;
  }

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}