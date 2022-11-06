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

const int mod = 1e9 + 7;

vector<vector<ll>> matrixMult(const vector<vector<ll>> A, const vector<vector<ll>> B) {
	vector<vector<ll>> C(A.size(), vector<ll>(B[0].size(), 0));
	for (int i = 0; i < C.size(); ++i)
		for (int j = 0; j < C[0].size(); ++j)
			for (int k = 0; k < A[0].size(); ++k)
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
	return C;
}

vector<vector<ll>> matrixIdentity(const int n) {
	vector<vector<ll>> M(n, vector<ll>(n, 0));
	for (int i = 0; i < n; ++i)
		M[i][i] = 1;
	return M;
}

vector<vector<ll>> matrixPow(vector<vector<ll>> A, ll k) {
	vector<vector<ll>> B = matrixIdentity(A.size());
	for (; k; k >>= 1) {
		if (k & 1)
			B = matrixMult(A, B);
		A = matrixMult(A, A);
	}
	return B;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll x, k;
	cin >> x >> k;
	if (x == 0) {
		cout << 0;
		return 0;
	}

	vector<vector<ll>> M = {
		{2, 0},
		{mod-1, 1}
	};
	vector<vector<ll>> v = {
		{(2 * x) % mod, 1}
	};
	cout << matrixMult(v, matrixPow(M, k))[0][0];
	return 0;
}