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

template<int N, class T>
struct TreeMax {
  int n;
  typedef pair<T, int> pti;
  pti t[2*N];

  T& operator [](int p) { return t[n+p].X; }

  void build(int nn = 0) {
    if (nn != 0) n = nn;
    REP(i, n) t[n+i].Y = i;
    FORD(i, n-1, 1) t[i] = max(t[i<<1], t[i<<1|1]);
  }

  void upd(int p, T newv) {
    for (t[p += n].X = newv; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
  }

  pti get(int l, int r) {
    pti res = t[l += n];
    for (r += n-1; l <= r; l = (l+1)>>1, r = (r-1)>>1)
      smax(res, max(t[l], t[r]));
    return res;
  }
};

template<int N, class T>
struct TreeSum {
  int n;
  T t[2*N];

  T& operator [](int p) { return t[n+p]; }

  void build(int nn = 0) {
    if (nn != 0) n = nn;
    FORD(i, n-1, 1) t[i] = t[i<<1] + t[i<<1|1];
  }

  void inc(int p, T delta) {
    for (p += n; p > 0; p >>= 1) t[p] += delta;
  }

  void upd(int p, T newv) {
    for (t[p += n] = newv; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
  }

  T sum(int l, int r) {
    T res = 0;
    for (l += n, r += n-1; l <= r; l = (l+1)>>1, r = (r-1)>>1) {
      if ( l&1) res += t[l];
      if (~r&1) res += t[r];
    }
    return res;
  }
};


const int h = 100011;
int n, m;
int a[h];

TreeMax<h, int> tmax;
TreeSum<h, ll> tsum;

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%d", a+i);
  tmax.n = tsum.n = n;
  REP(i, n) tmax[i] = tsum[i] = a[i];
  tmax.build();
  tsum.build();
  REP(i, m) {
    int t, l, r, x;
    scanf("%d", &t);
    switch (t) {
    case 1:
      scanf("%d%d", &l, &r);
      printf("%I64d\n", tsum.sum(l-1, r));
      break;
    case 2:
      scanf("%d%d%d", &l, &r, &x);
      --l;
      do {
        pii u = tmax.get(l, r);
        if (u.X < x) break;
        u.X %= x;
        tmax.upd(u.Y, u.X);
        tsum.upd(u.Y, u.X);
      } while (true);
      break;
    case 3:
      scanf("%d%d", &l, &x);
      --l;
      tmax.upd(l, x);
      tsum.upd(l, x);
      break;
    }
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}