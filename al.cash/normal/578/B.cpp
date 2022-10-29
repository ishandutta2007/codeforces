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
           const char* separator = " ", const char* closing = "\n") {
  for (Iterator it = begin; it != end; printf(fmt, *it),
       printf("%s", ++it == end ? closing : separator));
}

const int N = 2e5+5;
int n, k, x, a[N];
ll l[N], r[N];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d", &n, &k, &x);
  ll xp = 1;
  REP(i, k) xp *= x;
  REP(i, n) scanf("%d", a+i);
  l[0] = 0;
  REP(i, n) l[i+1] = l[i] | a[i];
  r[n] = 0;
  FORD(i, n-1, 0) r[i] = r[i+1] | a[i];
  ll ans = l[n];
  REP(i, n) {
    ll t = l[i] | r[i+1];
    smax(ans, t | (a[i] * xp));
  }
  cout << ans << endl;

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}