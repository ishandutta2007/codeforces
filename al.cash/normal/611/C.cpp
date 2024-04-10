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

const int N = 505;
int h, w, q;
char s[N][N];
int sh[N][N], sv[N][N];

int sum(int f[N][N], int r0, int c0, int r1, int c1) {
  return f[r1][c1] - f[r0-1][c1] - f[r1][c0-1] + f[r0-1][c0-1];
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &h, &w);
  REP(i, h) scanf("%s", s+i);
  REP(i, h) REP(j, w) {
    if (s[i][j] == '.') {
      if (i+1 < h && s[i+1][j] == '.') sv[i+1][j+1] = 1;
      if (j+1 < w && s[i][j+1] == '.') sh[i+1][j+1] = 1;
    }
    sv[i+1][j+1] += sv[i+1][j] + sv[i][j+1] - sv[i][j];
    sh[i+1][j+1] += sh[i+1][j] + sh[i][j+1] - sh[i][j];
  }
  scanf("%d", &q);
  REP(u, q) {
    int r0, c0, r1, c1;
    scanf("%d%d%d%d", &r0, &c0, &r1, &c1);
    printf("%d\n", sum(sv, r0, c0, r1-1, c1) + sum(sh, r0, c0, r1, c1-1));
  }

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}