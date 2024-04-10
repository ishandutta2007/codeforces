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

const int N = 3e5+5, A = 26;
int n, c[N];
char s[N];
int m = 0, t[N][A], k[N];
vi e[N];

int ans = 0, kans;

void merge(int v, int u) {
  k[v] = 1;
  REP(c, A) {
    if (t[u][c]) {
      if (t[v][c]) merge(t[v][c], t[u][c]);
      else t[v][c] = t[u][c];
    }
    if (t[v][c]) k[v] += k[t[v][c]];
  }
}

int dfs(int v, int p) {
  int tv = m++;
//  printf("%d\n", tv);
  k[tv] = 1;
  for (int u : e[v]) if (u != p) {
    int tu = dfs(u, v);
    if (t[tv][s[u]] == 0) {
      k[tv] += k[tu];
      t[tv][s[u]] = tu;
    } else {
      int tm = t[tv][s[u]];
      k[tv] -= k[tm];
      merge(tm, tu);
      k[tv] += k[tm];
    }
  }
  int cur = k[tv] + c[v];
  if (cur > ans) ans = cur, kans = 1;
  else if (cur == ans) ++kans;
  return tv;
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) scanf("%d", c+i);
  scanf("%s", s);

//  n = 300000;
//  REP(i, n) c[i] = 0;
//  REP(i, n) s[i] = 'a';
//  int kk = 0;
//  REP(i, n) {
//    int v = 2*i + 1;
//    if (v >= n) break;
//    e[i].pb(v), e[v].pb(i), ++kk;
//    ++v;
//    if (v < n) e[i].pb(v), e[v].pb(i), ++kk;
//  }

  REP(i, n) s[i] -= 'a';
  REP(i, n-1) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a; --b;
    e[a].pb(b);
    e[b].pb(a);
  }
  dfs(0, -1);
  printf("%d\n%d\n", ans, kans);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}