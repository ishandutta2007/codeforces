#include<cstdio>
#include<algorithm>
#define N_ 1010000
using namespace std;
int n, C[N_], PV[N_], cnt, L[N_], R[N_], cc, CC[N_];
long long w[N_], K, P[N_], TP[N_], res;
int main() {
	int i, a, j;
	long long b;
	scanf("%d%lld", &n,&K);
	for (i = 2; i <= n; i++) {
		scanf("%d%lld", &a, &b);
		w[i] = w[a] ^ b;
	}
	sort(w + 1, w + n + 1);

	P[++cnt] = 0;
	C[cnt] = n;
	for (i = 1; i <= n; i++)PV[i] = 1;
	for (i = 61; i >= 0; i--) {
		cc = 0;
		int pp = 1;
		for (j = 1; j <= cnt; j++)L[j] = R[j] = 0;
		for (j = 1; j <= n; j++) {
			if (!cc || TP[cc] != (w[j] >> i)) {
				TP[++cc] = (w[j] >> i);
				while (P[pp] * 2 + 1 < TP[cc])pp++;
				if (P[pp] * 2 == TP[cc])L[pp] = cc;
				else R[pp] = cc;
			}
			CC[cc]++;
		}
		long long s = 0;
		for (j = 1; j <= n; j++) {
			int ck = (w[j] >> i) & 1;
			if (!ck) {
				s += CC[L[PV[j]]];
			}
			else {
				s += CC[R[PV[j]]];
			}
		}
		if (s >= K) {
			for (j = 1; j <= n; j++) {
				int ck = (w[j] >> i) & 1;
				if (!ck)PV[j] = L[PV[j]];
				else PV[j] = R[PV[j]];
			}
		}
		else {
			res += (1ll << i);
			K -= s;
			for (j = 1; j <= n; j++) {
				int ck = (w[j] >> i) & 1;
				if (!ck)PV[j] = R[PV[j]];
				else PV[j] = L[PV[j]];
			}
		}
		for (j = 1; j <= cc; j++) {
			C[j] = CC[j];
			CC[j] = 0;
			P[j] = TP[j];
			TP[j] = 0;
		}
		cnt = cc;
	}
	printf("%lld\n", res);
}