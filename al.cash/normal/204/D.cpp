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
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define FORE(e, v) for (int e = head[v]; e >= 0; e = E[e].next)
#define UN(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T> T sqr(T a) { return a * a; }

template<class T> void outp(const vector<T>& v) {
  REP(i, sz(v)) cout << v[i] << (i + 1 == sz(v) ? '\n' : ' ');
}
template<class T> void outp(T* v, int n) {
  REP(i, n) cout << *v++ << (i + 1 == n ? '\n' : ' ');
}

const int mod = 1000000007;
void inc(int& a, int b) { a += b; if (a >= mod) a -= mod; }
void dec(int& a, int b) { a -= b; if (a < 0) a += mod; }
int sum(int a, int b) { inc(a, b); return a; }
int mul(int a, int b) { return ll(a) * b % mod; }

const int h = 1000011;
int n, k;
char s[h];
int kb[h], kw[h];

int nb[h], nw[h];
int aw[h], ans;

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%s", &n, &k, s);
  kb[0] = kw[0] = 0;
  REP(i, n) {
    kb[i+1] = kb[i] + (s[i] == 'B' ? 1 : 0);
    kw[i+1] = kw[i] + (s[i] == 'W' ? 1 : 0);
  }
  nb[0] = 1;
  REP(i, n) {
    nb[i+1] = mul(s[i] == 'X' ? 2 : 1, nb[i]);
    if (i >= k-1 && kw[i+1] == kw[i-k+1]) {
      if (i == k-1) dec(nb[i+1], 1);
      else if (s[i-k] != 'B') dec(nb[i+1], nb[i-k]);
    }
  }
  nw[n] = 1;
  FORD(i, n-1, 0) {
    nw[i] = mul(s[i] == 'X' ? 2 : 1, nw[i+1]);
    if (i+k <= n && kb[i] == kb[i+k]) {
      if (i+k == n) dec(nw[i], 1);
      else if (s[i+k] != 'W') dec(nw[i], nw[i+k+1]);
    }
  }
  CL(aw, 0);
  FORD(i, n-k, 0) {
    aw[i] = mul(s[i] == 'X' ? 2 : 1, aw[i+1]);
    if (kb[i] == kb[i+k]) {
      if (i+k == n) inc(aw[i], 1);
      else if (s[i+k] != 'W') inc(aw[i], nw[i+k+1]);
    }
  }
  ans = 0;
  REP(i, n-2*k+1) {
    int c = 0;
    if (kw[i] == kw[i+k]) {
      if (i == 0) c = 1;
      else if (s[i-1] != 'B') c = nb[i-1];
    }
    inc(ans, mul(c, aw[i+k]));
  }
  printf("%d\n", ans);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
}