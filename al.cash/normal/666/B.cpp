#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <memory>
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
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), b_(b); i >= b_; --i)
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
template <class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;

const int INF = static_cast<int>(1e9);
const long long INF_LL = static_cast<long long>(4e18);
const double pi = acos(-1.0);

template <class T> T& smin(T& x, const T& y) { if (x > y) x = y; return x; }
template <class T> T& smax(T& x, const T& y) { if (x < y) x = y; return x; }
template <class T> T sqr(const T& x) { return x * x; }

template <class T> T gcd(T a, T b) {
  for (a = abs(a), b = abs(b); a && b; a >= b ? a %= b : b %= a);
  return a + b;
}

template <typename Iterator>
void print(const char* format, Iterator first, Iterator last,
           const char* delimiter = " ", const char* closing = "\n") {
  for (; first != last; ++first != last ? printf("%s", delimiter) : 0)
    printf(format, *first);
  printf("%s", closing);
}

const int N = 3003, M = 5005;
int n, m;
vi e[N];
int d[N][N];
int q[N];

int ans;
vi ia;

vector<pii> t2[N];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  REP(i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u;
    --v;
    if (u != v) e[u].pb(v);
  }
  REP(i, n) {
    REP(j, n) d[i][j] = INF;
    d[i][i] = 0;
    q[0] = i;
    for (int qa = 0, qb = 1; qa < qb; ++qa) {
      int u = q[qa];
      for (int v : e[u]) if (d[i][v] == INF) {
        d[i][v] = d[i][u] + 1;
        q[qb++] = v;
      }
    }
//    printf("%d: ", i + 1);
//    print("%d", d[i], d[i]+n);
  }

  ia.resize(4);
  REP(i2, n) {
    REP(j, n) if (j != i2 && d[i2][j] != INF) t2[i2].eb(d[i2][j], j);
    sort(all(t2[i2]));
    reverse(all(t2[i2]));
    if (sz(t2[i2]) > 3) t2[i2].resize(3);
  }

  ans = 0;
  REP(i1, n) {
    vector<pii> t1;
    REP(j, n) if (j != i1 && d[j][i1] != INF) t1.eb(d[j][i1], j);
    sort(all(t1));
    reverse(all(t1));
    if (sz(t1) > 3) t1.resize(3);
    REP(i2, n) if (i2 != i1 && d[i1][i2] != INF) {
      for (pii u : t1) if (u.Y != i2)
        for (pii v : t2[i2]) if (v.Y != i1 && v.Y != u.Y) {
          int cur = u.X + d[i1][i2] + v.X;
          if (cur > ans) {
            ans = cur;
            ia = {u.Y, i1, i2, v.Y};
          }
        }
    }
  }
  for (int i : ia) printf("%d ", i + 1);
  printf("\n");
//  printf("%d\n", ans);

#ifdef LocalHost
  cerr << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}