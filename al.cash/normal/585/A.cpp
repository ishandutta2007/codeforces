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

const int N = 4004;
int n, v[N], d[N], p[N];
vector<pii> q;
vi r, ans;

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) scanf("%d%d%d", v+i, d+i, p+i);
  REP(i, n) q.eb(i, 0);
  while (!q.empty()) {
    pii qt = q[0];
    q.erase(q.begin());
    ans.pb(qt.X + 1);
    r.clear();
    for (int i = 0, x = v[qt.X]; i < sz(q) && x > 0; ++i, --x) {
      int u = q[i].X;
      if (q[i].Y != 0) continue;
      p[u] -= x;
      if (p[u] < 0) q[i].Y = 1, r.pb(u);
    }
    for (int ra = 0; ra < sz(r); ++ra) {
      int t = r[ra], i = 0;
      while (q[i].X != t) ++i;
      q.erase(q.begin() + i);
//      printf("%d:\n", t);
//      REP(i, sz(q)) printf("%d %d\n", q[i].X, q[i].Y);
      for (int x = d[t]; i < sz(q); ++i) {
        int u = q[i].X;
        if (q[i].Y != 0) continue;
        p[u] -= x;
        if (p[u] < 0) q[i].Y = 1, r.pb(u);
      }
    }
//    REP(i, sz(q)) printf("%d %d\n", q[i].X, q[i].Y);
//    print("%d", p, p+n);
  }
  printf("%d\n", sz(ans));
  print("%d", all(ans));

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}