#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>

using namespace std;
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
ll fastMin(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ x; }
ll fastMax(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

//  : MODvZtB

typedef vector<double> Row;
typedef vector<Row> Mat;
Mat mul(const Mat& a, const Mat& b) {
	int n = a.size();
	int m = a[0].size();
	int x = b.size();
	int y = b[0].size();
	assert(m == x);

	Mat c(n, Row(y));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < y; ++j)
			for (int k = 0; k < m; ++k)
				(c[i][j] += a[i][k] * b[k][j]);
	return c;
}

Mat pow(const Mat& _a, int e) {
	Mat a = _a;
	int n = a.size();
	Mat res(n, Row(n));
	for (int i = 0; i < n; ++i)
		res[i][i] = 1;

	while (e > 0) {
		if (e & 1)
			res = mul(res, a);
		a = mul(a, a);
		e /= 2;
	}

	return res;
}

Mat inv(Mat A) {
	assert(sz(A) == sz(A[0]));
	const int n = sz(A);
	Mat B(n, Row(n));
	FOR(i, n) B[i][i] = 1;

	FOR(k, n) {
		int pv = k;
		for (int i = k + 1; i < n; ++i) {
			if (abs(A[i][k]) > abs(A[pv][k])) pv = i;
		}

		A[k].swap(A[pv]);
		B[k].swap(B[pv]);

		double e = A[k][k];
		FOR(j, n) A[k][j] /= e, B[k][j] /= e;

		for (int i = k + 1; i < n; ++i) {
			double x = A[i][k];
			FOR(j, n) A[i][j] -= A[k][j] * x, B[i][j] -= B[k][j] * x;
		}
	}

	for (int k = n - 1; k >= 0; --k) {
		for (int i = 0; i < k; ++i) {
			double e = A[i][k];
			for (int j = 0; j < n; ++j) A[i][j] -= A[k][j] * e, B[i][j] -= B[k][j] * e;
		}
	}
	return B;
}

Mat LU(Mat mat) {
	const int n = sz(mat);
	Mat lu = mat;

	for (int i = 0; i < n; i++) {
		int z = i;
		while (z < n && lu[z][i] == 0) z++;
		if (z == n) continue;
		lu[i].swap(lu[z]);

		for (int j = i + 1; j < n; j++) {
			lu[j][i] /= lu[i][i];
			for (int k = i + 1; k < n; k++) {
				lu[j][k] -= lu[j][i] * lu[i][k];
			}
		}
	}

	return lu;
}

Mat invL(Mat L) {
	const int n = sz(L);
	Mat il(n, Row(n));
	// row:j, col:i
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			double sum = i == j ? 1 : 0;
			for (int k = i; k < j; k++) {
				sum -= L[j][k] * il[k][i];
			}
			il[j][i] = sum / L[j][j];
		}
	}
	return il;
}

Mat invU(Mat U) {
	const int n = sz(U);
	Mat iu(n, Row(n));
	// row:j, col:i
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			double sum = i == j ? 1 : 0;
			for (int k = i; k < j; k++) {
				sum -= U[k][j] * iu[i][k];
			}
			iu[i][j] = sum / U[j][j];
		}
	}
	return iu;
}

Mat inv_with_LU(Mat A) {
	const int n = sz(A);
	Mat lu = LU(A);
	Mat iu = invU(lu);
	for (int i = 0; i < n; i++)lu[i][i] = 1.0;
	Mat il = invL(lu);
	return mul(iu, il);
}

void print(vector<vector<double>>& x) {
	FOR(i, sz(x)) {
		FOR(j, sz(x[i])) printf("%lf ", x[i][j]);
		puts("");
	}
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	FOR(i, n) cin >> a[i];
	vector<int> trips;
	FOR(i, n) if (a[i]) trips.push_back(i);
	const int Bsize = sz(trips);

	vector<vector<int>> e(n, vector<int>(n));
	FOR(i, m) {
		int a, b; cin >> a >> b;
		a--; b--;
		e[a][b]++;
		e[b][a]++;
	}

	vector<vector<double>> A(n, vector<double>(n));

	FOR(i, n) {
		if (a[i] == 1) {
			continue;
		}
		double s = accumulate(e[i].begin(), e[i].end(), 0);
		FOR(j, n) {
			A[i][j] = e[i][j] / s;
		}
	}

	Mat Adash(n, Row(n));
	FOR(i, n) FOR(j, n) Adash[i][j] = -A[i][j];
	FOR(i, n) Adash[i][i] += 1;

	Mat Adash_inv = inv_with_LU(Adash);

	Mat B;
	FOR(i, n){
		if (!a[i]) continue;
		Mat c(1);
		double s = accumulate(e[i].begin(), e[i].end(), 0);
		FOR(j, n) {
			c[0].push_back(e[i][j] / s);
		}

		int tmp = 0;
		auto c2 = mul(c, Adash_inv);
		
		Row r;
		FOR(j, n) {
			if (!a[j]) continue;
			r.push_back(c2[0][j]);
		}
		B.push_back(r);
	}

	Mat start(1);
	FOR(i, n) {
		if (!a[i]) continue;
		start[0].push_back(Adash_inv[0][i]);
	}

	Mat C = pow(B, k - 2);
	Mat D = mul(start, C);
	double ans = D[0].back();
	printf("%.10lf\n", ans);
}