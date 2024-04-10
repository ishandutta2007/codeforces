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
	vector<int> data;
	vector<int> sz;
	int mxsz = 0;
	UnionFind(int size) {
		data.resize(size, -1);
		sz.resize(size, 0);
	}
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
			sz[x] += sz[y];
			mxsz = max(mxsz, sz[x]);
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
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
	UnionFind uf(N);
	int a;
	for (int i = 0; i < K; i++) {
		cin >> a; a--;
		uf.sz[a] = 1;
	}
	vector<pair<int, pair<int, int> > > es(M);

	for (int i = 0; i < M; i++) {
		cin >> es[i].second.first >> es[i].second.second >> es[i].first;
		es[i].second.first--;
		es[i].second.second--;
	}
	sort(es.begin(), es.end());
	int res;
	for (int i = 0; i < es.size(); i++) {
		uf.unionSet(es[i].second.first, es[i].second.second);
		if (uf.mxsz == K) {
			res = es[i].first;
			break;
		}
	}
	for (int i = 0; i < K; i++) {
		if (i > 0)cout << " ";
		cout << res;
	}
	cout << endl;
}