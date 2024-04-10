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

const int h = 2002;
int n, m;
bool r[h], c[h];
double a[h][h], b[h][h];

void inc(double &a, double &b, double c, double da, double db) {
  a += c * da;
  b += c * db;
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  int x, y;
  REP(i, m) {
    scanf("%d%d", &x, &y);
    r[x-1] = true;
    c[y-1] = true;
  }
  int re = count(r, r+n, false);
  int ce = count(c, c+n, false);
  a[0][0] = 1.0;
  b[0][0] = 0.0;
  REP(i, re+1) REP(j, ce+1) if (i+j > 0 && i+j < 2*n) {
    double ci = double(i) / n;
    double cj = double(j) / n;
    if (i > 0) {
      inc(a[i][j], b[i][j], ci * (1 - cj), a[i-1][j], b[i-1][j]);
      if (j > 0) inc(a[i][j], b[i][j], ci * cj, a[i-1][j-1], b[i-1][j-1]);
    }
    if (j > 0) inc(a[i][j], b[i][j], (1 - ci) * cj, a[i][j-1], b[i][j-1]);
    b[i][j] -= 1.0;
    double c0 = 1 - (1 - ci) * (1 - cj);
    a[i][j] /= c0;
    b[i][j] /= c0;
  }
  if (re + ce == 2*n) {
    a[re][ce] = a[re-1][ce-1];
    b[re][ce] = b[re-1][ce-1] - 1;
  }
  //REP(i, re+1) { REP(j, ce+1) printf("%.3lf,%.3lf ", a[i][j], b[i][j]); printf("\n"); }
  printf("%.6lf\n", -b[re][ce]/a[re][ce]);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}