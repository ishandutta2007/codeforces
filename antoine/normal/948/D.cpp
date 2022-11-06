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
#include <stack>
#include <memory>

using namespace std;

typedef long long ll;

struct Trie { // persistent binary trie
	char pos;
	typedef long long ll;
	ll v= 0;
	shared_ptr<Trie> next[2];

	Trie(const char pos) : pos(pos) {}

	void edit(const ll i, ll v) {
		this->v += v;
		if (pos != -1) {
			ll bit = (i >> pos) & 1;
			if (!next[bit])
				next[bit] = make_shared<Trie>((char)(pos - 1));
			next[bit]->edit(i, v);
		}
	}

	void insert(const ll i) {
		return edit(i, 1);
	}
	void del(const ll i) {
		return edit(i, -1);
	}

	void min(const ll x, ll &res) {
		if (pos == -1)
			return;
		ll bit = (x >> pos) & 1;
		if (!next[bit] || !next[bit]->v)
			bit ^= 1;

		res = res << 1 | bit;
		next[bit]->min(x, res);
	}

	ll min(const ll x) {
		ll res = 0;
		min(x, res);
		return res;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(0);

	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	Trie trie(32);
	for (int i = 0; i < n; ++i) {
		ll p;
		cin >> p;
		trie.insert(p);
	}
	for (int i = 0; i < n; ++i) {
		ll m = trie.min(a[i]);
		//cout << "min is [" << m << "]\n";
		trie.del(m);
		if (i)
			cout << ' ';
		cout << (a[i] ^ m);
	}
	return 0;
}