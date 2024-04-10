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
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T> T sqr(T a) { return a * a; }

template<class T1, class T2>
ostream& operator << (ostream& out, const pair<T1, T2>& p) {
  out << p.X << ',' << p.Y;
  return out;
}
template<class T> void outp(const vector<T>& v) {
  cout << sz(v) << ":";
  REP(i, sz(v)) cout << " " << v[i];
  cout << endl;
}
template<class T> void outp(T* v, int n) {
  cout << n << ":";
  REP(i, n) cout << " " << *v++;
  cout << endl;
}

const int h = 50005;
int n, q;
int o[h], sum[h];
vi a[h], d[h];

void edge(int u, int v, bool add) {
  if (sz(a[u]) + sz(d[u]) > sz(a[v]) + sz(d[v])) swap(u, v);
  if (add) a[u].pb(v), sum[v] += o[u];
  else d[u].pb(v), sum[v] -= o[u];
}

void rev(int u) {
  int x = 1 - 2 * o[u];
  o[u] ^= 1;
  for (vi::iterator it = a[u].begin(); it != a[u].end(); ++it) sum[*it] += x;
  for (vi::iterator it = d[u].begin(); it != d[u].end(); ++it) sum[*it] -= x;
}

int calc(int u) {
  int res = sum[u];
  for (vi::iterator it = a[u].begin(); it != a[u].end(); ++it) res += o[*it];
  for (vi::iterator it = d[u].begin(); it != d[u].end(); ++it) res -= o[*it];
  return res;
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  int m, k, u, v;
  scanf("%d%d%d%d", &n, &m, &q, &k);
  REP(i, k) {
    scanf("%d", &u);
    o[u] = true;
  }
  REP(i, m) {
    scanf("%d%d", &u, &v);
    edge(u, v, true);
  }
  char c;
  REP(i, q) {
    do { scanf("%c", &c); } while (!isalpha(c));
    switch (c) {
      case 'O': case 'F':
        scanf("%d", &u);
        rev(u);
        break;
      case 'A': case 'D':
        scanf("%d%d", &u, &v);
        edge(u, v, c == 'A');
        break;
      case 'C':
        scanf("%d", &u);
        printf("%d\n", calc(u));
        break;
    }
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}