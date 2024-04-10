#include <cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int aa[1 << 23];

class NTT {
public:
	const int A = 119, B = 23, P = A << B | 1, R = 3;
	int SZ, N;

	void init(int sz) {
		SZ = sz;
		N = (1 << sz);
	}

	int Pow(int x, int y) {
		int r = 1;
		while (y) {
			if (y & 1) r = (long long)r * x % P;
			x = (long long)x * x % P;
			y >>= 1;
		}
		return r;
	}


	void FFT(int *a, bool f) {
		int i, j, k, x, y, z;
		j = 0;
		for (i = 1; i < N; i++) {
			for (k = N >> 1; j >= k; k >>= 1) j -= k;
			j += k;
			if (i < j) {
				k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
		for (i = 1; i < N; i <<= 1) {
			x = Pow(f ? Pow(R, P - 2) : R, P / i >> 1);
			for (j = 0; j < N; j += i << 1) {
				y = 1;
				for (k = 0; k < i; k++) {
					z = (long long)a[i | j | k] * y % P;
					a[i | j | k] = a[j | k] - z;
					if (a[i | j | k] < 0) a[i | j | k] += P;
					a[j | k] += z;
					if (a[j | k] >= P) a[j | k] -= P;
					y = (long long)y * x % P;
				}
			}
		}
		if (f) {
			j = Pow(N, P - 2);
			for (i = 0; i < N; i++) a[i] = (long long)a[i] * j % P;
		}
	}
}CC;
int n, w[1<<21], cnt, D[100], bb[1<<21];
char p[1600000];
int main() {
	int i, n, j, M = 0;
	for (i = 1; i <= 100; i++) {
		if (i <= 5)D[i] = i;
		else D[i] = D[(i + 2) / 3] + 3;
	}
	scanf("%s", p);
	//for (i = 0; i < 1490000; i++)p[i] = '1';
	for (i = 0; p[i]; i++);
	n = i;
	if (n == 1 && p[0] <= '4') {
		printf("%d\n", p[0] - '0');
		return 0;
	}
	int c = 0;
	for (i = n - 1; i >= 0; i--) {
		w[c++] = (p[i] - '0');
	}
	int t = (int)((logl(10) / logl(3))*(n - 1) + logl(p[0] - '0') / logl(3));
	if (t >= 1)t--;
	aa[0] = 1;
	for (i = 30; i >= 0; i--) {
		int c = 0;
		while ((1 << c) < (M + 1) * 2)c++;
		CC.init(c);
		CC.FFT(aa, false);
		for (j = 0; j < (1 << c); j++) {
			aa[j] = (long long)aa[j] * aa[j] % CC.P;
		}
		CC.FFT(aa, true);
		for (j = 0; j <= M * 2 + 10; j++) {
			aa[j + 1] += aa[j]/10;
			aa[j] %= 10;
			if (aa[j])M = j;
		}
		if ((t >> i) & 1) {
			for (j = 0; j <= M; j++) aa[j] *= 3;
			for (j = 0; j <= M; j++) {
				aa[j + 1] += aa[j] / 10;
				aa[j] %= 10;
			}
			if (aa[M + 1])M++;
		}
	}
	M += 2;
	M = max(M, c / 4 + 1);
	for (i = 1;; i++) {
		for (j = 0; j < M; j++) {
			bb[j] = aa[j] * i;
		}
		for (j = 0; j < M; j++) {
			bb[j + 1] += bb[j] / 10;
			bb[j] %= 10;
		}
		int ck = 0;
		for (j = M; j >= 0; j--) {
			if (bb[j] != w[j]) {
				if (bb[j] > w[j])ck = 1;
				break;
			}
		}
		if (j == -1)ck = 1;
		if (ck == 1)break;
	}
	D[1] = 0;
	printf("%d\n", t * 3 + D[i]);
}