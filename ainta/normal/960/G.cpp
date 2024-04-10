#include <cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int aa[1 << 19], bb[1 << 19], cc[1 << 19];

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
vector<int>V[262144];
int Mod = 998244353;
void init(int *a, int p, int L) {
	for (int i = p; i < L; i++)a[i] = 0;
}
void Do(int nd, int b, int e) {
	if (b == e) {
		V[nd].push_back(b);
		V[nd].push_back(1);
		return;
	}
	int m = (b + e) >> 1;
	Do(nd * 2, b, m);
	Do(nd * 2 + 1, m + 1, e);
	int i;
	for (i = 0; i <= m - b + 1; i++) {
		aa[i] = V[nd*2][i];
	}
	for (i = 0; i <= e - m; i++) {
		bb[i] = V[nd*2+1][i];
	}
	int L = max(m-b+2,e - m + 1), tp = 1, cc = 0;
	while (tp < L)tp *= 2,cc++;
	tp *= 2,cc++;
	init(aa, m - b + 2, tp);
	init(bb, e - m + 1, tp);
	CC.init(cc);
	CC.FFT(aa, false);
	CC.FFT(bb, false);
	for (i = 0; i < tp; i++)aa[i] = 1ll * aa[i] * bb[i] % Mod;
	CC.FFT(aa, true);
	V[nd].resize(e - b + 2);
	for (i = 0; i <= e - b + 1; i++) {
		V[nd][i] = aa[i];
	}
}
long long F[201000], InvF[201000];
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r*a%Mod;
		a = a*a%Mod; b >>= 1;
	}
	return r;
}
int main() {
	int i, n, A, B;
	F[0] = InvF[0] = 1;
	for (i = 1; i <= 200000; i++) {
		F[i] = F[i - 1] * i%Mod;
	}
	InvF[200000] = Pow(F[200000], Mod - 2);
	for (i = 200000; i >= 1; i--)InvF[i - 1] = InvF[i] * i%Mod;
	scanf("%d%d%d", &n, &A, &B);
	if (n == 1) {
		if (A == 1 && B == 1)printf("1\n");
		else printf("0\n");
		return 0;
	}
	if (n == 2) {
		if (A == 2 && B == 1)printf("1\n");
		else if (A == 1 && B == 2)printf("1\n");
		else printf("0\n");
		return 0;
	}
	if (!A || !B || A + B == 2 || A+B-3>n-2) {
		printf("0\n");
		return 0;
	}
	Do(1, 1, n - 2);
	printf("%lld\n", V[1][A + B - 3] * F[A + B - 2] % Mod*InvF[A - 1] % Mod*InvF[B - 1] % Mod);
}