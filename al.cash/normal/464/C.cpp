#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <complex>
#include <numeric>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define FORE(e, v) for (int e = head[v]; e >= 0; e = E[e].next)
#define UN(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T> T sqr(T a) { return a * a; }

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
    const char* separator = " ") {
  for (Iterator it = begin; it != end; ++it) {
    if (it != begin) printf(separator);
    printf(fmt, *it);
  }
  printf("\n");
}

const int mod = 1000000007;
void inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }
int add(int x, int y) { inc(x, y); return x; }
int mul(int x, int y) { return (ll(x) * y) % mod; }

template<class T> T qpow(const T& a, int p) {
  T res(1);
  for (T b(a); p; p >>= 1, b = mul(b, b))
    if (p & 1) res = mul(res, b);
  return res;
}

const int h = 100011;
int n;
string s[h];
char d[h], c;

const int T = 10;
int ten[T], rem[T];

char t[h];
void inp(string& s) {
  gets(t);
  s = t;
}

int main() {
#ifdef LocalHost
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  inp(s[0]);
  scanf("%d", &n);
  FOR(i, 1, n+1) {
    do { scanf("%c", d+i); } while (!isdigit(d[i]));
    scanf("%c%c", &c, &c);
    inp(s[i]);
  }

  REP(i, T) {
    ten[i] = 10;
    rem[i] = i;
  }

  int cten, crem;
  FORD(i, n, 0) {
    cten = 1;
    crem = 0;
    REP(j, sz(s[i])) {
      int u = s[i][j] - '0';
      cten = mul(cten, ten[u]);
      crem = add(mul(crem, ten[u]), rem[u]);
    }
    if (i > 0) {
      int u = d[i] - '0';
      ten[u] = cten;
      rem[u] = crem;
    }
  }

  printf("%d\n", crem);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}