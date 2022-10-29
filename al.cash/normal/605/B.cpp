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

const int N = 1e5+5;
struct Edge {
  int a, b, i;
  void inp() { scanf("%d%d", &a, &b); }
  bool operator < (const Edge& other) const {
    return pii(a, -b) < pii(other.a, -other.b);
  }
} e[N];

int l[N];
pii ans[N];

int n, m;

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  REP(i, m) e[i].inp(), e[i].i = i;
  sort(e, e+m);
  REP(i, n) l[i] = i + 2;
  int cur = 0, f = 0;
  REP(i, m) {
//    printf("%d %d\n", e[i].a, e[i].b);
//    printf("cur = %d, f = %d\n", cur, f);
//    print("%d", l, l + n);
    if (e[i].b == 1) {
      ans[e[i].i] = {cur, cur + 1};
      ++cur;
      f = 0;
    } else {
      while (f < cur && l[f] > cur) ++f;
      if (f == cur) {
        printf("-1\n");
        return 0;
      }
      ans[e[i].i] = {f, l[f]};
      ++l[f];
    }
  }

  REP(i, m) printf("%d %d\n", ans[i].X+1, ans[i].Y+1);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}