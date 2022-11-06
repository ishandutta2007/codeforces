#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 1e5 + 9;

namespace RK { // Rabin Karp

const int mod[2] = { (int) 1e9 + 7, (int) 1e9 + 9 };
const int prime[2] = { 179, 233 };
ll pPow[MxN + 9][2];
ll h[MxN + 9][2];
int n;

void init(const string &s) {
	if (!pPow[0][0]) {
		pPow[0][0] = pPow[0][1] = 1;
		for (int i = 1; i <= MxN; ++i)
			for (int z = 0; z < 2; ++z)
				pPow[i][z] = pPow[i - 1][z] * prime[z] % mod[z];
	}

	n = (int) s.size();
	h[0][0] = h[0][1] = 0;
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

array<ll, 2> query(const string &s) {
	array<ll, 2> h;
	h.fill(0);
	for (int i = 0; i < (int) s.size(); ++i)
		for (int z = 0; z < 2; ++z)
			h[z] = (h[z] * prime[z] + s[i]) % mod[z];
	return h;
}

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string s;
	cin >> s;
	const int n = (int) s.size();

	int Q;
	cin >> Q;
	vector<pair<int, string>> queries(Q);
	for (auto && query : queries)
		cin >> query.first >> query.second;

	map<int, vector<int>> mp;
	for (int i = 0; i < Q; ++i)
		mp[(int) queries[i].second.size()].push_back(i);

	RK::init(s);
	vector<vector<int>> occ(Q);
	for (const pair<int, vector<int>> &entry : mp) {
		map<array<ll, 2>, int> mp;
		for (const int i : entry.second)
			mp[RK::query(queries[i].second)] = i;
		const int len = entry.first;
		for (int i = 0; i + len <= n; ++i) {
			const array<ll, 2> p = RK::query(i, i + len - 1);
			auto it = mp.find(p);
			if (it == mp.end())
				continue;
			occ[it->second].push_back(i);
		}
	}

	for (int i = 0; i < Q; ++i) {
		const int k = queries[i].first;
		const int len = (int) queries[i].second.size();
		const vector<int> &v = occ[i];
		int res = -1;
		if ((int) v.size() >= k) {
			res = n;
			for (int i = 0; i + k <= (int) v.size(); ++i)
				res = min(res, v[i + k - 1] - v[i] + len);
		}
		cout << res << '\n';
	}
	return 0;
}