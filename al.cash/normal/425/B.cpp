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

const int h = 102;
int n, m, k;
int a[h][h];
int x[h], y[h];

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d", &n, &m, &k);
  REP(i, n) REP(j, m) scanf("%d", &a[i][j]);
  int ans = INF;
  if (k >= n) {
    REP(u, 1<<n) {
      REP(i, n) x[i] = 1&u>>i;
      int sum = 0;
      REP(j, m) {
        int e = 0;
        REP(i, n) e += x[i] == a[i][j];
        sum += min(e, n-e);
      }
      smin(ans, sum);
    }
  } else {
    REP(u, n) {
      REP(j, m) y[j] = a[u][j];
      int sum = 0;
      REP(i, n) {
        int e = 0;
        REP(j, m) e += y[j] == a[i][j];
        sum += min(e, m-e);
      }
      smin(ans, sum);
    }
  }
  //printf("%d\n", ans);
  printf("%d\n", ans <= k ? ans : -1);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}