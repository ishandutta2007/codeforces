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

int n;
ll l, r;

typedef pair<int, ll> pil;

vi dl, dr, dt;

void calc(ll x, vi& dx) {
  dx.clear();
  while (x) {
    dx.pb(x&1);
    x >>= 1;
  }
}

ll dton(const vi& dx) {
  ll x = 0;
  FORD(i, sz(dx)-1, 0) x = x << 1 | dx[i];
  return x;
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(it, n) {
    scanf("%I64d%I64d", &l, &r);
    calc(l, dl);
    calc(r, dr);
    int m = sz(dr);
    while (m > sz(dl)) dl.pb(0);
    pil ans(0, 0);
    dt.resize(m);
    int k = 0;
    FORD(i, m-1, 0) {
      if (dl[i] == dr[i]) {
        dt[i] = dl[i];
        k += dt[i];
      } else {
        dt[i] = 0;
        REP(j, i) dt[j] = 1;
        smax(ans, pil(k+i, -dton(dt)));
        dt[i] = 1;
        ++k;
        REP(j, i) dl[j] = 0;
      }
    }
    smax(ans, pil(k, -dton(dt)));
    printf("%I64d\n", -ans.Y);
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}