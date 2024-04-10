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

const int h = 100011;
int n, m, s, e;
int a[h], b[h];
vi ub[h];

int find(int v, int r) {
  if (ub[v].empty()) return -1;
  int i = lower_bound(all(ub[v]), r) - ub[v].begin() - 1;
  return i >= 0 ? ub[v][i] : -1;
}

const int K = 303;
int d[K];

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d%d", &n, &m, &s, &e);
  REP(i, n) scanf("%d", a+i);
  REP(j, m) scanf("%d", b+j);
  REP(j, m) ub[b[j]].pb(j);
  int l = 0, r = s / e + 1;
  while (l + 1 < r) {
    int k = (l + r) / 2;
    int f = s - k * e;
    //printf("%d: %d\n", k, f);
    CL(d, -1);
    int p = 0;
    FORD(i, n-1, 0) {
      d[0] = max(-1, f - i - 1);
      //printf("%d ", d[0]);
      FORD(j, p, 0) smax(d[j+1], find(a[i], d[j]));
      if (d[p+1] != -1) ++p;
      if (p == k) break;
    }
    //printf("\n");
    //outp(d, k+1);
    if (d[k] == -1) r = k;
    else l = k;
  }
  printf("%d\n", l);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}