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

const int M = 1000001;
int m;
int h[2], a[2], x[2], y[2];
int s[2], p[2], r[2];
int o[M];

void ans(ll v) {
  cout << v << endl;
  exit(0);
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &m);
  REP(i, 2) {
    scanf("%d%d%d%d", h+i, a+i, x+i, y+i);
    fill_n(o, m, -1);
    int v = h[i], t = 0;
    r[i] = -1;
    while (o[v] == -1) {
      if (v == a[i]) r[i] = t;
      o[v] = t;
      ++t;
      v = (ll(v) * x[i] + y[i]) % m;
    }
    s[i] = o[v];
    p[i] = t - o[v];
//    printf("s = %d p = %d r = %d\n", s[i], p[i], r[i]);
    if (r[i] == -1) ans(-1);
  }

  if (r[1] < s[1]) {
    swap(r[0], r[1]);
    swap(s[0], s[1]);
    swap(p[0], p[1]);
  }

  if (r[0] < s[0]) {
    if (r[1] < s[1]) {
      if (r[0] != r[1]) ans(-1);
      else ans(r[0]);
    } else {
      if (r[0] < s[1] || (r[0] - s[1]) % p[1] != (r[1] - s[1]) % p[1]) ans(-1);
      else ans(r[0]);
    }
  } else {
    ll v = r[0];
    REP(i, m) {
      if (v >= r[1] && (v - r[1]) % p[1] == 0) ans(v);
      v += p[0];
    }
  }
  ans(-1);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}