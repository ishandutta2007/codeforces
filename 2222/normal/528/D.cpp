#include <algorithm>
#include <iostream>
#include <assert.h>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int N = 1 << 19;

char S[222222], T[222222];
int n, m, delta;

complex <double> W[N], A[N], B[N], C[N];

const double pi = acos(-1.);

void fft(complex <double> *y, complex<double> *a, int n = N, int k = 1) {
	if (n > 1) {
		fft(y, a, n >>= 1, k << 1);
		fft(y + n, a + k, n, k << 1);
		REP (i, n) {
			complex <double> t = W[i * k] * y[i + n];
			y[i + n] = y[i] - t;
			y[i] += t;
		}
	} else *y = *a;
}


vector<bool> solve(char c) {
	CL(C, 0);
	int need = 0;
	REP (i, n) {
		C[(N - i) & (N - 1)] = S[i] == c ? 1.0 : 0.0;
		need += (S[i] == c);
	}
	if (need == 0)
		return vector<bool>(N, true);
	fft(A, C, N);
	CL(C, 0);
	int last = -delta - 1;
	REP (i, m) {
		if (T[i] == c) {
			last = i;
		}
		if ((i - last) <= delta)
			C[i] = 1.0;
	}
	for (int i = m; (i - last) <= delta; ++i)
		C[i] = 1.0;
	last = m + delta;
	for (int i = m; i --> 0; ) {
		if (T[i] == c)
			last = i;
		if ((last - i) <= delta)
			C[i] = 1.0;
	}
	for (int i = -1; (last - i) <= delta; --i)
		C[i + N] = 1.0;
	fft(B, C, N);
	REP (i, N)
		A[i] *= B[i];
	REP (i, N)
		W[i] = conj(W[i]);
	fft(C, A, N);
	vector<bool> r(N);
	REP (i, N) {
		assert(fabs(C[i].imag() / N) < 1e-4);
		int k = int(C[i].real() / N + 0.5);
		assert(k <= need);
		r[i] = k == need;
	}
	return r;
}

int main() {
	REP (i, N)
		W[i] = polar(1.0, (2 * pi) * i / N);
    scanf("%d%d%d", &m, &n, &delta);
	assert(m >= n);
	scanf("%s%s", T, S);
	assert(strlen(S) == n);
	assert(strlen(T) == m);
	vector<bool> ok(N, true);
	for (char c : "ATGC") {
		if (c == 0)
			break;
		auto v = solve(c);
		REP (i, N)
			ok[i] = ok[i] && v[i];
	}
	cout << count(ok.begin(), ok.begin() + (m - n + 1), true) << endl;
    return 0;
}