#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <complex>
#include <numeric>
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

const int h = 111;
int n, m, a[h][h];
int sr[h], sc[h];
bool r[h], c[h];

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  REP(i, n) REP(j, m) scanf("%d", &a[i][j]);
  REP(i, n) REP(j, m) {
    sr[i] += a[i][j];
    sc[j] += a[i][j];
  }
  bool ok;
  do {
    ok = true;
    REP(i, n) if (sr[i] < 0) {
      ok = false;
      r[i] = !r[i];
      sr[i] = -sr[i];
      REP(j, m) {
        a[i][j] = -a[i][j];
        sc[j] += 2 * a[i][j];
      }
    }
    REP(j, m) if (sc[j] < 0) {
      ok = false;
      c[j] = !c[j];
      sc[j] = -sc[j];
      REP(i, n) {
        a[i][j] = -a[i][j];
        sr[i] += 2 * a[i][j];
      }
    }
  } while (!ok);

  vi ur, uc;
  REP(i, n) if (r[i]) ur.pb(i + 1);
  REP(j, m) if (c[j]) uc.pb(j + 1);

  printf("%d", sz(ur));
  REP(i, sz(ur)) printf(" %d", ur[i]); printf("\n");
  printf("%d", sz(uc));
  REP(i, sz(uc)) printf(" %d", uc[i]); printf("\n");

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}