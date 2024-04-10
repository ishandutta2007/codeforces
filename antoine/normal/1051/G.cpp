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


/*
void assert(bool x) {
	if (!x) {
		cout << "assert failed\n";
		exit(0);
	}
}*/

template<int n> struct DSU {
	array<int, n> rank, parent;

	DSU() {
		fill(rank.begin(), rank.end(), 1);
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	int find(const int u) {
		return parent[u] == u ? u : (parent[u] = find(parent[u]));
	}

	bool merge(int u, int v) {
		if ((u = find(u)) == (v = find(v)))
			return false;
		if (rank[u] < rank[v])
			swap(u, v);
		rank[u] += rank[v];
		parent[v] = u;
		return true;
	}

	int size(int u) {
		return rank[find(u)];
	}
};


ll ans = 0;

struct Trie {
	struct Node {
		int cnt = 0;
		ll sum = 0;
		Node * adj[2] = { 0, 0 };

		~Node() {
			for (auto &&x : adj)
				if (x) delete x;
		}

		pair<int, ll> insert(const int idx, const int lo, const int hi) {
			assert(lo <= idx && idx <= hi);

			cnt++;
			sum += idx;

			if (lo == hi) {
				assert(cnt == 1 && sum == idx);
				return{ 0, 0 };
			} else {
				const int mid = (lo + hi) >> 1;
				const bool bit = idx > mid;
				if (!adj[bit])
					adj[bit] = new Node();

				if (!bit)
					return adj[0]->insert(idx, lo, mid);

				pair<int, ll> res = adj[1]->insert(idx, mid + 1, hi);
				if (adj[0]) {
					res.first += adj[0]->cnt;
					res.second += adj[0]->sum;
				}
				return res;
			}
		}

		void retrieve(vector<int> &res, const int lo, const int hi) {
			if (lo == hi) {
				assert(cnt == 1 && sum == lo);
				res.push_back(lo);
			} else {
				const int mid = (lo + hi) >> 1;
				if (adj[1]) adj[1]->retrieve(res, mid + 1, hi);
				if (adj[0]) adj[0]->retrieve(res, lo, mid);
			}
		}
	};

	int n;
	Trie(const int _n) : n(_n) {
		root = new Node();
	}

	Node * root;

	pair<int, ll> insert(const int idx) {
		assert(1 <= idx && idx <= n);
		return root->insert(idx, 1, n);
	}

	vector<int> retrieve() {
		vector<int> res;
		root->retrieve(res, 1, n);
		return res;
	}

	Trie() { delete root; }

};

struct Comp {
	int l, r;
	Trie trie;

	Comp(int a, int b) : trie((int)4e5 + 5) {
		l = r = a;
		trie.insert(b);
	}

	Comp &merge(Comp &other) {
		assert(l == other.r + 1 || other.l == r + 1);
		
		if (cnt() < other.cnt()) {
			ans += sum() * other.cnt();
			ans -= other.sum() * cnt();
			return other.merge(*this);
		}
		l = min(l, other.l);
		r = max(r, other.r);

		for (auto &&x : other.trie.retrieve()) {
			pair<int, ll> res = trie.insert(x);
			ans += res.second - res.first * (ll)x;
		}
		return *this;
	}

	ll sum() const { return trie.root->sum; }
	int cnt() const {
		const int res = r - l + 1;
		assert(res == trie.root->cnt);
		return res;
	}
};

DSU<(int)4e5 + 4> dsu;
Comp * comps[(int)4e5 + 4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		if (comps[dsu.find(a)]) {
			ans += ((comps[dsu.find(a)]->r + 1 - a) * (ll)b);
			a = comps[dsu.find(a)]->r + 1;
		}


		assert(a == dsu.find(a));
		assert(!comps[a]);

		Comp * curr = comps[a] = new Comp(a, b);

		if(comps[dsu.find(a - 1)]) {
			curr = &comps[dsu.find(a - 1)]->merge(*curr);
			dsu.merge(a, a - 1);
			comps[dsu.find(a)] = curr;
		}
		if (comps[dsu.find(a + 1)]) {
			curr = &curr->merge(*comps[dsu.find(a + 1)]);
			dsu.merge(a, a + 1);
			comps[dsu.find(a)] = curr;
		}

		cout << ans << '\n';
	}
	return 0;
}