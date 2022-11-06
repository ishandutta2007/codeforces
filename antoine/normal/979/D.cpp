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
#include <assert.h>
#include <numeric>

using namespace std;
typedef long long ll;

struct Trie { // persistent binary trie
	char pos;
	int v = 1e6;
	Trie * next[2] = { 0, 0 };

	Trie() {
		int maxVal = 1e5;
		for (pos = -1; maxVal; ++pos, maxVal >>= 1);
	}

	Trie(char pos) : pos(pos) {};

	void insert(const int i) {
		v = min(v, i);
		if (pos != -1) {
			bool bit = (i >> pos) & 1;
			if (!next[bit])
				next[bit] = new Trie((char)(pos - 1));
			next[bit]->insert(i);
		}
	}

	int query(const int _xor, const int r, const int lo, const int hi) const {
		if (pos == -1) {
			assert(lo == hi);
			assert(lo <= r);
			return lo;
		}
		auto mid = (lo + hi) >> 1;
		bool bit = (_xor >> pos) & 1;
		if (!bit) {
			if (next[1] && next[1]->v <= r)
				return next[1]->query(_xor, r, mid + 1, hi);
			if (next[0] && next[0]->v <= r)
				return next[0]->query(_xor, r, lo, mid);
		}
		else {
			if (next[0] && next[0]->v <= r)
				return next[0]->query(_xor, r, lo, mid);
			if (next[1] && next[1]->v <= r)
				return next[1]->query(_xor, r, mid + 1, hi);
		}
		assert(false);
		return -999;
	}

	int query(const int _xor, const int r) const {
		auto hi = (1ll << (pos + 1)) - 1;
		return (0 <= r && 0 < hi && r >= 0 && v <= r) ? query(_xor, r, 0, hi) : -1;
	}
};

void divisors(int i, int acc, const vector<pair<int, int>> &v, vector<int> &res) {
	if (i == v.size())
		res.push_back(acc);
	else {
		for (int j = 0; j <= v[i].second; ++j) {
			divisors(i + 1, acc, v, res);
			acc *= v[i].first;
		}
	}
}

vector<int> divisors(int n) {
	vector<pair<int, int>> primeDivs;
	for (int i = 2; i*i <= n; ++i)
		if (n%i == 0) {
			primeDivs.emplace_back(i, 1);
			for (n /= i; n%i == 0; n /= i)
				primeDivs.back().second++;
		}
	if (!primeDivs.empty() && primeDivs.back().first == n)
		primeDivs.back().second++;
	else
		primeDivs.emplace_back(n, 1);

	vector<int> res;
	divisors(0, 1, primeDivs, res);
	return res;
}

int query(int x, int k, int s) {
	if (x%k) return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> q;
	static Trie tries[(int)1e5 + 1];
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int u;
			cin >> u;
			for (auto &&d : divisors(u))
				tries[d].insert(u);
		}
		else {
			int x, k, s;
			cin >> x >> k >> s;
			cout << (x%k ? -1 : tries[k].query(x, s - x)) << '\n';
		}
	}
	return 0;
}