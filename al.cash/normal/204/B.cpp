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
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define FORE(e, v) for (int e = head[v]; e >= 0; e = E[e].next)
#define UN(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T> T sqr(T a) { return a * a; }

template<class T> void outp(const vector<T>& v) {
  REP(i, sz(v)) cout << v[i] << (i + 1 == sz(v) ? '\n' : ' ');
}
template<class T> void outp(T* v, int n) {
  REP(i, n) cout << *v++ << (i + 1 == n ? '\n' : ' ');
}

const int h = 100011;
int n;
int a[h], b[h];

map<int, int> k;

void add(int v) {
  if (k.count(v)) ++k[v];
  else k[v] = 1;
}

int main() {
#ifdef LocalHost
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) scanf("%d%d", a+i, b+i);
  k.clear();
  REP(i, n) {
    add(a[i]);
    if (a[i] != b[i]) add(b[i]);
  }
  int ans = -1;
  int m = (n + 1) / 2;
  for (map<int, int>::iterator it = k.begin(); it != k.end(); ++it) {
    int v = it->X;
    if (it->Y < m) continue;
    int u = 0;
    REP(i, n) if (a[i] == v) ++u;
    if (ans == -1) ans = max(0, m - u);
    else smin(ans, max(0, m - u));
  }
  printf("%d\n", ans);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
}