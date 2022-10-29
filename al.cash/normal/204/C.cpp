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

const int h = 200022;
int n;
char a[h], b[h];
ll sl[h], sr[h];

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%s%s", &n, a, b);
  //n = 200000; REP(i, n) a[i] = b[i] = 'A';
  ll s = 0, r = 0, k = 0;
  REP(l, n) k += ll(n - l) * (n - l);
  for (char c = 'A'; c <= 'Z'; ++c) {
    sl[0] = 0;
    REP(i, n) sl[i+1] = sl[i] + (b[i] == c ? i + 1 : 0);
    sr[n] = 0;
    FORD(i, n-1, 0) sr[i] = sr[i+1] + (b[i] == c ? n - i : 0);
    REP(i, n) if (a[i] == c) {
      if (b[i] == c) r += ll(i + 1) * (n - i);
      r += (i + 1) * sr[i + 1] + sl[i] * (n - i);
      if (r >= k) {
        s += r / k;
        r %= k;
      }
    }
  }
  //cout << s << ' ' << r << ' ' << k << endl;
  cout << s << '.';
  REP(p, 10) {
    r *= 10;
    ll q = r / k;
    r -= q * k;
    cout << q;
  }
  cout << endl;

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
}