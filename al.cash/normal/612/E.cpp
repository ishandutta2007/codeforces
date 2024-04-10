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

const int N = 1e6+6;
int n, p[N], q[N];
vector<vi> c;
bool used[N];
vi t;

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) scanf("%d", p+i), --p[i];
  REP(i, n) if (!used[i]) {
    t.clear();
    for (int j = i; !used[j]; j = p[j]) {
      used[j] = true;
      t.pb(j);
    }
    if (sz(t)&1) {
      int d = (sz(t) + 1) / 2;
      REP(j, sz(t)) q[t[j]] = t[(j+d)%sz(t)];
    } else {
      c.pb(t);
    }
  }
  sort(all(c), [](const vi& a, const vi& b) { return sz(a) < sz(b); });
  for (int i = 0; i < sz(c); i += 2) {
    if (i+1 == sz(c) || sz(c[i]) != sz(c[i+1])) {
      printf("-1\n");
      return 0;
    }
    int m = sz(c[i]);
    REP(j, m) {
      q[c[i][j]] = c[i+1][j];
      q[c[i+1][j]] = c[i][(j+1)%m];
    }
  }
  REP(i, n) printf("%d ", q[i]+1);
  printf("\n");

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}