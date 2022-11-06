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

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

void addRange(set<pair<ll, ll>> &ranges, ll l, ll r) {
	auto it = ranges.lower_bound({ l, -1 });
	while (it != ranges.end() && it->second <= r)
		it = ranges.erase(it);
	if (it != ranges.end() && it->first <= r) {
		ranges.emplace(r + 1, it->second);
		it = ranges.erase(it);
	}
	if (it != ranges.begin()) {
		--it;
		if (it->second >= l) {
			ranges.emplace(it->first, l - 1);
			if (it->second > r)
				ranges.emplace(r + 1, it->second);
			ranges.erase(it);
		}
	}
	ranges.emplace(l, r);
}

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
	auto B = matrixIdentity(A.size());
	for (; k; k >>= 1) {
		if (k & 1)
			B = matrixMult(A, B);
		A = matrixMult(A, A);
	}
	return B;
}


ll n, m;
set<pair<ll, ll>> obstacles[3];

int get(ll a, ll i) {
	auto it = obstacles[a].upper_bound({ i, 2e18 });
	if (it == obstacles[a].begin()) return 0;
	--it;
	return it->second >= i;
}

int get(ll i) {
	return get(2, i) << 2 | get(1, i) << 1 | get(0, i);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	set<ll> events = { m - 1 };

	for (int i = 0; i < n; ++i) {
		ll a, l, r;
		cin >> a >> l >> r;
		addRange(obstacles[--a], --l, --r);
		events.insert(l - 1);
		events.insert(r);
	}

	const vector<vector<vector<ll>>> Matrixes = {
		{ { 1, 1, 0 },{ 1, 1, 1 },{ 0, 1, 1 } },
		{ { 0, 1, 0 },{ 0, 1, 1 },{ 0, 1, 1 } },
		{ { 1, 0, 0 },{ 1, 0, 1 },{ 0, 0, 1 } },
		{ { 0, 0, 0 },{ 0, 0, 1 },{ 0, 0, 1 } },
		{ { 1, 1, 0 },{ 1, 1, 0 },{ 0, 1, 0 } },
		{ { 0, 1, 0 },{ 0, 1, 0 },{ 0, 1, 0 } },
		{ { 1, 0, 0 },{ 1, 0, 0 },{ 0, 0, 0 } },
		{ { 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } }
	};


	ll pos = 0;
	vector<ll> dp = { 0, 1, 0 };

	while (events.size()) {
		const auto &M = Matrixes[get(pos + 1)];
		const ll k = *events.begin() - pos;
		events.erase(events.begin());
		dp = matrixMult(vector<vector<ll>>{dp}, matrixPow(M, k))[0];
		pos += k;
	}

	cout << dp[1];
	return 0;
}