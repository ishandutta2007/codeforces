#include <stdexcept>
#include <iostream>
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

typedef pair<ll, int> pli;
const int N = 2e5+5;
int n, m, k, s;
int a[N], b[N];
pli ma[N], mb[N];
int t[N], c[N];

pli x[N];
bool solve(int d) {
  REP(i, m) {
    if (t[i] == 1) x[i] = {ma[d].X * c[i], i};
    else x[i] = {mb[d].X * c[i], i};
  }
//  nth_element(x, x+k, x+m);
  sort(x, x+m);
  ll sum = 0;
  REP(i, k) sum += x[i].X;
//  printf("%d: %lld\n", d, sum);
  return sum <= s;
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d%d", &n, &m, &k, &s);
  REP(i, n) scanf("%d", a+i);
  REP(i, n) scanf("%d", b+i);
  REP(i, n) {
    ma[i] = (i == 0 || a[i] < ma[i-1].X) ? pli(a[i], i) : ma[i-1];
    mb[i] = (i == 0 || b[i] < mb[i-1].X) ? pli(b[i], i) : mb[i-1];
  }
  REP(i, m) scanf("%d%d", t+i, c+i);
  int l = 0, r = n;
  while (l != r) {
    int d = (l + r) / 2;
    if (solve(d)) r = d;
    else l = d + 1;
  }
  if (r == n) printf("-1\n");
  else {
    printf("%d\n", r + 1);
    solve(r);
    REP(i, k) {
      int u = x[i].Y;
      printf("%d %d\n", u + 1, (t[u] == 1 ? ma[r].Y : mb[r].Y) + 1);
    }
  }

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}