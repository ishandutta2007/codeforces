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

const int N = 2e5+4;
int n, k;
int a[N];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &k);
  int m = n - k;
  REP(i, n) scanf("%d", a+i);
  int k0 = 0, k1 = 0;
  REP(i, n) {
    if (a[i]&1) ++k1;
    else ++k0;
  }
  int ans = 0;

  if (m == 0) {
    ans = (k1 % 2 == 0) ? 1 : 0;
  } else {
    if (m&1) {
      if (m / 2 >= k1 || (m / 2 >= k0 && k % 2 == 0)) ans = 1;
      else ans = 0;
    } else {
      if (m / 2 >= k0 && k % 2 == 1) ans = 0;
      else ans = 1;
    }
  }

  printf("%s\n", ans == 0 ? "Stannis" : "Daenerys");

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}