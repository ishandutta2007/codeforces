#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXL = 5e5 + 5;

namespace FFT {
  #define FOR(i, a, b) for (int i = (a); i < (b); ++i)
  #define REP(i, n) FOR(i, 0, n)

  const int MAX = 1 << 20;
  
  typedef complex<double> comp;

  int N;
  comp omega[MAX];
  comp a1[MAX], a2[MAX];
  comp z1[MAX], z2[MAX];

  void fft(comp *a, comp *z, int m = N) {
    if (m == 1) {
      z[0] = a[0];
    } else {
      int s = N/m;
      m /= 2;

      fft(a, z, m);
      fft(a+s, z+m, m);

      REP(i, m) {
        comp c = omega[s*i] * z[m+i];
        z[m+i] = z[i] - c;
        z[i] += c;
      }
    }
  }

  void mult(int *a, int *b, int *c, int len) {
    N = 2*len;
    while (N & (N-1)) ++N;
    assert(N <= MAX);

    REP(i, N) a1[i] = 0;
    REP(i, N) a2[i] = 0;
    REP(i, len) a1[i] = a[i];
    REP(i, len) a2[i] = b[i];

    REP(i, N) omega[i] = polar(1.0, 2*M_PI/N*i);
    fft(a1, z1, N);
    fft(a2, z2, N);

    REP(i, N) omega[i] = comp(1, 0) / omega[i];
    REP(i, N) a1[i] = z1[i] * z2[i] / comp(N, 0);
    fft(a1, z1, N);

    REP(i, 2*len) c[i] = round(z1[i].real());
  }
}

int N, X, Y;
int ans[MAXL];
int a[MAXN], b[MAXN];
int c[2 * MAXN];

void load() {
  scanf("%d%d%d", &N, &X, &Y);
  for (int i = 0; i <= N; i++) {
    int x;
    scanf("%d", &x);
    a[x] = b[X - x] = 1;
  }
}

void solve() {
  FFT::mult(a, b, c, X + 1);
  memset(ans, -1, sizeof ans);
  for (int i = X + 1; i < 2 * MAXN; i++) 
    if (c[i]) {
      int divisor = i - X + Y;
      for (int j = divisor; j < MAXL; j += divisor)
        ans[j] = 2 * divisor;
    }
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int len;
    scanf("%d", &len);
    printf("%d ", ans[len / 2]);
  }
  puts("");
}

int main() {
  load();
  solve();
  return 0;
}