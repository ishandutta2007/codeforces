#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define eb emplace_back
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1e9;
const ll INF_LL = 4e18;
const double pi = acos(-1.0);

template<class T> T& smin(T& a, const T& b) { if (a > b) a = b; return a; }
template<class T> T& smax(T& a, const T& b) { if (a < b) a = b; return a; }
template<class T> T sqr(const T& a) { return a * a; }

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
           const char* separator = " ", const char* closing = "\n") {
  for (Iterator it = begin; it != end; printf(fmt, *it),
       printf("%s", ++it == end ? closing : separator));
}

const int N = 1e5+5;
int n, m;
vector<pii> e[N];
int l[N], w[N];
pii tw[N];
pii p[N];
int l0[N], p0[N];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  REP(i, m) {
    int a, b, l;
    scanf("%d%d%d", &a, &b, &l);
    e[a].eb(b, l);
    e[b].eb(a, l);
  }

  CL(l0, -1);
  int z = n-1;
  l0[z] = 0;
  vi q = {z};
  for (int qa = 0; qa < sz(q); ++qa) {
    int v = q[qa];
    for (auto u : e[v]) if (u.Y == 0 && l0[u.X] == -1) {
      l0[u.X] = l0[v] + 1;
      p0[u.X] = v;
      q.pb(u.X);
    }
  }

  vector<int> s;
  set<int> t;
  CL(l, -1);
  l[0] = 0;
  w[0] = 0;
  s.pb(0);
  while (true) {
//    printf("iteration\n");
    int o = -1;
    for (auto v : s) if (l0[v] != -1) {
      if (o == -1) o = v;
      else if (w[v] == w[o] && l0[v] < l0[o]) o = v;
    }

    if (o != -1) {
      int v = o;
      for (int u = v; u != n-1; ) {
        v = u;
        u = p0[u];
        p[u] = {v, 0};
      }
      vi ans;
      bool zero = true;
      for (int u = n-1; u != 0; u = p[u].X) {
        ans.pb(u);
        if (p[u].Y != 0) zero = false;
        if (!zero) printf("%d", p[u].Y);
      }
      if (zero) printf("0");
      ans.pb(0);
      printf("\n%d\n", sz(ans));
      reverse(all(ans));
      print("%d", all(ans));
      break;
    }

    for (auto v : s) {
      for (auto c : e[v]) {
        int u = c.X;
        bool upd = false;
        if (l[u] == -1) {
          t.insert(u);
          l[u] = l[v] + 1;
          upd = true;
        } else if (l[u] == l[v] + 1 && tw[u] > pii(c.Y, w[v])) {
          upd = true;
        }
        if (upd) {
          tw[u] = {c.Y, w[v]};
          p[u] = {v, c.Y};
        }
      }
    }

    s.clear();
    for (auto it : t) s.pb(it);
    sort(all(s), [&](int i, int j) -> bool { return tw[i] < tw[j]; });
    int k = 0;
    REP(i, sz(s)) {
      if (i != 0 && tw[s[i-1]] != tw[s[i]]) ++k;
      w[s[i]] = k;
//      printf("%d(%d):%d ", s[i], l[s[i]], k);
    }
    t.clear();
//    printf("\n");
  }

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}