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
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define FORE(e, v) for (int e = head[v]; e >= 0; e = E[e].next)
#define UN(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
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
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T> T sqr(T a) { return a * a; }

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
    const char* separator = " ") {
  for (Iterator it = begin; it != end; ++it) {
    if (it != begin) printf(separator);
    printf(fmt, *it);
  }
  printf("\n");
}

const int h = 100001;
int n, m;
int a[h];
vi r[h];

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  REP(i, m) scanf("%d", a+i);
  ll sum = 0, ans = INF_LL;
  REP(i, m-1) if (a[i] != a[i+1]) {
    sum += abs(a[i+1] - a[i]);
    r[a[i]].pb(a[i+1]);
    r[a[i+1]].pb(a[i]);
  }
  FOR(i, 1, n+1) if (!r[i].empty()) {
    sort(all(r[i]));
    ll cur = sum;
    ll x = r[i][sz(r[i])/2];
    REP(j, sz(r[i])) cur += abs(x - r[i][j]) - abs(i - r[i][j]);
    smin(ans, cur);
    //cout << i << ' ' << cur << endl;
  }
  if (ans == INF_LL) ans = 0;
  cout << ans << endl;

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}