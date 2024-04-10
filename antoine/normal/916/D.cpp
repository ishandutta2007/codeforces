#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <array>
#include <queue>
#include <memory>

using namespace std;

template<class T> struct PBTrie { // persistent binary trie
	char pos;
	T v;
	shared_ptr<PBTrie> next[2];

	PBTrie(long long maxVal) {
		for (pos = -1; maxVal; ++pos, maxVal >>= 1);
	}

	PBTrie(const char pos) : pos(pos) {}

	void updateHelper(const long long i, const T v) {
		if (pos == -1)
			this->v = T(v, this->v);
		else {
			bool bit = (i >> pos) & 1;
			if (next[bit])
				next[bit] = make_shared<PBTrie>(*next[bit]);
			else
				next[bit] = make_shared<PBTrie>((char)(pos - 1));
			next[bit]->updateHelper(i, v);
			this->v = !next[!bit] ? next[bit]->v : T(next[0]->v, next[1]->v);
		}
	}

	shared_ptr<PBTrie> update(const long long i, const T v) const {
		auto dup = make_shared<PBTrie>(*this);
		dup->updateHelper(i, v);
		return dup;
	}

	T query(const long long l, const long long r, const long long lo, const long long hi) const {
		if (l <= lo && hi <= r)
			return v;
		auto mid = (lo + hi) >> 1;
		T res;
		if (r > mid && next[1])
			res = T(res, next[1]->query(l, r, mid + 1, hi));
		if (l <= mid && next[0])
			res = T(res, next[0]->query(l, r, lo, mid));
		return res;
	}

	T query(const long long l, const long long r) const {
		auto hi = (1ll << (pos + 1)) - 1;
		return (l <= r && l < hi && r >= 0) ? query(l, r, 0, hi) : T();
	}
};

struct PBTrieVal {
	long long v = 0;
	PBTrieVal() {}
	PBTrieVal(const long long v) : v(v) {}
	PBTrieVal(const PBTrieVal &v1, const PBTrieVal &v2) {
		v = v1 + v2;
	}
	operator long long() const {
		return v;
	}
};

template <class T> struct IDGen {
	map<T, int> mp;

	bool hasID(const T x) {
		return mp.count(x);
	}

	int getID(T x) {
		auto it = mp.find(x);
		if (it != mp.end())
			return it->second;
		int sz = mp.size();
		mp[x] = sz;
		return sz;
	}
};

template<class K, class V> struct GeneticPTrie { // genetic persistent trie
	PBTrie<V> pbTrie;
	shared_ptr<IDGen<K>> idGenPtr;

	GeneticPTrie(const int MaxInserts) : pbTrie(MaxInserts - 1ll) {
		idGenPtr = make_shared<IDGen<K>>();
	}

	void updateHelper(const K k, const V v) {
		pbTrie.updateHelper(idGenPtr->getID(k), v);
	}

	shared_ptr<GeneticPTrie<K, V>> update(const K k, const V v) {
		auto dup = make_shared<>(*this);
		dup->updateHelper(k, v);
		return dup;
	}

	PBTrieVal query(const K k) const {
		auto id = idGenPtr->getID(k);
		return pbTrie.query(id, id);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> q;

	vector<pair<PBTrie<PBTrieVal>, GeneticPTrie<string, PBTrieVal>>> states = { { { (long long)1e9 },{ (int)1e5} } };
	states.reserve(q);

	for (int i = 1; i <= q; ++i) {
		string op;
		cin >> op;
		if (op == "undo") {
			int x;
			cin >> x;
			states.push_back(states[i - x - 1]);
			continue;
		}
		string a;
		cin >> a;
		states.push_back(states.back());
		auto y = states.back().second.query(a);
		if (op == "query") {
			cout << (y ? (long long)states.back().first.query(0, y - 1) : -1ll) << endl;
			continue;
		}
		if (y) {
			states.back().first.updateHelper(y, -1);
			states.back().second.updateHelper(a, -y);
		}
		if (op == "set") {
			int x;
			cin >> x;
			states.back().first.updateHelper(x, 1);
			states.back().second.updateHelper(a, x);
		}
	}
	return 0;
}