#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;

vector<vector<int>> matrixMult(const vector<vector<int>> A, const vector<vector<int>> B) {
	vector<vector<int>> C(A.size(), vector<int>(B[0].size(), 0));
	for (int i = 0; i < C.size(); ++i)
		for (int j = 0; j < C[0].size(); ++j)
			for (int k = 0; k < A[0].size(); ++k)
				C[i][j] = (C[i][j] + (ll)A[i][k] * B[k][j]) % mod;
	return C;
}

vector<vector<int>> matrixIdentity(const int n) {
	vector<vector<int>> M(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
		M[i][i] = 1;
	return M;
}

vector<vector<int>> matrixPow(vector<vector<int>> A, ll k) {
	auto B = matrixIdentity(A.size());
	for (; k; k >>= 1) {
		if (k & 1)
			B = matrixMult(A, B);
		A = matrixMult(A, A);
	}
	return B;
}
// fn = fn-1 - fn-2

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<vector<int>> v = { { 0, 0} };
	cin >> v[0][0] >> v[0][1];

	int n;
	cin >> n;

	vector<vector<int>> M = {
		{0, -1},
		{1, 1}
	};

	v = matrixMult(v, matrixPow(M, n - 1));

	cout << (v[0][0] % mod + mod) % mod;

	return 0;
}