#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <complex>
#include <numeric>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define FORE(e, v) for (int e = head[v]; e >= 0; e = E[e].next)
#define UN(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T> T sqr(T a) { return a * a; }

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
    const char* separator = " ") {
  for (Iterator it = begin; it != end; ++it) {
    if (it != begin) printf(separator);
    printf(fmt, *it);
  }
  printf("\n");
}

const int V = 8;
const int v[V][3] = {
    {0, 0, 0},
    {0, 0, 1},
    {0, 1, 0},
    {1, 0, 0},
    {0, 1, 1},
    {1, 0, 1},
    {1, 1, 0},
    {1, 1, 1},
};
ll d[V][V];

int c[V][3];
int p[V];
bool fr[V];

ll dst(const int a[3], const int b[3]) {
  ll res = 0;
  REP(i, 3) res += sqr(ll(a[i] - b[i]));
  return res;
}

bool perm(int x);

bool go(int x) {
  FOR(i, 1, V) if (fr[i]) {
    p[x] = i;
    fr[i] = false;
    ll d0 = dst(c[0], c[x]);
    bool ok = d0 != 0;
    if (ok) FOR(j, 1, x) {
      ll dj = dst(c[j], c[x]);
      if (d0 * d[p[j]][p[x]] != dj * d[0][p[x]]) {
        ok = false;
        break;
      }
    }
    if (ok && perm(x + 1)) return true;
    fr[i] = true;
  }
  return false;
}

bool perm(int x) {
  if (x == V) return true;
  if (go(x)) return true;
  swap(c[x][1], c[x][2]);
  if (go(x)) return true;
  swap(c[x][0], c[x][1]);
  if (go(x)) return true;
  swap(c[x][1], c[x][2]);
  if (go(x)) return true;
  swap(c[x][0], c[x][1]);
  if (go(x)) return true;
  swap(c[x][1], c[x][2]);
  if (go(x)) return true;
  swap(c[x][0], c[x][1]);
  return false;
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  REP(i, V) REP(j, V) d[i][j] = dst(v[i], v[j]);

  REP(i, V) REP(j, 3) scanf("%d", c[i]+j);
  p[0] = 0;
  fill_n(fr, V, true);

  if (perm(1)) {
    printf("YES\n");
    REP(i, V) print("%d", c[i], c[i]+3);
  } else {
    printf("NO\n");
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}