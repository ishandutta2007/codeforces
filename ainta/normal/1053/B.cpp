#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int w[301000], S[301000], C[301000][2];
long long res;
int main() {
	int i, j, k;
	scanf("%d", &n);
	long long x;
	for (i = 1; i <= n; i++) {
		scanf("%lld", &x);
		for (j = 0; j < 61; j++) {
			if ((x >> j) & 1)w[i]++;
		}
		S[i] = S[i - 1] + w[i];
	}
	for (i = 0; i <= n; i++) {
		C[i][S[i] % 2] = 1;
		if (i)C[i][0] += C[i - 1][0], C[i][1] += C[i - 1][1];
	}
	for (i = 1; i <= n; i++) {
		int Mx = -1, s = 0;
		for (j = i - 1; j >= i - 100 && j >= 0; j--) {
			Mx = max(Mx, w[j + 1]);
			s += w[j + 1];
			if (Mx * 2 > s || s & 1)continue;
			else res++;
		}
		if (i >= 101) res += C[i - 101][S[i] % 2];
	}
	printf("%lld\n", res);
}