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

struct Trie {
	int cnt = 0;
	Trie * adj[2] = { 0, 0 };
	void insert(const string &s, const int i) {
		++cnt;
		if (i != s.size()) {
			bool bit = s[i] - '0';
			if (!adj[bit])
				adj[bit] = new Trie();
			adj[bit]->insert(s, i + 1);
		}
	}

	int leftCnt() {
		return adj[0] ? adj[0]->cnt : 0;
	}

	int rightCnt() {
		return adj[1] ? adj[1]->cnt : 0;
	}
};

string revBinRep(int x) {
	string res = "";
	for (int i = 0; i < 31; ++i) {
		res.push_back((x & 1) + '0');
		x >>= 1;
	}

	return res;
}

int f(Trie * trie1, Trie * trie2) {
	if (!trie1 && !trie2) return 0;
	if (!trie1) return f(trie2->adj[0], trie2->adj[1]);
	if (!trie2) return f(trie1->adj[0], trie1->adj[1]);
	
	int ans = max(trie1->leftCnt() + trie2->rightCnt(), trie1->rightCnt() + trie2->leftCnt());
	ans = max(ans, f(trie1->adj[0], trie2->adj[0]));
	ans = max(ans, f(trie1->adj[1], trie2->adj[1]));
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, h;
	cin >> n >> h;
	vector<ll> x1(n), x2(n);
	for (int i = 0; i < n; ++i)
		cin >> x1[i] >> x2[i];

	vector<ll> cs(n, 0);
	for (int i = 1; i < n; ++i)
		cs[i] = cs[i - 1] + x1[i] - x2[i - 1];


	ll ans = 0;


	for (int i = 0; i < n; ++i) {

		auto it = lower_bound(cs.begin(), cs.end(), cs[i] + h);
		it--;
		const int j = it - cs.begin();
		ll curr = x2[j] - x1[i] + h - (cs[j] - cs[i]);
		ans = max(ans, curr);
	}
	cout << ans;
	return 0;
}