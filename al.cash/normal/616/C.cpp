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
void print(const char* fmt, Iterator first, Iterator last,
           const char* delimiter = " ", const char* closing = "\n") {
  for (; first != last; ++first != last ? printf("%s", delimiter) : 0)
    printf(fmt, *first);
  printf("%s", closing);
}

class DSU {
  vector<int> parent;

public:
  DSU(int n = 0) { init(n); }

  int add() {
    parent.emplace_back(-1);
    return static_cast<int>(parent.size() - 1);
  }

  void init(int n) { parent.assign(n, -1); }

  int find(int v) {
    int u = v, t;
    while (parent[u] >= 0) u = parent[u];
    while (v != u && parent[v] != u) t = parent[v], parent[v] = u, v = t;
    return u;
  }

  int size(int v) { return -parent[find(v)]; }

  bool join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (parent[a] > parent[b]) swap(a, b);
    parent[a] += parent[b];
    parent[b] = a;
    return true;
  }
};

const int N = 1001;
int n, m;
char s[N][N];
DSU dsu;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%s", s[i]);
  dsu.init(n*m);
  REP(i, n) REP(j, m) if (s[i][j] == '.') {
    if (i > 0 && s[i-1][j] == '.') dsu.join(i*m+j, (i-1)*m+j);
    if (j > 0 && s[i][j-1] == '.') dsu.join(i*m+j, i*m+j-1);
  }
  REP(i, n) REP(j, m) if (s[i][j] == '*') {
    vector<pii> c;
    REP(u, 4) {
      int x = i + dx[u], y = j + dy[u];
      if (0 <= x && x < n && 0 <= y && y < m && s[x][y] == '.') {
        int v = dsu.find(x*m+y);
        c.eb(v, dsu.size(v));
      }
    }
    UNIQUE(c);
    int ans = 1;
    for (pii p : c) ans += p.Y;
    s[i][j] = '0' + ans % 10;
  }
  REP(i, n) printf("%s\n", s[i]);

#ifdef LocalHost
  cout << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}