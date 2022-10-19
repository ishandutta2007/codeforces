/*input
10
50 9 11 44 39 40 5 39 23 7
*/

#include <iostream>
#include <array>

using namespace std;

const int N = 17, MOD = 1000 * 1000 * 1000 + 7;
using arr_t = array<int, 1 << N>;

int add(int x, int y) { return (x -= ((x += y) >= MOD ? MOD : 0)); }
int sub(int x, int y) { return (x += ((x -= y) < 0 ? MOD : 0)); }
int mul(int x, int y) { return (int) ((int64_t) x * y % MOD); }
int bpow(int a, int p)
{
	int ans = 1;
	for (; p > 0; p >>= 1) {
		if (p & 1) ans = mul(ans, a);
		a = mul(a, a);
	}
	return ans;
}

void fwht(arr_t &A, bool inv)
{
	for (int k = 1; k < (1 << N); k <<= 1) {
		for (int i = 0; i < (1 << N); i += (k << 1)) {
			for (int j = i; j < i + k; ++j) {
				int x = A[j], y = A[j + k];
				A[j] = add(x, y);
				A[j + k] = sub(x, y);
			}
		}
	}

	if (inv) {
		int x = bpow(1 << N, MOD - 2);
		for (int i = 0; i < (1 << N); ++i) {
			A[i] = mul(A[i], x);
		}
	}
}

arr_t xor_convolution(arr_t A, arr_t B)
{
	fwht(A, false);
	fwht(B, false);
	for (int i = 0; i < (1 << N); ++i) {
		A[i] = mul(A[i], B[i]);
	}
	fwht(A, true);
	return A;
}

void sum_of_superset(arr_t &A, bool inv)
{
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < (1 << N); ++i) {
			if (!((i >> j) & 1)) {
				if (inv) {
					A[i] = sub(A[i], A[i ^ (1 << j)]);
				} else {
					A[i] = add(A[i], A[i ^ (1 << j)]);
				}
			}
		}
	}
}

arr_t and_convolution(arr_t A, arr_t B)
{
	sum_of_superset(A, false);
	sum_of_superset(B, false);
	for (int i = 0; i < (1 << N); ++i) {
		A[i] = mul(A[i], B[i]);
	}
	sum_of_superset(A, true);
	return A;
}

void sum_of_subset(arr_t &A, bool inv)
{
	for (int j = 0; j < N; ++j) {
		for (int i = (1 << N) - 1; i >= 0; --i) {
			if ((i >> j) & 1) {
				if (inv) {
					A[i] = sub(A[i], A[i ^ (1 << j)]);
				} else {
					A[i] = add(A[i], A[i ^ (1 << j)]);
				}
			}
		}
	}
}

arr_t subset_convolution(arr_t A, arr_t B)
{
	array<arr_t, N + 1> X = {}, Y = {};
	for (int i = 0; i < (1 << N); ++i) {
		X[__builtin_popcount(i)][i] = A[i];
		Y[__builtin_popcount(i)][i] = B[i];
	}

	for (int j = 0; j <= N; ++j) {
		sum_of_subset(X[j], false);
		sum_of_subset(Y[j], false);
	}

	for (int j = N; j >= 0; --j) {
		for (int i = 0; i < (1 << N); ++i) {
			X[j][i] = mul(X[j][i], Y[0][i]);
			for (int k = 0; k < j; ++k) {
				X[j][i] = add(X[j][i], mul(X[k][i], Y[j - k][i]));
			}
		}
		sum_of_subset(X[j], true);
	}

	for (int i = 0; i < (1 << N); ++i) {
		A[i] = X[__builtin_popcount(i)][i];
	}
	return A;
}

arr_t S, fib, A, B;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int sz;
	cin >> sz;
	while (sz--) {
		int x;
		cin >> x;
		++S[x];
	}

	fib[0] = 0, fib[1] = 1;
	for (int i = 2; i < (1 << N); ++i) {
		fib[i] = add(fib[i - 2], fib[i - 1]);
	}

	A = subset_convolution(S, S);
	B = xor_convolution(S, S);
	
	for (int i = 0; i < (1 << N); ++i) {
		S[i] = mul(S[i], fib[i]);
		A[i] = mul(A[i], fib[i]);
		B[i] = mul(B[i], fib[i]);
	}

	A = and_convolution(A, B);
	S = and_convolution(S, A);

	int ans = 0;
	for (int j = 0; j < N; ++j) {
		ans = add(ans, S[1 << j]);
	}
	cout << ans << endl;
}