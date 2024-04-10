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

int p, q;

const int N = 2e6;
bitset<N/2> y;

void gen_primes() {
  y.set();
  REP(i, (N-1)/2) if (y[i]) {
    int v = 2*i+3;
    for (int u = v, m = N/v; u <= m; u += 2) y.reset((v*u-3)/2);
  }
}

bool is_prime(int v) {
  if (v == 1) return false;
  if (v == 2) return true;
  if (v % 2 == 0) return false;
  return y[(v-3)/2];
}

vi d;
bool is_pal(int v) {
  d.clear();
  while (v) d.pb(v%10), v /= 10;
  for (int i = 0, j = sz(d)-1; i < j; ++i, --j)
    if (d[i] != d[j]) return false;
  return true;
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
  
  scanf("%d%d", &p, &q);
  
  gen_primes();
  int pr = 0, pal = 0;
  int ans = 0;
  FOR(n, 1, N) {
    if (is_prime(n)) ++pr;
    if (is_pal(n)) ++pal;
    if (pr * q <= p * pal) ans = n;
  }
  printf("%d\n", ans);
  
#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}