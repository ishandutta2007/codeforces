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

const int N = 1e5+5;
int n, k, a;

int g1[5] = {0, 1, 0, 1, 2};
int f1(int x) {
  if (x < 5) return g1[x];
  if (x % 2 == 1) return 0;
  int t = f1(x/2);
  if (t != 1) return 1;
  return 2;
}

int g0[3] = {0, 1, 2};
int f0(int x) {
  if (x < 3) return g0[x];
  return x % 2 == 0 ? 1 : 0;
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

//  const int M = 1000;
//  int g[M];
//  g[0] = 0;
//  FOR(i, 1, M) {
//    g[i] = 0;
//    REP(t, 2) {
//      if (g[i] == g[i-1]) ++g[i];
//      if ((i % 2 == 0) && g[i] == 0) ++g[i];
//      if ((i % 2 == 0) && g[i] == g[i/2]) ++g[i];
//    }
//  }
//  print("%d", g, g+M);

  scanf("%d%d", &n, &k);
  k %= 2;
  int ans = 0;
  REP(i, n) {
    int a;
    scanf("%d", &a);
    if (k == 0) ans ^= f0(a);
    else ans ^= f1(a);
  }
//  printf("%d\n", ans);
  printf("%s\n", ans != 0 ? "Kevin" : "Nicky");

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}