#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;

namespace FFT {
	const int MAX = 1 << 20;
	
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

int N;
char s[MAXN];
int v[MAXN], k[MAXN];
int d[MAXN];

void load() {
	scanf("%d%s", &N, s);
}

bool check(int p) {
	for (int i = p; i < N; i += p)
		if (d[N - 1 + i] || d[N - 1 - i])
			return false;
	return true;
}

void solve() {
	for (int i = 0; i < N; i++)
		v[i] = k[i] = 0;
		
	for (int i = 0; i < N; i++)
		if (s[i] == 'V')
			v[i]++;
		else if (s[i] == 'K')
			k[N - i - 1]++;
	
	FFT::mult(v, k, d, N);	

	vector <int> sol;
	for (int i = 1; i <= N; i++)
		if (check(i))
			sol.push_back(i);
		
	printf("%d\n", sol.size());
	for (auto it : sol)
		printf("%d ", it);
	puts("");
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		load();
		solve();
	}
	return 0;
}