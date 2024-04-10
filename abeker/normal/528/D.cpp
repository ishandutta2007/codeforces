#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005;

namespace FFT {
  const int MAX = 1 << 19;
	
  typedef complex<double> comp;
	#define REP(i, n) for (int i = 0; i < n; i++)
	
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

int N, M, K;
char s[MAXN], t[MAXN];
int occ[MAXN];
int a[MAXN], b[MAXN], c[MAXN];

void load() {
	scanf("%d%d%d%s%s", &N, &M, &K, s, t);
}

void work(char ltr) {
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	int cnt = 0;
	for (int i = 0; i < M; i++)
		if (t[i] == ltr) {
			a[M - i - 1]++;
			cnt++;
		}
	for (int i = 0; i < N; i++)
		if (s[i] == ltr) {
			b[max(i - K, 0)]++;
			b[min(i + K, N - 1) + 1]--;
		}
	for (int i = 1; i < N; i++)
		b[i] += b[i - 1];
	for (int i = 0; i < N; i++)
		b[i] = !!b[i];
	FFT::mult(a, b, c, N);
	for (int i = 0; i + M - 1 < N; i++)
		if (c[i + M - 1] == cnt)
			occ[i]++;
}

int solve() {
	for (int i = 0; i < 4; i++)
		work("ATGC"[i]);
		
	int sol = 0;
	for (int i = 0; i < N; i++)
		sol += occ[i] == 4;
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}