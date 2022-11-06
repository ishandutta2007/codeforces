#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MxN = (int) 1e6 + 9;

const int mod[2] = { (int) 1e9 + 7, (int) 1e9 + 9 };
const int prime[2] = { 179, 233 };
ll pPow[MxN + 9][2];

struct DS {
	vector<array<ll, 2>> h = { { 0, 0 } };
	string str;

	void append(const string s) {
		str += s;
		for (const char c : s) {
			array<ll, 2> a;
			for (int z = 0; z < 2; ++z)
				a[z] = (h.back()[z] * prime[z] + c) % mod[z];
			h.push_back(a);
		}
	}

	array<ll, 2> query(const int l, const int r) {
		// assert(0 <= l && l <= r + 1 && r + 1 < (int )h.size());
		array<ll, 2> res;
		for (int z = 0; z < 2; ++z) {
			res[z] = (h[r + 1][z] - h[l][z] * pPow[r - l + 1][z]) % mod[z];
			if (res[z] < 0)
				res[z] += mod[z];
		}
		return res;
	}

	int len() const {
		return (int) h.size() - 1;
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	pPow[0][0] = pPow[0][1] = 1;
	for (int i = 1; i <= MxN; ++i)
		for (int z = 0; z < 2; ++z)
			pPow[i][z] = pPow[i - 1][z] * prime[z] % mod[z];

	int q;
	cin >> q;
	DS ds;
	while (q--) {
		string s;
		cin >> s;
		DS ds2;
		ds2.append(s);
		int mx = 0;
		for (int i = 1; i <= min(ds.len(), ds2.len()); ++i)
			if (ds.query(ds.len() - i, ds.len() - 1) == ds2.query(0, i - 1))
				mx = i;
		ds.append(s.substr(mx));
	}
	cout << ds.str;
	return 0;
}