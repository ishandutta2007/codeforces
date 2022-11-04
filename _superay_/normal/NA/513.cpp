#include <bits/stdc++.h>
using namespace std;
void NO() {
	puts("-1");
	exit(0);
}
long long mod;
struct Matrix {
	long long mat[2][2];
	Matrix(long long x = 0) {
		mat[0][0] = mat[1][1] = x;
		mat[0][1] = mat[1][0] = 0;
	}
	Matrix operator * (const Matrix &oth) const {
		Matrix res;
		for (int i = 0; i < 2; i++) for (int k = 0; k < 2; k++) for (int j = 0; j < 2; j++)
			res.mat[i][j] = (res.mat[i][j] + (__int128)mat[i][k] * oth.mat[k][j]) % mod;
		return res;
	}
};
Matrix matpow(Matrix a, long long b) {
	Matrix res(1);
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
long long calc(long long n) {
	Matrix A;
	A.mat[0][0] = 0;
	A.mat[0][1] = A.mat[1][0] = A.mat[1][1] = 1;
	A = matpow(A, n);
	return A.mat[0][1];
}
int main() {
	long long tar;
	scanf("%lld", &tar);
	mod = 100000ll;
	vector<long long> vec;
	for (int i = 0, a = 0, b = 1; i < mod / 2 * 3; i++) {
		if (a == tar % mod) vec.push_back(i);
		tie(a, b) = make_pair(b, (a + b) % mod);
	}
	if (!vec.size()) NO();
	for (int ee = 6; ee <= 13; ee++) {
		mod *= 10;
		vector<long long> nvec;
		for (long long &x : vec) {
			for (long long idx = x; idx < mod / 2 * 3; idx += mod / 10 / 2 * 3) {
				if (calc(idx) == tar % mod) nvec.push_back(idx);
			}
		}
		vec = nvec;
		if (!vec.size()) NO();
		sort(vec.begin(), vec.end());
		vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	}
	printf("%lld\n", vec[0]);
	return 0;
}