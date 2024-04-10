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

const int INF = 2e9 + 1;
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

const int N = 2e5+5;
int n, m;
pii x[N];
int u[N], r[N];

int bs(int a, int b, int i, int l) {
  while (abs(a - b) != 1) {
    int t = (a + b) / 2;
    if (l >= abs(x[t].X - x[i].X)) a = t;
    else b = t;
  }
  return a;
}

int f(int i, int l) {
  if (l < r[i]) return i;
  int j;
  if (i < n-1 && l >= x[i+1].X - x[i].X) j = bs(i + 1, n, i, l);
  else j = bs(i - 1, -1, i, l);

  int d = abs(x[i].X - x[j].X);
  l -= d;
  if (i < j && (i == 0 || x[j].X > x[i-1].X + l) &&
      (j == n-1 || x[j+1].X > x[j].X + l)) l %= 2LL * d;

  return f(j, l);
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%d", &x[i].X), x[i].Y = i;
  sort(x, x+n);
  REP(i, n) u[x[i].Y] = i;

  REP(i, n) r[i] = INF;
  REP(i, n-1) {
    int l = x[i+1].X - x[i].X;
    smin(r[i], l);
    smin(r[i+1], l);
  }

  if (n == 1) {
    REP(q, m) printf("1\n");
    return 0;
  }

  REP(q, m) {
    int a, l;
    scanf("%d%d", &a, &l);
    printf("%d\n", x[f(u[a-1], l)].Y + 1);
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}