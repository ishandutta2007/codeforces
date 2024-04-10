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

template<class T> void read(T& x){
  static char c;
  for (c = '\0'; c < '-'; c = getchar());
  bool neg = c == '-';
  if (neg) c = getchar();
  for (x = 0; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  if (neg) x = -x;
}

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
    const char* separator = " ") {
  for (Iterator it = begin; it != end; ++it) {
    if (it != begin) printf(separator);
    printf(fmt, *it);
  }
  printf("\n");
}

int n, a0, a1, app, ap, a;
bool l2;
ll v0, v1;

void calc() {
  ll c0 = max(v1 + abs(ap  - a0), v0 +           abs(ap  - a1));
  ll c1 = max(v1 + abs(app - a0), v0 + (l2 ? 0 : abs(app - a1)));
  v0 = c0;
  v1 = c1;
  //printf("%I64d %I64d\n", c0, c1);
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  read(n);  // scanf("%d", &n);
  v0 = v1 = 0;
  read(a);  // scanf("%d", &a);
  a0 = a1 = app = a;
  int u = 1;
  while (u < n) {
    ++u;
    read(a);  // scanf("%d", &a);
    if (a != a0) {
      a1 = a;
      break;
    }
  }
  ap = a;
  l2 = true;

  bool inc = a1 > a0;
  for (; u < n; ++u) {
    read(a);  // scanf("%d", &a);
    if (a == ap || inc == (a > ap)) {
      l2 = false;
    } else {
      calc();
      inc = !inc;
      a0 = ap;
      a1 = a;
      l2 = true;
    }
    app = ap;
    ap = a;
  }
  calc();
  cout << v0 << endl;

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}