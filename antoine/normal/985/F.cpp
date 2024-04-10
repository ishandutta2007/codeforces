#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 2e5 + 9;

namespace RK { // Rabin Karp

const int mod[2] = { (int) 1e9 + 7, (int) 1e9 + 9 };
const int prime[2] = { 179, 233 };
ll pPow[MxN + 9][2];

struct Obj {
	ll h[MxN + 9][2];

	void init(const string &s) {
		if (!pPow[0][0]) {
			pPow[0][0] = pPow[0][1] = 1;
			for (int i = 1; i <= MxN; ++i)
				for (int z = 0; z < 2; ++z)
					pPow[i][z] = pPow[i - 1][z] * prime[z] % mod[z];
		}
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
};

}

char str[MxN + 9] = { '.' };
array<int, 26> nxt[MxN + 9];
RK::Obj hashers[26];

vector<pair<int, char>> getNxt(const int i, const int len) {
	vector<pair<int, char>> res;
	for (int k = 0; k < 26; ++k)
		if (nxt[i][k] - i < len)
			res.push_back( { nxt[i][k] - i, 'a' + k });
	sort(res.begin(), res.end());
	return res;
}

bool query(const int i, const int j, const int len) {
	vector<pair<int, char>> vi = getNxt(i, len);
	vector<pair<int, char>> vj = getNxt(j, len);
	if (vi.size() != vj.size())
		return false;
	for (int k = 0; k < (int) vi.size(); ++k) {
		if (vi[k].first != vj[k].first)
			return false;
		const char ci = vi[k].second;
		const char cj = vj[k].second;
		if (hashers[ci - 'a'].query(i, i + len - 1) != hashers[cj - 'a'].query(j, j + len - 1))
			return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, Q;
	cin >> n >> Q;

	cin >> (str + 1);
	nxt[n + 1].fill(n + 1);
	for (int i = n; i >= 1; --i) {
		nxt[i] = nxt[i + 1];
		nxt[i][str[i] - 'a'] = i;
	}

	for (int k = 0; k < 26; ++k) {
		string t(str, str + n + 1);
		for (char &c : t)
			c = c == 'a' + k ? '0' : '1';
		hashers[k].init(t);
	}

	while (Q--) {
		int i, j, len;
		cin >> i >> j >> len;

		cout << (query(i, j, len) ? "YES" : "NO") << '\n';
	}

	return 0;
}