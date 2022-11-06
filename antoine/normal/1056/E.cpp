#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = (int) 1e6 + 9;

namespace RK { // Rabin Karp

const int mod[2] = { (int) 1e9 + 7, (int) 1e9 + 9 };
const int prime[2] = { 179, 233 };
ll pPow[MaxN + 9][2];
ll h[MaxN + 9][2];

void init(const string &s) {
	if (!pPow[0][0]) {
		pPow[0][0] = pPow[0][1] = 1;
		for (int i = 1; i <= MaxN; ++i)
			for (int z = 0; z < 2; ++z)
				pPow[i][z] = pPow[i - 1][z] * prime[z] % mod[z];
	}
	for (int i = 0; i < (int) s.size(); ++i)
		for (int z = 0; z < 2; ++z)
			h[i + 1][z] = (h[i][z] * prime[z] + s[i]) % mod[z];
}

array<ll, 2> query(const int l, const int r) {
	array<ll, 2> res;
	for (int z = 0; z < 2; ++z) {
		res[z] = (h[r + 1][z] - h[l][z] * pPow[r - l + 1][z]) % mod[z];
		if (res[z] < 0)
			res[z] += mod[z];
	}
	return res;
}

}

string s, t;
bool f(const int len0, const int len1) {
	const int len[2] = { len0, len1 };
	array<ll, 2> h[2] = { { -1, -1 }, { -1, -1 } };

	int j = 0;
	for (const char c : s) {
		const int l = len[c - '0'];
		const auto res = RK::query(j, j + l - 1);
		if (h[c - '0'][0] == -1)
			h[c - '0'] = res;
		else if (h[c - '0'] != res)
			return false;
		j += l;
	}

	assert(j == (int )t.size());
	assert(h[0][0] >= 0 && h[1][0] != 0);
	return len0 != len1 || h[0] != h[1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> s >> t;

	RK::init(t);

	const int cnt0 = count(s.begin(), s.end(), '0');
	const int cnt1 = count(s.begin(), s.end(), '1');

	const ll N = (ll) t.size();

	int ans = 0;
	for (ll len0 = 1; len0 <= N; ++len0) {
		const ll len1 = (N - (cnt0 * len0)) / cnt1;
		if (len1 <= 0 || cnt0 * len0 + cnt1 * len1 != N)
			continue;
		ans += f(len0, len1);
	}
	cout << ans;
	return 0;
}