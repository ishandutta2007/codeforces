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

const int h = 100011;
int m, k, p;
int d[h], s[h];
vi r[h];
bool use[h];

void dfs(int v, int l) {
  if (use[v]) return;
  ++d[l];
  use[v] = true;
  REP(i, sz(r[v])) dfs(r[v][i], l+1);
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d", &m, &k, &p);
  int a, b;
  REP(i, m-1) {
    scanf("%d%d", &a, &b);
    --a;
    --b;
    r[a].pb(b);
    r[b].pb(a);
  }
  dfs(0, 0);
  s[0] = 0;
  REP(i, m) s[i+1] = s[i] + d[i];

  ll res = d[1], c = 0;
  for (b = 1, a = 2; d[a] > 0; ++a) {
    c += s[a] - s[b];
    while (true) {
      ll v = d[b] * ll(a - b);
      if (c - v >= p) {
        c -= v;
        ++b;
      }
      else break;
    }
    smax(res, s[a+1] - s[b] - (max(c-p, 0ll) + a-b-1) / (a-b));
    //printf("%d %d: %d %d\n", a, b, c, s[a+1] - s[b] - (max(c-p, 0) + a-b-1) / (a-b));
  }

  printf("%d\n", min(int(res), k));

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}