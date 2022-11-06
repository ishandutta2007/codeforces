#include <bits/stdc++.h>

#pragma GCC optimize(3)

#define rep(i, a, b) for (int i = a, i##end = b; i <= i##end; ++i)
#define per(i, a, b) for (int i = a, i##end = b; i >= i##end; --i)
#define rep0(i, a) for (int i = 0, i##end = a; i < i##end; ++i)
#define per0(i, a) for (int i = (int)a-1; ~i; --i)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define x first
#define y second
#define enter putchar('\n')

typedef long long ll;

inline int read() {
	int w = 0, f = 1; char c;
	while (!isdigit(c = getchar())) c == '-' && (f = -1);
	while (isdigit(c)) w = w*10+(c^48), c = getchar();
	return w * f;
}

const int maxn = 50000 + 5;
const int P = 998244353, g = 3;

int inc(int a, int b) { return (a += b) >= P ? a-P : a; }
int mul(int a, int b) { return 1ll*a*b%P; }

int qpow(int a, int b) {
	int t = 1;
	for (; b; b >>= 1, a = mul(a, a))
		if (b & 1) t = mul(t, a);
	return t;
}

int W[maxn*4], inv[maxn*4];

void prework(int n) {
	for (int i = 1; i < n; i <<= 1) {
		W[i] = 1;
		for (int j = 1, Wn = qpow(g, (P-1)/i>>1); j < i; j++) W[i+j] = mul(W[i+j-1], Wn);
	}
	inv[1] = 1;
	rep(i, 2, n) inv[i] = 1ll*(P-P/i)*inv[P%i]%P;
}

void NTT(int a[], int n, int opt) {
	static int rev[maxn*2] = {0};
	for (int i = 1; i < n; i++)
		if ((rev[i] = rev[i>>1]>>1|(i&1?n>>1:0)) > i) std::swap(a[i], a[rev[i]]);
	for (int q = 1; q < n; q <<= 1)
		for (int p = 0; p < n; p += q << 1)
			for (int i = 0, t; i < q; i++)
				t = mul(a[p+q+i], W[q+i]), a[p+q+i] = inc(a[p+i], P-t), a[p+i] = inc(a[p+i], t);
	if (~opt) return;
	std::reverse(a+1, a+n);
	rep0(i, n) a[i] = mul(a[i], inv[n]);
}

int getsz(int n) { int x = 1; while (x < n) x <<= 1; return x; }

struct Poly {
	int len; std::vector<int> A;
	Poly(int n = 0) {
		if (n > 0) { A.resize(len = n); rep0(i, n) A[i] = read(); }
		else A.resize(len = 1), A[0] = -n;
	}
	int &operator [] (int i) { return A[i]; }
	void load(int a[], int n) {
		A.resize(len = n);
		memcpy(&A[0], a, sizeof(int) * n);
	}
	void cpyto(int a[], int n) {
		memcpy(a, &A[0], sizeof(int) * min(n, len));
	}
	void write() {
		per0(i, len) printf("%d ", A[i]); enter;
	}
	void resize(int n = 0) {
		if (!n) while (len > 1 && !A[len-1]) len--; else len = n;
		A.resize(len, 0);
	}
};

Poly operator + (Poly A, Poly B) {
	if (A.len < B.len) std::swap(A, B);
	rep0(i, B.len) A[i] = inc(A[i], B[i]);
	return A.resize(), A;
}

Poly operator * (Poly A, Poly B) {
	static int x[maxn*4], y[maxn*4];
	int len = getsz(A.len + B.len - 1);
	rep0(i, len) x[i] = y[i] = 0;
	A.cpyto(x, A.len), B.cpyto(y, B.len);
	NTT(x, len, 1), NTT(y, len, 1);
	rep0(i, len) x[i] = mul(x[i], y[i]);
	NTT(x, len, -1);
	return A.load(x, len), A.resize(), A;
}

int n, k;

struct Matrix {
	Poly A, B, C, D;
	Matrix operator * (Matrix rhs) {
		Poly _A = A*rhs.A+B*rhs.C, _B = A*rhs.B+B*rhs.D, _C = C*rhs.A+D*rhs.C, _D = C*rhs.B+D*rhs.D;
		return _A.resize(k), _B.resize(k), _C.resize(k), _D.resize(k), (Matrix){_A, _B, _C, _D};
	}
	void I() { A = Poly(-1), B = Poly(0), C = Poly(0), D = Poly(-1); }
};

Matrix qpow(Matrix A, int b) {
	Matrix Res; Res.I();
	for (; b; A = A*A, b >>= 1)
		if (b & 1) Res = Res * A;
	return Res;
}

int main() {
	n = read(), k = read()+1;
	prework(getsz(k)*4);
	/*
	int x[4] = {1, 1, 1, 1};
	Poly P; P.load(x, 4); P.write(); P = P*P;
	P.write();
	*/
	Matrix A; Poly P;
	P.resize(2); P[1] = 1; A.B = P; P[0] = 1; A.A = P; A.C = Poly(-1);
	/*
	A.A.write(), A.B.write(), A.C.write(), A.D.write();
	*/
	A = qpow(A, n-1);

	P = A.A*P + A.B*Poly(-1); P.resize(k);
	rep(i, 1, k-1) printf("%d ", P[i]);
	return 0;
}