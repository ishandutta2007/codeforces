#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MOD = 490019;
const int P = 491;
const int Q = 499;
const int GP = 2;
const int GQ = 7;

namespace FFT {
	#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
	#define REP(i, n) FOR(i, 0, n)

	typedef long long llint;
	
	const int MAX = 1 << 20;
	
	typedef llint value;
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

	void mult(value *a, value *b, value *c, int len) {
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

int N, M, C;
int a[MAXN], b[MAXN];
int pot[MOD];
int sq[MAXN], cube[MAXN];
vector <int> A[5], B[5];
int idP[P], idQ[Q];
int potP[P], potQ[Q];
ll coefA[MOD], coefB[MOD];
ll coef[2 * MOD];
int crt[P][Q][2];

void load() {
	scanf("%d%d%d", &N, &M, &C);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	for (int i = 0; i < M; i++)
		scanf("%d", b + i);
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	else if (x < 0)
		x += MOD;
	return x;
}

inline void inc(ll &x, int y) {
	x = add(x, y);
}

inline int mul(int x, int y) {
	return (ll)x * y % MOD;
}

inline bool coprime(int x) {
	return x % P && x % Q;
}

inline int get(int i, int j) {
	return mul(mul(a[i], b[j]), pot[(ll)sq[i] * cube[j] % (MOD - 1)]);
}

void init() {
	for (int i = 0; i < MAXN; i++) {
		sq[i] = (ll)i * i % (MOD - 1);
		cube[i] = (ll)i * i * i % (MOD - 1);
	}
	
	pot[0] = 1;
	for (int i = 1; i < MOD - 1; i++)
		pot[i] = mul(pot[i - 1], C);
	
	int curr = 1;
	for (int i = 0; i < P - 1; i++) {
		idP[curr] = i;
		potP[i] = curr;
		curr = curr * GP % P;
	}
	
	curr = 1;
	for (int i = 0; i < Q - 1; i++) {
		idQ[curr] = i;
		potQ[i] = curr;
		curr = curr * GQ % Q;
	}
	
	for (int i = 0; i < MOD - 1; i++)
		crt[i % P][i % Q][i % 2] = i;
}

vector <int> convolution(int k, int l) {
	memset(coefA, 0, sizeof coefA);
	memset(coefB, 0, sizeof coefB);
	memset(coef, 0, sizeof coef);
	
	for (auto it : A[k]) {
		int x = 2 * idP[it % P] % (P - 1);
		int y = 2 * idQ[it % Q] % (Q - 1);
		inc(coefA[2 * P * y + x], a[it]);
	}
	
	for (auto it : B[l]) {
		int x = 3 * idP[it % P] % (P - 1);
		int y = 3 * idQ[it % Q] % (Q - 1);
		inc(coefB[2 * P * y + x], b[it]);
	}
	
	FFT::mult(coefA, coefB, coef, MOD);
	
	vector <int> res;
	for (int i = 0; i < 2 * MOD; i++)
		res.push_back(coef[i] % MOD);
	
	return res;
}

int calc(vector <int> v, int parity) {
	int res = 0;
	for (int i = 0; i < v.size(); i++) {
		int x = i / (2 * P) % (Q - 1);
		int y = i % (2 * P) % (P - 1);
		res = add(res, mul(v[i], pot[crt[potP[y]][potQ[x]][parity]]));
	}
	return res;
}

int solve() {
	vector <int> d;
	for (int i = 0; i < M; i++) 
		if (coprime(i)) 
			B[i % 2].push_back(i);
		else 
			d.push_back(i);
		
	int sol = 0;
	for (int i = 0; i < N; i++)
		if (coprime(i)) {
			A[i % 2].push_back(i);
			for (auto j : d)
				sol = add(sol, get(i, j));
		}
		else
			for (int j = 0; j < M; j++)
				sol = add(sol, get(i, j));
	
	for (auto it : A[1])
		A[0].push_back(it);
		
	for (auto it : B[1])
		B[0].push_back(it);
	
	vector <int> all = convolution(0, 0);	
	vector <int> part = convolution(1, 1);
	for (int i = 0; i < all.size(); i++)
		all[i] -= part[i];
		
	return add(sol, add(calc(all, 0), calc(part, 1)));	
}

int main() {
	load();
	init();
	printf("%d\n", solve());
	return 0;
}