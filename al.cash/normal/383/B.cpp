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

const int M = 100011;
int n, m;
pii c[M];

int x;
vector<pii> a, b;

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  REP(i, m) scanf("%d%d", &c[i].X, &c[i].Y);
  sort(c, c+m);
  //outp(c, m);

  x = 0;
  a.pb(pii(1, 1));

  REP (i, m) {
    if (c[i].X > x + 1) {
      a.resize(1);
      a[0].Y = n;
    }

    int j = i;
    b.clear();
    int u = 0;
    while (j < m && c[j].X == c[i].X) {
      if (u < sz(a)) {
        int y = a[u].X;
        while (u < sz(a) && a[u].Y <= c[j].Y) ++u;
        if (y < c[j].Y) b.pb(pii(y, c[j].Y-1));
        smax(a[u].X, c[j].Y+1);
      }
      ++j;
    }
    if (u < sz(a) && a[u].X <= n) b.pb(pii(a[u].X, n));

    a = b;
    //outp(a);
    if (a.empty()) break;
    i = j-1;
    x = c[i].X;
  }
  if (!a.empty() && x < n) a.back().Y = n;

  printf("%d\n", (!a.empty() && a.back().Y == n) ? 2*(n-1) : -1);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}