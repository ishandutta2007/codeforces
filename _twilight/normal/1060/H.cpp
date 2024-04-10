#include <bits/stdc++.h>
using namespace std;

const int p1 = 15, p0 = 16, pmul = 17, pq1 = 18, pq2 = 19;

int d, p;
int C[12][12], pw[12][12];

int qpow(int a, int x) {
	int rt = 1;
	for ( ; x; x >>= 1, a = 1ll * a * a % p) {
		if (x & 1) {
			rt = 1ll * rt * a % p;
		}
	}
	return rt;
}

void add(int x, int y, int z) {
	cout << "+ " << x << " " << y << " " << z << '\n';
}
void prepare() {
	int t = 30;
	while (!((p >> t) & 1))
		t--;
	for ( ; t--; ) {
		add(p0, p0, p0);
		if ((p >> t) & 1) {
			add(p0, p1, p0);
		}
	}

	C[0][0] = 1;
	for (int i = 1; i <= d; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
		}
	}
}

void reset(int x) {
	add(p0, p0, x);
}
void mul(int x, int y, int z) {
	add(x, p0, pmul);
	reset(z);
	for (int i = y; i; i >>= 1, add(pmul, pmul, pmul)) {
		if (i & 1) {
			add(z, pmul, z);
		}
	}
}

void pow_d(int x, int z) {
	cout << "^ " << x << " " << z << '\n';
}

void square(int x, int y) {
	reset(y);
	add(p0, x, pq1);
	int t = d - 2;
	int coef2 = 0, coef1 = 0, coef0 = 0;
	for (int i = 0; i <= t; i++) {
		pow_d(pq1, pq2);
		int coef = C[t][i];
		if (i & 1) {
			coef = (p - coef) % p;
		}
		coef2 = (coef2 + 1ll * qpow(i, t) * coef) % p;
		coef1 = (coef1 + 1ll * qpow(i, t + 1) * coef) % p;
		coef0 = (coef0 + 1ll * qpow(i, t + 2) * coef) % p;
		mul(pq2, coef, pq2);
		add(pq2, y, y);
		add(pq1, p1, pq1);
	}
	coef2 = 1ll * coef2 * (((t + 1) * (t + 2)) >> 1) % p;
	coef1 = 1ll * coef1 * (t + 2) % p;
	assert(coef2);
	mul(x, p - coef1, pq1);
	add(pq1, y, y);
	mul(p1, p - coef0, pq1);
	add(pq1, y, y);
	coef2 = qpow(coef2, p - 2);
	mul(y, coef2, y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> d >> p;
	prepare();
	square(1, 3);
	square(2, 4);
	add(1, 2, 1);
	square(1, 5);
	mul(3, p - 1, 3);
	mul(4, p - 1, 4);
	add(3, 5, 5);
	add(4, 5, 5);
	mul(5, (p + 1) >> 1, 5);
	cout << "f 5\n"; 
	return 0;
}