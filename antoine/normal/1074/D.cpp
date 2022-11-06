#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// http://codeforces.com/contest/1074/problem/D

const int MaxN = (int) 4e5 + 9;

int parent[MaxN];
vector<int> comp[MaxN];
int color[MaxN];

struct ADSU {

	ADSU() {
		for (int i = 0; i < MaxN; ++i) {
			parent[i] = i;
			comp[i] = {i};
		}
		memset(color, 0, sizeof color);
	}

	int query(const int u, const int v) const {
		return parent[u] != parent[v] ? -1 : color[u] ^ color[v];
	}

	void connect(const int u, const int v, const vector<int> &compU,
			vector<int> &compV, const int w) {
		for (auto &&x : compU) {
			parent[x] = v;
			color[x] ^= w;
		}
		compV.insert(compV.end(), compU.begin(), compU.end());
		comp[u].clear();
	}

	void connect(int u, int v, int w) {
		w ^= color[u] ^ color[v];
		u = parent[u];
		v = parent[v];
		if (u == v)
		return;

		vector<int> &compU = comp[u];
		vector<int> &compV = comp[v];

		if (compU.size() < compV.size())
		connect(u, v, compU, compV, w);
		else
		connect(v, u, compV, compU, w);
	}
}adsu;

struct IdGen {
	map<int, int> mp;
	int operator[](const int x) {
		const int sz = mp.size();
		auto it = mp.insert( { x, sz });
		return it.first->second;
	}
} idGen;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int Q;
	cin >> Q;

	for (int last = 0; Q--;) {
		int type, l, r;
		cin >> type >> l >> r;

		l ^= last, r ^= last;
		if (l > r)
			swap(l, r);

		const int u = idGen[l - 1];
		const int v = idGen[r];

		if (type == 1) {
			int x;
			cin >> x;
			x ^= last;
			adsu.connect(u, v, x);
		} else {
			assert(type == 2);
			last = adsu.query(u, v);
			cout << last << '\n';
			if (last == -1)
				last = 1;
		}
	}
	return 0;
}