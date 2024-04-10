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

typedef pair<ll, int> pli;

const int N = 150015;
int n, m, d;
int a, b, t;

ll x[2][N];
ll *x0, *x1;

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d", &n, &m, &d);
  x0 = x[0];
  x1 = x[1];
  int tp = 0;
  REP(i, m) {
    scanf("%d%d%d", &a, &b, &t);
    int l = min(ll(t - tp) * d, (ll)n-1);
    tp = t;
    deque<pli> w;
    REP(i, n+l) {
      if (i < n) {
        while (!w.empty() && w.back().X <= x0[i]) w.pop_back();
        w.pb(pli(x0[i], i));
      }
      if (i >= l) {
        while (w.front().Y < i - 2*l) w.pop_front();
        x1[i-l] = w.front().X;
      }
    }
    REP(i, n) x1[i] += b - abs(a - i - 1);
    //print("% 4d", x1, x1+n);
    swap(x0, x1);
  }

  ll ans = x0[0];
  REP(i, n) smax(ans, x0[i]);
  cout << ans << endl;

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}