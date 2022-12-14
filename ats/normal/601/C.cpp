#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <stdio.h>
using namespace std;

int MOD = 1000000007;
complex<double> operator* (const complex<double> a, const complex<double> b) {
	return complex<double>(a.real()*b.real() - a.imag()*b.imag(), a.real()*b.imag() + a.imag()*b.real());
}

vector<complex<double> > fft(vector<complex<double> > a, bool rev = false)
{
	constexpr double PI = std::acos(-1);
	int n = a.size(), h = 0;
	for (int i = 0; 1 << i < n; i++) h++;
	for (int i = 0; i < n; i++) {
		int j = 0;
		for (int k = 0; k < h; k++) {
			j |= (i >> k & 1) << (h - 1 - k);
		}
		if (i < j) swap(a[i], a[j]);
	}
	for (int i = 1; i < n; i *= 2) {
		for (int j = 0; j < i; j++) {
			complex<double> w = polar(1.0, 2 * PI / (i * 2)*(rev ? -1 : 1)*j);
			for (int k = 0; k < n; k += i * 2) {
				complex<double> s = a[j + k];
				complex<double> t = a[j + k + i] * w;
				a[j + k + 0] = s + t;
				a[j + k + i] = s - t;
			}
		}
	}
	if (rev) {
		for (int i = 0; i < n; i++) {
			a[i] /= n;
		}
	}
	return a;
}

void mul(vector<double> &a,const vector<double> &b)
{
	int s = (int)a.size() + (int)b.size() - 1, t = 1;
	while (t < s) t *= 2;
	vector<complex<double> > A(t), B(t);
	for (int i = 0; i < (int)a.size(); i++) {
		A[i].real(a[i]);
	}
	for (int i = 0; i < (int)b.size(); i++) {
		B[i].real(b[i]);
	}
	A = fft(A), B = fft(B);
	for (int i = 0; i < t; i++) {
		A[i] *= B[i];
	}
	A = fft(A, true);
	a.resize(s);
	for (int i = 0; i < s; i++) {
		a[i] = A[i].real();
	}
}

#define int long long
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	double res = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}

	vector<vector<double> >dp(N, vector<double>(M + 1, 1.0 / (M - 1)));

	for (int i = 0; i < N; i++) {
		dp[i][0] = 0;
		dp[i][A[i]] = 0;
	}
	int cur = 1;
	while (cur < N) {
		for (int i = 0; i + cur < N; i += cur) {
			mul(dp[i], dp[i + cur]);
		}
		cur *= 2;
	}
	for (int i = 0; i < sum; i++) {
		res += dp[0][i];
	}
	res *= M - 1;
	cout << fixed << setprecision(15) << res + 1 << endl;
}