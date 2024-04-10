#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
const int K = 23;
#warning "change k"
const int T = 1 << K;

// pairwise or
// res[k] = 1 iff there exist i, j such that X[i] = 1 and Y[i] = 1 and i | j = k
bitset<T> convolution(bitset<T> X, bitset<T> Y) {
	int i, j;

	static int x[T];
	static int y[T];

	REP(i,T)
		x[i] = X[i];
	REP(i,K)
		REP(j,T)
			if (!(j & (1 << i)))
				x[j ^ (1 << i)] += x[j];

	REP(i,T)
		y[i] = Y[i];
	REP(i,K)
		REP(j,T)
			if (!(j & (1 << i)))
				y[j ^ (1 << i)] += y[j];

	REP(i,T)
		x[i] *= y[i];

	REP(i,K)
		REP(j,T)
			if (j & (1 << i))
				x[j] -= x[j ^ (1 << i)];

	bitset<T> ans;
	REP(i,T)
		ans[i] = (x[i] != 0);

	return ans;
}

struct DSU {
	vector<int> rank;
	vector<int> parent;

	DSU(int n) {
		rank.resize(n, 1);
		parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	vector<string> a(n);
	for (string &s : a)
		cin >> s;

	DSU dsu(n);

	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (a[i][j] == 'A')
				dsu.merge(i, j);

	vector<int> nodes;
	for (int i = 0; i < n; ++i)
		if (dsu.find(i) == i && dsu.size(i) >= 2)
			nodes.push_back(i);
	const int k = (int) nodes.size();
	assert(k <= K);
	vector<int> adj(k, (1 << k) - 1);

	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (a[i][j] == 'X') {
				int u = dsu.find(i);
				int v = dsu.find(j);
				if (u == v) {
					cout << -1;
					return 0;
				}
				if (dsu.size(u) == 1 || dsu.size(v) == 1)
					continue;

				u = find(nodes.begin(), nodes.end(), u) - nodes.begin();
				v = find(nodes.begin(), nodes.end(), v) - nodes.begin();
				assert(u < k && v < k);
				adj[u] &= ~(1 << v);
				adj[v] &= ~(1 << u);
			}

	bitset<T> clique = 1;

	for (int mask = 1; mask < (1 << k); ++mask) {
		int i = 0;
		while (!(mask & (1 << i)))
			++i;
		assert(i < k);
		clique[mask] = clique[mask ^ (1 << i)] && (adj[i] & mask) == mask;
	}
	/*

	 int lo = 0, hi = k;
	 while (lo < hi) {
	 const int mid = (lo + hi) / 2;
	 bitset<T> bs = 1;
	 for (int rep = 0; rep < mid; ++rep)
	 bs = convolution(bs, clique);

	 if (bs[(1 << k) - 1])
	 hi = mid;
	 else
	 lo = mid + 1;
	 }
	 */

	const int L = 4;
	bitset<T> dp[L + 1];
	dp[0] = clique;
	for (int i = 1; i <= L; ++i)
		dp[i] = convolution(dp[i - 1], dp[i - 1]);

	int lo = 0;
	bitset<T> bs = 1;
	for (int i = L; i >= 0; --i) {
		if (lo + (1 << i) >= k)
			continue;
		bitset<T> bs2 = move(convolution(bs, dp[i]));
		if (bs2[(1 << k) - 1])
			continue;

		bs = move(bs2);
		lo += 1 << i;
	}
	if (k)
		++lo;
	cout << n + lo - 1;
	return 0;
}