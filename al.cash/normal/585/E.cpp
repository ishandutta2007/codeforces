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
void inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }
int add(int x, int y) { inc(x, y); return x; }
int mul(int x, int y) { return (ll(x) * y) % mod; }

void dec(int &x, int y) { x -= y; if (x < 0) x += mod; }
int sub(int x, int y) { dec(x, y); return x; }

const int A = 1e7+1, N = 5e5+1;
int lp[A];
vi pr;

int n, a[N];
vi d[N];
int cnt, mcnt[A];

int p2[N];
int g, ga;

void go1(const vi& d, int i = 0, int v = 1, bool p = true) {
  if (i == sz(d)) {
    if (p) mcnt[v] -= cnt;
    else mcnt[v] += cnt;
  } else {
    go1(d, i + 1, v, p);
    go1(d, i + 1, v * d[i], !p);
  }
}

void go2(const vi& d, int i = 0, int v = 1) {
  if (i == sz(d)) {
    dec(ga, mcnt[v]);
  } else {
    go2(d, i + 1, v);
    go2(d, i + 1, v * d[i]);
  }
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  for (int i = 2; i < A; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.pb(i);
    }
    for (int p : pr) {
      if (p * i >= A || lp[i] < p) break;
      lp[p * i] = p;
    }
  }

  p2[0] = 1;
  FOR(i, 1, N) p2[i] = mul(2, p2[i-1]);

  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);
  sort(a, a+n);
  for (int i = 0, j; i < n; i = j) {
    for (j = i + 1; j < n && a[i] == a[j]; ++j);
    int v = a[i];
    while (v != 1) {
      int p = lp[v];
      d[i].pb(p);
      do { v /= p; } while (lp[v] == p);
    }
    cnt = j - i;
    go1(d[i]);
  }

  mcnt[1] = 0;
  FOR(i, 2, A) if (mcnt[i]) {
    if (mcnt[i] > 0) mcnt[i] = p2[mcnt[i]] - 1;
    else mcnt[i] = sub(1, p2[-mcnt[i]]);
    inc(g, mcnt[i]);
  }

  int ans = 0;
  for (int i = 0, j; i < n; i = j) {
    for (j = i + 1; j < n && a[i] == a[j]; ++j);
    ga = g;
    go2(d[i]);
    inc(ans, mul(ga, j - i));
  }
  printf("%d\n", ans);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}