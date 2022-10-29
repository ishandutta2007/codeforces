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
#define FOR(i, a, b) for(int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i(a), _b(b); i >= _b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;

class tree {
  int n;
  vi t;

public:
  tree(int n) : n(n), t(n) {}

  int len() { return n; }

  void inc(int i, int v) {
    for(; i < n; i |= i+1) t[i] += v;
  }

  int sum(int r) {
    int res = 0;
    for(; r >= 0; r = (r&(r+1))-1) res += t[r];
    return res;
  }

  int ye(int l, int r) {
    if (r > n) r = n;
    return (r - l) - (sum(r-1) - sum(l-1));
  }
};

const int h = 200022;

int n,m,k;
pii u[h];
bool y[h];

vector<tree> t;

map<int, pii> ui;

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d", &n, &m, &k);
  CL(y, 0);
  REP(i, n) if(!y[i]) {
    int j = i;
    int k = 0;
    while(!y[j]) {
      y[j] = true;
      u[j] = pii(sz(t), k);
      j += m;
      if (j >= n) j -= n;
      ++k;
    }
    t.pb(tree(k));
  }

  ll ans = 0;

  char c;
  int id, hs;
  REP(i, k) {
    c = 0;
    while(c!='-' && c!='+') scanf("%c", &c);
    scanf("%d", &id);
    if (c == '+') {
      scanf("%d", &hs);
      int v = u[hs].X, p = u[hs].Y;
      if (!t[v].ye(p, t[v].len())) {
        ans += t[v].len() - p;
        p = 0;
      }
      int a = 1;
      while ((a<<1) <= t[v].len()) a <<= 1;
      while (a>0) {
        if (!t[v].ye(p, p+a)) {
          ans += a;
          p += a;
        }
        a >>= 1;
      }
      ui[id] = pii(v, p);
      t[v].inc(p, 1);
    } else {
      pii uid = ui[id];
      int v = uid.X, p = uid.Y;
      t[v].inc(p, -1);
    }
  }
  cout << ans << endl;

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}