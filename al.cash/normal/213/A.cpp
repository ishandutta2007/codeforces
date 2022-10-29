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

const int h = 202;
int n, c[h], d0[h], d[h];
vi r[h];

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) scanf("%d", c+i), --c[i];
  REP(i, n) r[i].clear();
  int a;
  REP(i, n) {
    scanf("%d", d0+i);
    REP(j, d0[i]) {
      scanf("%d", &a);
      r[a-1].pb(i);
    }
  }
  int ans = INF;
  REP(s, 3) {
    int v = s, t = 0;
    int left = n;
    REP(i, n) d[i] = d0[i];
    while (left) {
      vi q;
      REP(i, n) if (c[i] == v && d[i] == 0) q.pb(i);
      for (int qa = 0; qa < sz(q); ++qa) {
        ++t;
        --left;
        int i = q[qa];
        d[i] = -1;
        REP(j, sz(r[i])) {
          int u = r[i][j];
          --d[u];
          if (c[u] == v && d[u] == 0) q.pb(u);
        }
      }
      ++v;
      if (v == 3) v = 0;
      ++t;
    }
    smin(ans, t);
  }
  printf("%d\n", ans - 1);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
}