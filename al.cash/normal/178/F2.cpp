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
#define FOR(i, a, b) for(int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i(a), _b(b); i >= _b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = 2*acos(0.0);

const int N = 2048;

complex<double> a[N], b[N];
complex<double> w[N], c[N], d[N];
void fft(complex <double> *a, complex <double> *b, int n, int add=1) {
    if (n == 1) { *b = *a; return; }
    fft(a, b, n/2, add*2);
    fft(a+add, b+n/2, n/2, add*2);
    REP (i, n/2)
        b[i] += b[i + n/2] * w[i*add];
    FOR (i, n/2, n)
        b[i] = b[i-n/2] - b[i] * w[(i-n/2)*add] + b[i] * w[i*add];
}

void mul(vi &va, vi &vb) {
  REP(i, sz(va)) a[i] = va[i];
  FOR(i, sz(va), N) a[i] = 0;
  REP(i, sz(vb)) b[i] = vb[i];
  FOR(i, sz(vb), N) b[i] = 0;
  fft(a, c, N);
  fft(b, d, N);
  REP (i, N) c[i] *= d[i];
  REP (i, N) w[i] = polar(1.0, -2*pi*i/N);
  fft(c, d, N);
}
// FORD (i,N-1,0) printf ("%d ", (int) (d[i].real()/N+1e-7));


void smax(int &a, int b) { if(a < b) a = b; }

const int h = 2002;

int n, k;
string s[h];

vi f(int l, int r, int d) {
  if (l+1==r) return vi(2, 0);
  //int l0 = l;
  vi a(r-l+1, 0);
  int kl = 0;
  while(l<r && sz(s[l])==d) ++kl, ++l;
  bool first = true;
  FOR(i, l+1, r+1) if(i==r || s[i-1][d] != s[i][d]) {
    vi t = f(l, i, d+1);
    FOR(j, 2, sz(t)) t[j] += j*(j-1)/2;
    if (first) {
      REP(j, sz(t)) a[j] = t[j];
      REP(j, kl) a[sz(t)+j] = a[sz(t)-1];
      first = false;
    } else {
      FORD(u, sz(a)-1, 0) FOR(j, 1, min(sz(t), sz(a)-u))
          smax(a[u+j], a[u] + t[j]);
    }
    l = i;
  }
  //printf("%d %d %d:", l0, r, d); REP(i, sz(a)) printf(" %d", a[i]); printf("\n");
  return a;
}

int main() {
  REP (i, N) w[i] = polar(1.0, 2*pi*i/N);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &k);
  char c[555];
  REP(i, n) {
    scanf("%s", c);
    s[i] = c;
  }
  sort(s, s+n);
  vi ans = f(0, n, 0);
  printf("%d\n", ans[k]);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}