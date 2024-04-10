#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
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

template <class T> T& smin(T& x, const T& y) { if (x > y) x = y; return x; }
template <class T> T& smax(T& x, const T& y) { if (x < y) x = y; return x; }
template <class T> T sqr(const T& x) { return x * x; }

template <typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
           const char* delimiter = " ", const char* closing = "\n") {
  for (; begin != end; ++begin != end ? printf("%s", delimiter) : 0)
    printf(fmt, *begin);
  printf("%s", closing);
}

const int N = 2e5+5;
int n, f[3], t[N], ans = 0;
bool d[N];

void go(int one, int two) {
  int u = n;
  while (u > 0 && t[u-1] > one) --u;
  while (true) {
    while (n > 0 && d[n-1]) --n;
    if (n == 0 || t[n-1] <= two) return;
    ++ans;
    d[--n] = true;
    while (u > 0 && d[u-1]) --u;
    if (u > 0) d[--u] = true;
  }
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, 3) scanf("%d", f+i);
  REP(i, n) scanf("%d", t+i);
  int s = f[0] + f[1] + f[2];
  sort(f, f+3);
  sort(t, t+n);
  if (t[n-1] > s) {
    printf("-1\n");
    return 0;
  }
  s = f[1] + f[2];
  while (n > 0 && t[n-1] > s) --n, ++ans;
  go(f[0], f[0] + f[2]);
  if (f[2] < f[0] + f[1]) {
    go(f[1], f[0] + f[1]);
    go(f[2], f[2]);
    vi r;
    REP(i, n) if (!d[i]) r.pb(t[i]);
    int ua = 0;
    while (ua < sz(r) && r[ua] <= f[0]) ++ua;
    int ub = ua;
    while (ub < sz(r) && r[ub] <= f[1]) ++ub;
    int ka = ua, kb = ub - ua, kc = sz(r) - ub;
    while (ka || kb || kc) {
      ++ans;
      if (kc) --kc;
      else if (kb) --kb;
      else --ka;
      if (ka) {
        --ka;
        if (kb) --kb;
        else if (ka) --ka;
      } else {
        if (kc) --kc;
        else if (kb) --kb;
      }
    }
  } else {
    go(f[1], f[2]);
    vi r;
    REP(i, n) if (!d[i]) r.pb(t[i]);
    int ua = 0;
    while (ua < sz(r) && r[ua] <= f[0]) ++ua;
    int ub = ua;
    while (ub < sz(r) && r[ub] <= f[1]) ++ub;
    int uab = ub;
    while (uab < sz(r) && r[uab] <= f[0] + f[1]) ++uab;
    int ka = ua, kb = ub - ua, kab = uab - ub, kc = sz(r) - uab;
//    printf("ans = %d\n", ans);
//    print("%d", all(r));
//    printf("%d %d %d %d\n", ka, kb, kab, kc);
    while (ka || kb || kab || kc) {
      ++ans;
      if (kc) --kc;
      else if (kab) --kab;
      else if (kb) --kb;
      else --ka;
      if (ka) {
        --ka;
        if (kb) --kb;
        else if (ka) --ka;
      } else {
        if (kab) --kab;
        else if (kb) --kb;
      }
    }
  }
  printf("%d\n", ans);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}