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

const int N = 1e5+5, mod = 1e9+7;
int n, m;
int l[N], f[N];
vector<pii> e[N];

bool dfs(int v) {
  for (auto t : e[v]) {
    int u = t.X, r = f[v] ^ t.Y;
    if (f[u] == -1) {
      l[u] = l[v] + 1;
      f[u] = r;
      if (!dfs(u)) return false;
    } else if (f[u]^r == (abs(l[u] - l[v])&1)) return false;
  }
  return true;
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  REP(i, m) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    e[a].eb(b, c);
    e[b].eb(a, c);
  }
  int ans = 1;

  CL(f, -1);
  FOR(i, 1, n+1) if (f[i] == -1) {
    l[i] = f[i] = 0;
    if (!dfs(i)) {
      ans = 0;
      break;
    }
    if (i != 1) {
      ans *= 2;
      if (ans >= mod) ans -= mod;
    }
  }

  printf("%d\n", ans);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}