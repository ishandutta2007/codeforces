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
           const char* delimiter = " ", const char* closing = "\n") {
  for (; begin != end; ++begin != end ? printf("%s", delimiter) : 0)
    printf(fmt, *begin);
  printf("%s", closing);
}

const int N = 30;
int n, d[N][3];

struct S {
  int v0, d1, d2, m;
  S(int v0 = 0, int d1 = 0, int d2 = 0, int m = 0) : v0(v0), d1(d1), d2(d2), m(m) {}

  bool operator == (const S& b) const {
    return d1 == b.d1 && d2 == b.d2;
    //    return d1 < b.d1 || (d1 == b.d1 && d2 < b.d2 || d2 == b.d2 && v0 < b.v0);
  }

  bool operator < (const S& b) const {
    return d1 < b.d1 || (d1 == b.d1 && d2 < b.d2);
//    return d1 < b.d1 || (d1 == b.d1 && d2 < b.d2 || d2 == b.d2 && v0 < b.v0);
  }

  void outp() { printf("%d %d %d %d\n", v0, d1, d2, m); }
};

vector<S> h1, h2;

void go(int i, int l, vi v, int m, vector<S>& h) {
  if (i == l) {
    h.eb(v[0], v[1]-v[0], v[2]-v[0], m);
    return;
  }
  m *= 3;
  REP(p, 3) {
    REP(u, 3) if (u != p) v[u] += d[i][u];
    go(i+1, l, v, m+p, h);
    REP(u, 3) if (u != p) v[u] -= d[i][u];
  }
}

int ans = -INF, m1, m2;

void outp(int m, int l) {
  vector<string> s;
  REP(i, l) {
    int r = m % 3;
    if (r == 0) s.pb("MW");
    if (r == 1) s.pb("LW");
    if (r == 2) s.pb("LM");
    m /= 3;
  }
  reverse(all(s));
  REP(i, l) printf("%s\n", s[i].c_str());
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) REP(j, 3) scanf("%d", d[i]+j);
  int l = n / 2;
  vi v(3, 0);
  go(0, l, v, 0, h1);
  go(l, n, v, 0, h2);
  sort(all(h1));
  for (auto& t : h2) t.d1 = -t.d1, t.d2 = -t.d2;
  sort(all(h2));
//  printf("h1: %d\n", sz(h1));
//  for (auto& t: h1) t.outp();
//  printf("h2 %d\n", sz(h2));
//  for (auto& t: h2) t.outp();
//  return 0;
  for (int i1 = 0, i2 = 0; i1 < sz(h1) && i2 < sz(h2); ) {
    if (h1[i1] < h2[i2]) ++i1;
    else if (h2[i2] < h1[i1]) ++i2;
    else {  // equal
      pii a1 = {h1[i1].v0, h1[i1].m};
      while (true) {
        ++i1;
        if (i1 < sz(h1) && h1[i1] == h1[i1-1]) {
          if (h1[i1].v0 > a1.X) a1 = {h1[i1].v0, h1[i1].m};
        } else break;
      }
      pii a2 = {h2[i2].v0, h2[i2].m};
      while (true) {
        ++i2;
        if (i2 < sz(h2) && h2[i2] == h2[i2-1]) {
          if (h2[i2].v0 > a2.X) a2 = {h2[i2].v0, h2[i2].m};
        } else break;
      }
      if (a1.X + a2.X > ans) {
        ans = a1.X + a2.X;
        m1 = a1.Y;
        m2 = a2.Y;
      }
    }
  }
  if (ans == -INF) printf("Impossible\n");
  else {
    outp(m1, l);
    outp(m2, n-l);
  }

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}