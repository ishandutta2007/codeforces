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

const int N = 2*5005;
int n, x;
pii t[N];
int a[N], v[N];
ll d[N];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &x);
  REP(i, 2*n) scanf("%d", &t[i].X), t[i].Y = i;
  t[2*n] = {x, 2*n};
  int m = 2*n + 1;
  sort(t, t+m);
  int k = 0;
  REP(i, m) {
    if (i != 0 && t[i].X != t[i-1].X) ++k;
    a[t[i].Y] = k;
    v[k] = t[i].X;
  }
  ++k;
  REP(j, k) d[j] = abs(x - v[j]);
//  print("%d", d, d+k);

  REP(i, n) {
    int l = a[2*i], r = a[2*i+1];
    FORD(j, l-1, 0) {
      d[j] += v[l] - v[j];
      smin(d[j], d[j+1] + v[j+1] - v[j]);
    }
    FOR(j, r+1, k) {
      d[j] += v[j] - v[r];
      smin(d[j], d[j-1] + v[j] - v[j-1]);
    }
//    print("%d", d, d+k);
  }

  ll ans = INF_LL;
  REP(j, k) smin(ans, d[j]);
  cout << ans << endl;

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}