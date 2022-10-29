#include <bits/stdc++.h>

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

int a[4];
typedef pair<double, double> pdd;
pdd b[4];
pdd f[2];

const double inf = 1e100;
void upd(pdd& x, double v) {
  smin(x.X, v);
  smax(x.Y, v);
}

void calc(pdd& x, pdd a, pdd b) {
  x = {inf, -inf};
  upd(x, a.X * b.X);
  upd(x, a.X * b.Y);
  upd(x, a.Y * b.X);
  upd(x, a.Y * b.Y);
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  REP(i, 4) scanf("%d", a+i);

  double l = 0, r = 1e9;
  REP(it, 100) {
    double d = (l + r) / 2;
    REP(i, 4) b[i] = {a[i] - d, a[i] + d};
    calc(f[0], b[0], b[3]);
    calc(f[1], b[1], b[2]);
    if (f[0].Y < f[1].X || f[1].Y < f[0].X) l = d;
    else r = d;
  }
  printf("%.10lf\n", (l + r) / 2);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}