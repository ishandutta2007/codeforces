// LastDay@TB
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long int LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(), a.end()
#define SET(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define si(n) scanf("%d", &n)
#define dout(n) printf("%d\n", n)
#define sll(n) scanf("%lld", &n)
#define lldout(n) printf("%lld\n", n)
#define fast_io                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

// FILE *fin = freopen("in","r",stdin);
// FILE *fout = freopen("out","w",stdout);
const int N = 5e5 + 10;
int A[N];
bool isPossible[N];
VI g[N];
int main() {
  int n;
  si(n);
  int m;
  si(m);
  REP(i, n) {
    si(A[i]);
    A[i]--;
  }
  REP(i, m) {
    int x, y;
    si(x);
    si(y);
    x--;
    y--;
    g[x].PB(y);
    if (y == A[n - 1]) {
      isPossible[x] = true;
    }
  }
  int ans = 0;
  set<int> S;
  for (int i = n - 1; i >= 0; i--) {
    bool swapped = false;
    if (isPossible[A[i]]) {
      int num_back = 0;
      for (auto& y : g[A[i]]) {
        num_back += S.count(y);
      }
      if (num_back == S.size()) {
        ans++;
        swapped = true;
      }
    }
    if (!swapped) {
      S.insert(A[i]);
    }
  }
  cout << ans << endl;

  return 0;
}