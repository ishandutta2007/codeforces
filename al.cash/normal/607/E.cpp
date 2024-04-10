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

template <class T, int N>
struct FenwickTree {
  int n;
  T tree[N];

  void inc(int i, const T& delta) {
    for (; i < n; i |= i+1) tree[i] += delta;
  }

  T sum(int r) const {
    T res = 0;
    for (--r; r >= 0; r = (r & r+1)-1) res += tree[r];
    return res;
  }

  T sum(int l, int r) const { return sum(r) - sum(l); }
};

const int N = 5e4, E = 2 * N;
int n, m;
double a[N], b[N], dist[N], angle[N];
vector<pair<double, int>> events;

void inp(double& x) {
  int t;
  scanf("%d", &t);
  x = t / 1000.;
}

int calcEvents(double r) {
  events.clear();
  REP(i, n) {
    if (abs(dist[i]) > r) continue;
    double shift = acos(dist[i] / r), t;
    t = angle[i] - shift;
    events.eb(t < -pi ? t + 2 * pi : t, i);
    t = angle[i] + shift;
    events.eb(t >= pi ? t - 2 * pi : t, i);
  }
  sort(all(events));
  return sz(events);
}

FenwickTree<int, E> tree;
int start[E];

int intersectionCount(double r) {
  int k = tree.n = calcEvents(r);
  fill_n(start, k, -1);
  int res = 0;
  REP(i, k) {
    int u = events[i].Y;
    if (start[u] == -1) {
      start[u] = i;
      tree.inc(i, 1);
    } else {
      tree.inc(start[u], -1);
      res += tree.sum(start[u], k);
      start[u] = -1;
    }
  }
  return res;
}

inline double cross(int i, int j) {
  double x = (b[j] - b[i]) / (a[i] - a[j]);
  double y = a[i] * x + b[i];
  return sqrt(sqr(x) + sqr(y));
}

int nx[E], pr[E];
void erase(int i) {
  nx[pr[i]] = nx[i];
  pr[nx[i]] = pr[i];
}

double distanceSum(double r) {
  int k = calcEvents(r);
  REP(i, k) {
    int j = (i + 1) % k;
    nx[i] = j;
    pr[j] = i;
  }
  double sum = 0;
  fill_n(start, k, -1);
  REP(i, k) {
    int u = events[i].Y;
    if (start[u] == -1) {
      start[u] = i;
    } else {
      for (int t = nx[start[u]]; t != i; t = nx[t], --m)
        sum += cross(u, events[t].Y);
      erase(start[u]);
      erase(i);
    }
  }
  return sum + m * r;
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  double x0, y0;
  scanf("%d", &n);
  inp(x0);
  inp(y0);
  scanf("%d", &m);
  REP(i, n) {
    inp(a[i]);
    inp(b[i]);
    b[i] += a[i] * x0 - y0;
    dist[i] = b[i] / sqrt(sqr(a[i]) + 1);
    angle[i] = atan2(-1, a[i]);
  }

  double l = 0, r = 2e9 + 2e3;
  REP(it, 50) {
    double mid = (l + r) / 2;
    if (intersectionCount(mid) >= m) r = mid;
    else l = mid;
  }
  printf("%.9lf\n", distanceSum(l));

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}