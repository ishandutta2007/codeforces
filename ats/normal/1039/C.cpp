#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
struct UnionFind {
	set<int> X;
	vector<int> data;
	int cnt;
	UnionFind(int size) {
		data.resize(size, -1);
		cnt = size;
	}
	inline int updateData(int x, int v) {
		X.insert(x);
		data[x] = v;
		return v;
	}
	void undo() {
		for (auto x : X) {
			data[x] = -1;
		}
		X.clear();
		cnt = data.size();
	}
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			updateData(x, data[x] + data[y]);
			updateData(y, x);
			cnt--;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : updateData(x, root(data[x]));
	}
	int size(int x) {
		return -data[root(x)];
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M, K;
	cin >> N >> M >> K;
	set<int> st;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	map<int, vector<pair<int, int> > >mp;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--; b--;
		mp[A[a] ^ A[b]].emplace_back(a, b);
	}
	vector<int> p2(max(K + 5, N + 5));
	p2[0] = 1;
	for (int i = 1; i < p2.size(); i++) {
		p2[i] = (p2[i - 1] * 2) % MOD;
	}
	UnionFind uf(N);
	int res = 0;
	for (auto m : mp) {
		for (int i = 0; i < m.second.size(); i++) {
			uf.unionSet(m.second[i].first, m.second[i].second);
		}
		//cerr << m.first << " " << uf.cnt << endl;
		res = (res + p2[uf.cnt]);
		uf.undo();
	}
	a = p2[K] - (int)mp.size();
	if (a < 0)a += MOD;
	res = (res + ((a * p2[N]) % MOD)) % MOD;
	cout << res << endl;
}