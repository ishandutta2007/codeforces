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
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T> T sqr(T a) { return a * a; }

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
    const char* separator = " ") {
  for (Iterator it = begin; it != end; ++it) {
    if (it != begin) printf(separator);
    printf(fmt, *it);
  }
  printf("\n");
}

const int N = 100011, M = 11, Q = N, C = 10001;
const pii INFP(-2, -2);
int n, m, q;
char s[N][M];
int v[N][M];
pii r[N][M];

int x[Q], y[Q];
char o[Q];

vector<pii> p;
pii f[C];

void go(int i, int j, int jp) {
  if (r[i][j].Y <= m) return;
  if (s[i][j] == '^') {
    if (i == 0 || v[i-1][j] != -1) r[i][j] = pii(i-1, j);
    else r[i][j] = r[i-1][j];
  } else {
    int jn = s[i][j] == '<' ? j-1 : j+1;
    if (jn == -1 || jn == m || v[i][jn] != -1) r[i][j] = pii(i, jn);
    else if (jn == jp) r[i][j] = INFP;
    else {
      go(i, jn, j);
      r[i][j] = r[i][jn];
    }
  }
}

void gof(int i, int ip) {
  if (f[i].Y <= m) return;
  pii a = r[p[i].X][p[i].Y];
  if (0 <= a.X && a.X < n && 0 <= a.Y && a.Y < m) {
    int in = v[a.X][a.Y];
    if (in == ip) f[i] = INFP;
    else {
      gof(in, i);
      f[i] = f[in];
    }
  } else {
    f[i] = a;
  }
}

void calcf() {
  CL(f, 1);
  REP(i, sz(p)) gof(i, INF);
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d", &n, &m, &q);
  REP(i, n) scanf("%s", s+i);
  CL(v, -1);
  REP(t, q) {
    do { scanf("%c", o+t); } while (o[t] != 'A' && o[t] != 'C');
    scanf("%d%d", x+t, y+t);
    --x[t]; --y[t];
    if (o[t] == 'C') {
      p.pb(pii(x[t], y[t]));
      scanf("%c%c", o+t, o+t);
    }
  }

  UN(p);
  REP(i, sz(p)) v[p[i].X][p[i].Y] = i;

  CL(r, 1);
  REP(i, n) {
    REP(j, m) go(i, j, INF);
  }
  calcf();

  REP(t, q) {
    if (o[t] == 'A') {
      pii a = r[x[t]][y[t]];
      if (0 <= a.X && a.X < n && 0 <= a.Y && a.Y < m) a = f[v[a.X][a.Y]];
      printf("%d %d\n", a.X + 1, a.Y + 1);
    } else {
      s[x[t]][y[t]] = o[t];
      r[x[t]][y[t]] = pii(INF, INF);
      go(x[t], y[t], INF);
      calcf();
    }
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}