#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
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

template<int N>
vi gen_primes(int n) {
  bitset<N/2> y;
  vi p;
  if (n >= 2) p.pb(2);
  y.set();
  REP(i, (n-1)/2) if (y[i]) {
    int v = 2*i+3;
    p.pb(v);
    for (int u = v, m = n/v; u <= m; u += 2) y.reset((v*u-3)/2);
  }
  return p;
}

const int N = 200002, A = 500005;
int n, q, a[N];
bool y[N];
vi d[N];
int k[A];

map<int, int> m;

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  vi p = gen_primes<A>(A);

  scanf("%d%d", &n, &q);
  REP(t, n) {
    scanf("%d", a + t);
    if (m.count(a[t])) continue;
    m[a[t]] = t;
    vi pd;
    int ta = a[t];
    for (int i = 0; i < sz(p) && sqr(p[i]) <= ta; ++i) if (ta % p[i] == 0) {
      pd.pb(p[i]);
      do { ta /= p[i]; } while (ta % p[i] == 0);
    }
    if (ta > 1) pd.pb(ta);

    d[t].reserve(1<<sz(pd));
    FOR(o, 1, 1<<sz(pd)) {
      int v = 1, b = 0;
      REP(i, sz(pd)) if (o>>i&1) v *= pd[i], ++b;
      d[t].pb(v * ((b&1) ? -1 : 1));
    }
  }

  fill_n(k, A, 0);
  fill_n(y, n, 0);
  ll tot = 0, ans = 0;

  REP(iq, q) {
    int x;
    scanf("%d", &x);
    --x;
    int i = m[a[x]];

//    printf("%d:\n", iq);
    ll cur = tot;
    for (int v : d[i]) {
      int iv = abs(v);
      if (v > 0) cur += k[iv];
      else cur -= k[iv];
//      printf("%d: %d (%I64d)\n", v, k[abs(v)], cur);
      if (y[x]) --k[iv];
      else ++k[iv];
    }
    if (a[x] == 1 && y[x]) --cur;

    if (y[x]) {
      --tot;
      ans -= cur;
      y[x] = false;
    } else {
      ++tot;
      ans += cur;
      y[x] = true;
    }

    cout << ans << '\n';
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}