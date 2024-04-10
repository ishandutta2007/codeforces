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

const int h = 111;
char t[h];
string s;

ll d[h];

ll f(char c) {
  int n = sz(s);
  d[0] = 1;
  d[1] = s[0] == c;
  FOR(i, 1, n) {
    if (s[i] == 'A') {
      d[i+1] = d[i];
      if (s[i-1] == 'B' && (i != 1 || c == 'A')) d[i+1] += d[i-1];
    } else {
      d[i+1] = 0;
      if (s[i-1] == 'B') d[i+1] = d[i];
      else if (i > 1 && s[i-2] == 'B' && (i != 2 || c == 'A')) d[i+1] = d[i-2];
    }
  }
  //cout << s << ": "; REP(i, n+1) cout << d[i] << ' '; cout << endl;
  return d[n];
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%s", t);
  s = t;
  int n = sz(s);
  ll ans = f('A');
  if (s[0] == 'A' && s[n-1] == 'B') {
    s = s.substr(1, n - 2);
    ans += f('A') + f('B');
  } else if (s[0] == 'B') {
    s = s.substr(1, n-1);
    reverse(all(s));
    REP(i, sz(s)) s[i] = 'A' + 'B' - s[i];
    ans += f('A');
  }
  cout << ans << endl;

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
}