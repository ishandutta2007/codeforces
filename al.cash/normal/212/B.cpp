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

const int N = 1000011, M = 10011, A = 26;
int n, m;
char s[N], c[A+1];
int pr[A];
pii o[A];

short p[1<<A];
int ans[M], g[M];

vi t;

void inc(int u) {
  if (p[u] != -1) ++ans[p[u]];
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%s%d", s, &m);
  n = strlen(s);
  CL(p, -1);
  REP(i, m) {
    scanf("%s", c);
    int u = 0;
    REP(j, strlen(c)) u |= 1<<(c[j]-'a');
    if (p[u] == -1) p[u] = i, g[i] = i;
    else g[i] = p[u];
  }
  CL(ans, 0);
  t.clear();
  CL(pr, -1);
  REP(i, n) {
    int x = s[i] - 'a';
    //printf("%d: %d\n", i, x);
    REP(j, sz(t)) if (~t[j]>>x & 1) inc(t[j]);
    pr[x] = i;
    REP(i, A) o[i] = pii(pr[i], i);
    sort(o, o + A);
    t.clear();
    int u = 0;
    FORD(i, A - 1, 0) {
      if (o[i].X == -1) break;
      t.pb(u |= 1<<o[i].Y);
    }
  }
  REP(j, sz(t)) inc(t[j]);
  REP(i, m) printf("%d\n", ans[g[i]]);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
}