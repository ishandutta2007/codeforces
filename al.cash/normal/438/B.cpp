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
int n, m;
int a[h];
vi r[h];
pii p[h];

int root[h], k[h];
int fr(int x) { return root[x] == x ? x : fr(root[x]); }

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  REP(i, n) {
    scanf("%d", a+i);
    p[i] = pii(a[i], i);
  }
  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a; --b;
    r[a].pb(b);
    r[b].pb(a);
  }
  ll ans = 0;
  CL(root, -1);
  CL(k, 0);
  sort(p, p+n);
  FORD(t, n-1, 0) {
    int i = p[t].Y;
    REP(c, sz(r[i])) {
      int j = r[i][c];
      if (root[j] != -1) {
        if (root[i] == -1) {
          root[i] = fr(j);
          ans += ll(p[t].X) * k[root[i]];
          ++k[root[i]];
        } else if (fr(i) != fr(j)) {
          ans += ll(p[t].X) * k[fr(i)] * k[fr(j)];
          k[fr(i)] += k[fr(j)];
          root[fr(j)] = fr(i);
        }
      }
    }
    if (root[i] == -1) {
      root[i] = i;
      k[i] = 1;
    }
  }
  ll d = ll(n) * (n-1) / 2;
  cout << ans / d << '.';
  REP(i, 9) {
    ans %= d;
    ans *= 10;
    cout << ans / d;
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}