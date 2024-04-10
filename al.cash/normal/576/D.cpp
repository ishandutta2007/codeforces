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

const int N = 155;
struct F {
  int a, b, d;
  void inp() {
    scanf("%d%d%d", &a, &b, &d);
    --a;
    --b;
  }
} f[N];

bool cmp(const F& a, const F& b) { return a.d < b.d; }

int n, m;

const int P = 1e5;
vi s[P];
map<vi, int> u;

void outp(const vi& a) {
  REP(i, n) printf("%d", (a[i/32] & 1 << (i%32)) ? 1 : 0);
  printf("\n");
}

void calc(vi& a, vi& b, int m) {
  REP(i, sz(b)) b[i] = 0;
  REP(i, m) if (a[f[i].a/32] & 1 << (f[i].a%32))
    b[f[i].b/32] |= 1 << (f[i].b%32);
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  REP(i, m) f[i].inp();
  sort(f, f+m, cmp);
  f[m].d = 2 * INF;

  int l = (n + 31) / 32;
  REP(i, P) s[i].resize(l);
  s[0][0] = 1;

  int dst = n-1;
  int t = 0;
  REP(e, m+1) {
    int t0 = t, c = 0;
//    printf("%d: %d\n", e, t0);
//    outp(s[0]);
    u.clear();
    u[s[0]] = 0;
    bool found = false;
    while (t < f[e].d) {
      calc(s[c], s[c+1], e);
      ++t;
      ++c;
//      printf("%d: ", t);
//      outp(s[c]);
      if (s[c][dst/32] & 1 << (dst%32)) {
        printf("%d\n", t);
        return 0;
      }
      if (!found) {
        if (u.count(s[c])) {
          int p = c - u[s[c]];
          int k = (f[e].d - t) / p;
//          printf("found period starting at %d with length %d\n", t, p);
          t += k * p;
          found = true;
        } else {
          u[s[c]] = c;
        }
      }
    }
    s[0] = s[c];
  }
  printf("Impossible\n");

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}