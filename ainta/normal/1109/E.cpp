#include<cstdio>
#include<algorithm>
#define SZ 131072
using namespace std;
int n, Mod;
int P[10], PC, A[101000], B[101000][10], Inv[101000], w[101000], po[2010000][10];
struct Tree {
	int U[SZ + SZ][10], K[SZ + SZ][10];
	void UDT(int nd) {
		int i;
		long long t1 = U[nd * 2][0], t2 = U[nd * 2 + 1][0];
		for (i = 1; i <= PC; i++) {
			int t = min(U[nd * 2][i], U[nd * 2 + 1][i]);
			U[nd][i] = t;
			t1 = t1*po[U[nd * 2][i] - t][i] % Mod;
			t2 = t2*po[U[nd * 2 + 1][i] - t][i] % Mod;
		}
		U[nd][0] = (t1 + t2) % Mod;
		K[nd][0] = 1;
	}
	void init(int nd, int b, int e) {
		if (b == e) {
			int x = w[b];
			int i;
			for (i = 1; i <= PC; i++) {
				U[nd][i] = B[x][i];
			}
			U[nd][0] = A[x];
			K[nd][0] = 1;
			return;
		}
		int m = (b + e) >> 1;
		init(nd * 2, b, m);
		init(nd * 2 + 1, m + 1, e);
		UDT(nd);
	}
	void Put2(int nd, int x) {
		int i;
		for (i = 1; i <= PC; i++) {
			U[nd][i] += B[x][i];
			K[nd][i] += B[x][i];
		}
		U[nd][0] = (long long)A[x] * U[nd][0] % Mod;
		K[nd][0] = (long long)A[x] * K[nd][0] % Mod;
	}
	void Spread(int nd) {
		int i;
		for (i = 1; i <= PC; i++) {
			U[nd * 2][i] += K[nd][i];
			U[nd * 2 + 1][i] += K[nd][i];
			K[nd * 2][i] += K[nd][i];
			K[nd * 2 + 1][i] += K[nd][i];
			K[nd][i] = 0;
		}
		U[nd * 2][0] = (long long)K[nd][0] * U[nd * 2][0] % Mod;
		U[nd * 2 + 1][0] = (long long)K[nd][0] * U[nd * 2 + 1][0] % Mod;
		K[nd * 2][0] = (long long)K[nd][0] * K[nd * 2][0] % Mod;
		K[nd * 2 + 1][0] = (long long)K[nd][0] * K[nd * 2 + 1][0] % Mod;
		K[nd][0] = 1;
	}
	void Put(int nd, int b, int e, int s, int l, int x) {
		if (b == s&&e == l) {
			Put2(nd, x);
			return;
		}
		Spread(nd);
		int m = (b + e) >> 1;
		if (s <= m)Put(nd * 2, b, m, s, min(m, l), x);
		if (l > m)Put(nd * 2 + 1, m + 1, e, max(m + 1, s), l, x);
		UDT(nd);
	}
	void Div(int nd, int b, int e, int s, int x) {
		if (b == s&&e == s) {
			int i;
			for (i = 1; i <= PC; i++) {
				U[nd][i] -= B[x][i];
				K[nd][i] -= B[x][i];
			}
			U[nd][0] = (long long)U[nd][0] * Inv[A[x]] % Mod;
			return;
		}
		Spread(nd);
		int m = (b + e) >> 1;
		if (s <= m)Div(nd * 2, b, m, s, x);
		else Div(nd * 2 + 1, m + 1, e, s, x);
		UDT(nd);
	}
	long long Get(int nd) {
		int i;
		long long r = U[nd][0];
		for (i = 1; i <= PC; i++)r = r*po[U[nd][i]][i] % Mod;
		return r;
	}
	long long Calc(int nd, int b, int e, int s, int l) {
		if (b == s&&e == l) {
			return Get(nd);
		}
		Spread(nd);
		int m = (b + e) >> 1;
		long long r = 0;
		if (s <= m)r = Calc(nd * 2, b, m, s, min(m, l));
		if (l > m)r += Calc(nd * 2 + 1, m + 1, e, max(m + 1, s), l);
		return r%Mod;
	}
}T;
int Pow(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1)r = 1ll * r*a%Mod;
		a = 1ll * a*a%Mod; b >>= 1;
	}
	return r;
}
int main() {
	scanf("%d%d", &n, &Mod);
	int i, j, PHI = Mod;
	int t = Mod;
	for (i = 2; i*i <= t; i++) {
		if (t%i == 0) {
			P[++PC] = i;
			while (t%i == 0)t /= i;
		}
	}
	if (t != 1)P[++PC] = t;
	for (i = 1; i <= PC; i++) {
		PHI = PHI / P[i] * (P[i] - 1);
	}
	for (i = 1; i <= 100000; i++) {
		int t = i;
		for (j = 1; j <= PC; j++) {
			while (t%P[j] == 0) {
				t /= P[j];
				B[i][j]++;
			}
		}
		A[i] = t;
		if (A[i] == i) {
			Inv[i] = Pow(i, PHI - 1);
		}
	}
	for (i = 1; i <= PC; i++)po[0][i] = 1;
	for (i = 1; i <= 2000000; i++) {
		for (j = 1; j <= PC; j++)po[i][j] = 1ll * po[i - 1][j] * P[j] % Mod;
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	T.init(1, 1, n);
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int ck, a, b, c;
		scanf("%d%d%d", &ck, &a, &b);
		if (ck == 1) {
			scanf("%d", &c);
			T.Put(1, 1, n, a, b, c);
		}
		if (ck == 2) {
			T.Div(1, 1, n, a, b);
		}
		if (ck == 3) {
			printf("%lld\n", T.Calc(1, 1, n, a, b));
		}
	}
}