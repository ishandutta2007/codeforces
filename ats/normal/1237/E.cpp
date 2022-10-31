#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define MOD 998244353
#define root 3

int add(const int x, const int y) { return (x + y < MOD) ? x + y : x + y - MOD; }
int mul(const int x, const int y) { return (long long)x * y % MOD; }
int power(int x, int n)
{
	int res = 1;
	while (n > 0) {
		if (n & 1) { res = mul(res, x); }
		x = mul(x, x);
		n >>= 1;
	}
	return res;
}
int inverse(const int x) { return power(x, MOD - 2); }

void ntt(vector<int>& a, const bool rev = false)
{
	int i, j, k, s, t, v, w, wn;
	const int size = (int)a.size();
	const int height = (int)log2(2 * size - 1);
	for (i = 0; i < size; i++) {
		j = 0;
		for (k = 0; k < height; k++) { j |= (i >> k & 1) << (height - 1 - k); }
		if (i < j) swap(a[i], a[j]);
	}
	for (i = 1; i < size; i *= 2) {
		w = power(root, (MOD - 1) / (i * 2));
		if (rev) w = inverse(w);
		for (j = 0; j < size; j += i * 2) {
			wn = 1;
			for (k = 0; k < i; k++) {
				s = a[j + k + 0], t = mul(a[j + k + i], wn);
				a[j + k + 0] = add(s, t);
				a[j + k + i] = add(s, MOD - t);
				wn = mul(wn, w);
			}
		}
	}
	if (rev) {
		v = inverse(size);
		for (i = 0; i < size; i++) { a[i] = mul(a[i], v); }
	}
}

vector<int> convolute(const vector<int>& a, const vector<int>& b)
{
	const int size = (int)a.size() + (int)b.size() - 1;
	int t = 1;
	while (t < size) { t <<= 1; }
	vector<int> A(t, 0), B(t, 0);
	for (int i = 0; i < (int)a.size(); i++) { A[i] = a[i]; }
	for (int i = 0; i < (int)b.size(); i++) { B[i] = b[i]; }
	ntt(A), ntt(B);
	for (int i = 0; i < t; i++) { A[i] = mul(A[i], B[i]); }
	ntt(A, true);
	A.resize(size);
	return A;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}else if (N == 1) {
		cout << 1 << endl;
		return 0;
	}else if (N == 2) {
		cout << 1 << endl;
		return 0;
	}
	else if (N == 3) {
		cout << 0 << endl;
		return 0;
	}

	vector<int> dp1(N + 1);
	vector<int> dp2(N + 1);
	vector<int> sumodd1(N + 1, 0);
	vector<int> sumeven1(N + 1, 0);
	vector<int> sumodd2(N + 1, 0);
	vector<int> sumeven2(N + 1, 0);
	dp1[1] = 1;
	dp2[1] = 0;
	dp1[2] = 1;
	dp2[2] = 1;
	vector<int> leftodd(3, 0);
	vector<int> righteven(3, 0);
	
	leftodd[0] = 0;
	righteven[0] = 1;
	leftodd[1] = 1;
	righteven[1] = 1;
	leftodd[2] = 0;
	righteven[2] = 0;
	int mn = 1;
	int mx = 3;
	while (true) {

		if (N <= 2 * mx + 1)break;
		mn = 2 * mn + 1;
		mx = 2 * mx + 1;
		vector<int> leftodd_even(righteven.size(), 0);
		vector<int> righteven_odd(leftodd.size(), 0);
		for (int i = 0; i < righteven.size(); i++) {
			if (!(i & 1)) {
				leftodd_even[i] = 0;
				righteven_odd[i] = righteven[i];
			}
			else {
				leftodd_even[i] = leftodd[i];
				righteven_odd[i] = 0;
			}
		}

		vector<int> nleftodd = convolute(righteven_odd, leftodd);
		vector<int> nrighteven = convolute(leftodd_even, righteven);
		swap(righteven, nrighteven);
		swap(leftodd, nleftodd);
	}
	int res = 0;
	//cerr << mn << "  " << mx << endl;
	for (int i = 0; i < leftodd.size(); i++) {
		//cerr << i << " " << N - 2 * mn - 1 - i << endl;
		//cerr << leftodd[i] << " " << endl;
		if (N - 2 * mn - 1 - i >= 0) {
			res = add(res, mul(leftodd[i], righteven[N - 2 * mn - 1 - i]));
		}
	}



	cout << res << endl;
}