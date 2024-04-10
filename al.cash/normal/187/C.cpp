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
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a%b); }

const int h = 100011;
int n,m, k;
vi v;
vi r[h];
pii e[2*h];
int s,t;

bool us[3*h];
int p[3*h];
int pr(int x) { return p[x]==x ? x : p[x] = pr(p[x]); }

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d", &n, &m, &k);
  v.resize(k);
  REP(i, k) scanf("%d", &v[i]), --v[i];
  int a,b;
  REP(i, m) {
    scanf("%d%d", &a, &b);
    --a; --b;
    r[a].pb(i);
    r[b].pb(i);
    e[i] = pii(a, b);
  }
  scanf("%d%d", &s, &t);
  --s; --t;

  REP(i, n+m) p[i] = i;

  CL(us, 0);
  REP(i, sz(v)) us[v[i]] = true;
  if(!us[t]) {
    us[t] = true;
    v.pb(t);
  }
  int q = 0, c = 0;
  while(1) {
    if(c==sz(v)) {
      printf("-1\n");
      break;
    }
    int l = sz(v);
    FOR(o, c, l) {
      int x = v[o];
      if(x<n) {
        REP(i, sz(r[x])) {
          int j = r[x][i] + n;
          p[pr(j)] = pr(x);
          if(!us[j]) {
            us[j] = true;
            v.pb(j);
          }
        }
      } else {
        a = e[x-n].X;
        b = e[x-n].Y;
        p[pr(a)] = pr(x);
        p[pr(b)] = pr(x);
        if(!us[a]) {
          us[a] = true;
          v.pb(a);
        }
        if(!us[b]) {
          us[b] = true;
          v.pb(b);
        }
      }
    }
    c = l;
    ++q;
    if(pr(s)==pr(t)) {
      printf("%d\n", q);
      break;
    }
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}