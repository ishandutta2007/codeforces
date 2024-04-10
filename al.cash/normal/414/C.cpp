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

const int N = 20;
int n, m, q;
int a[1<<N], b[1<<N];

ll s[N], c[N];

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, 1<<n) scanf("%d", a+i);
  int p = 1;
  FOR(u, 0, n) {
    c[u] = 0;
    s[u] = 1ll<<(n+u-1);
    //s[u] = 0;
    for (int x = 0; x < (1<<n); x += 2*p) {
      int i = 0, j = 0, t = x;
      while (i < p || j < p) {
        int v = INF;
        if (i < p) smin(v, a[x+i]);
        if (j < p) smin(v, a[x+p+j]);
        int ki = 0, kj = 0;
        while (i < p && a[x+i] == v) ++i, ++ki;
        c[u] += ll(ki) * j;
        while (j < p && a[x+p+j] == v) ++j, ++kj;
        s[u] -= ll(ki) * kj;
        //s[u] += ll(ki) * (p - kj);
        REP(o, ki + kj) b[t++] = v;
      }
    }
    p <<= 1;
    REP(i, 1<<n) a[i] = b[i];
  }

//  outp(c, n);
//  outp(s, n);

  scanf("%d", &m);
  REP(i, m) {
    scanf("%d", &q);
    REP(i, q) c[i] = s[i] - c[i];
    ll sum = 0;
    REP(i, n) sum += c[i];
    printf("%lld\n", sum);
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}