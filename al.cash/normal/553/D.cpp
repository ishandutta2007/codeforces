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

const int N = 1e5+5;
int n, m, k;
bool s[N];
int f[N];
vi e[N];
vi o;

struct S {
  int i, f;
  S(int i = 0, int f = 0) : i(i), f(f) {}
};

bool operator < (const S& a, const S& b) {
  return ll(a.f) * sz(e[b.i]) > ll(b.f) * sz(e[a.i]);
}

priority_queue<S> q;

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d", &n, &m, &k);

  o.reserve(n);
  REP(i, n) s[i] = true;
  REP(i, k) {
    int a;
    scanf("%d", &a);
    --a;
    o.pb(a);
    s[a] = false;
  }

  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a; --b;
    e[a].pb(b);
    e[b].pb(a);
    if (s[a] && s[b]) ++f[a], ++f[b];
  }

  REP(i, n) if (s[i]) q.emplace(i, f[i]);

  S opt;
  while (!q.empty()) {
    S x = q.top();
    q.pop();
    if (x.f != f[x.i]) continue;
    if (x < opt) {
      k = sz(o);
      opt = x;
    }
    o.pb(x.i);
    s[x.i] = false;
    for (int j : e[x.i]) if (s[j]) q.emplace(j, --f[j]);
  }

//  cout << opt << endl;
  printf("%d\n", n - k);
  o.resize(k);
  sort(all(o));
  int u = 0;
  REP(i, n) {
    if (u < k && i == o[u]) ++u;
    else printf("%d ", i+1);
  }
  printf("\n");

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}