#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <complex>
#include <numeric>
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

template<class T1, class T2>
ostream& operator << (ostream& out, const pair<T1, T2>& p) {
  out << p.X << ',' << p.Y;
  return out;
}
template<class T> void outp(const vector<T>& v) {
  cout << sz(v) << ":";
  REP(i, sz(v)) cout << " " << v[i];
  cout << endl;
}
template<class T> void outp(T* v, int n) {
  cout << n << ":";
  REP(i, n) cout << " " << *v++;
  cout << endl;
}

const int h = 24;
int n, c[h];
bool ok = true;

int t[h], k[h];
int sumt;

void go(int v) {
  if (ok) return;
  if (c[v] == 1) {
    if (sumt == n-v) ok = true;
  } else {
    REP(i, v) {
      t[i] -= c[v];
      if (t[i] > 0 || t[i] == 0 && k[i] > 0) {
        sumt -= c[v];
        ++k[i];
        go(v+1);
        --k[i];
        sumt += c[v];
      }
      t[i] += c[v];
    }
  }
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) scanf("%d", c+i);
  sort(c, c+n);
  reverse(c, c+n);
  if (c[0] != n) ok = false;
  if (count(c, c+n, 1) <= n/2) ok = false;
  if (count(c, c+n, 2) > 0) ok = false;
  if (ok) {
    sumt = 0;
    REP(i, n) {
      k[i] = 0;
      t[i] = c[i]-1;
      sumt += t[i];
    }
    if (n > 1) {
      ok = false;
      go(1);
    }
  }
  printf("%s\n", ok ? "YES" : "NO");

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}