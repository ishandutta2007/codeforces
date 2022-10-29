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

const int N = 505;
int n, c[N];
int d[N][N][2];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) scanf("%d", c+i);
  REP(i, n) {
    d[i][i][0] = d[i][i][1] = 0;
    d[i][i+1][0] = 1;
    d[i][i+1][1] = 0;
  }
  FOR(l, 2, n+1) for (int i = 0; i + l <= n; ++i) {
    d[i][i+l][0] = d[i][i+l][1] = INF;
    if (c[i] == c[i+l-1]) {
      smin(d[i][i+l][0], d[i+1][i+l-1][1] + 1);
      smin(d[i][i+l][1], d[i+1][i+l-1][1]);
    }
    FOR(j, i+1, i+l) {
      smin(d[i][i+l][0], d[i][j][0] + d[j][i+l][0]);
      smin(d[i][i+l][1], d[i][j][0] + d[j][i+l][1]);
      smin(d[i][i+l][1], d[i][j][1] + d[j][i+l][0]);
    }
  }

  printf("%d\n", d[0][n][0]);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}