#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
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
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 9000000000000000000LL;
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> void gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }

template<class T> void outp(const vector<T>& v) {
  REP(i, sz(v)) cout << v[i] << (i + 1 == sz(v) ? '\n' : ' ');
}
template<class T> void outp(T* v, int n) {
  REP(i, n) cout << *v++ << (i + 1 == n ? '\n' : ' ');
}

const int h = 250025;
int n, x[h],y[h], p[h],r[h], m[h];
int o[h];
ll d[h], r2[h];

bool comp(int i, int j) {
  return m[i] < m[j];
}

typedef pair<ll, int> pli;
pli t[2*h];  // min

void build() {
  REP(i, n) t[i+n+1] = pli(d[o[i]], i);
  FORD(i, n, 1) {
    t[i] = t[2*i];
    if(i<n) smin(t[i], t[2*i+1]);
  }
}

void put(int x, ll v) {
  pli tv = pli(v, x);
  x += n+1;
  t[x] = tv;
  while(x>1) {
    x >>= 1;
    t[x] = t[2*x];
    if(x<n) smin(t[x], t[2*x+1]);
  }
}

pli get(int x, int y) {
  pli res(INF_LL, -1);
  for(x+=n+1, y+=n+1; x<=y; x=x+1>>1, y=y-1>>1) {
    smin(res, t[x]);
    smin(res, t[y]);
  }
  return res;
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d%d%d", x+0, y+0, p+0, r+0, &n);
  ++n;
  FOR(i, 1, n) scanf("%d%d%d%d%d", x+i, y+i, m+i, p+i, r+i);
  FORD(i, n-1, 0) {
    x[i] -= x[0];
    y[i] -= y[0];
    d[i] = ll(x[i])*x[i] + ll(y[i])*y[i];
  }
  REP(i, n) {
    r2[i] = ll(r[i]) * r[i];
    o[i] = i;
  }
  sort(o, o+n, comp);
  //outp(o, n);


//  REP(i, n) FOR(j, i, n) {
//    pli t = get(i, j);
//    printf("%d %d: %lld %d\n", i, j, t.X, t.Y);
//  }
//  return 0;

  build();
  put(0, INF_LL);
  m[0] = p[0];
  vi q(1, 0);
  int a = 0;
  while(a<sz(q)) {
    int v = q[a++];
    m[n] = p[o[v]];
    int r = upper_bound(o, o+n, n, comp) - o;
    //printf("%d (%d), %d: %d...\n", v, o[v], m[o[v]], r);
    while(1) {
      pli e = get(0, r-1);
      int u = e.Y;
      //printf("%lld %d (%d)\n", e.X, u, o[u]);
      if(e.X <= r2[o[v]]) {
        //printf("!\n");
        q.pb(u);
        put(u, INF_LL);
        //m[o[u]] = p[o[u]];
      } else break;
    }
  }
  printf("%d\n", sz(q) - 1);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
}