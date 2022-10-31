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
	int mxsz = 1;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
			mxsz = max(mxsz, -data[x]);
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
	int N;
	cin >> N;
	vector<int> A(N);
	map<int, vector<int> > mp;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		mp[-A[i]].push_back(i);
	}
	UnionFind uf(N);
	vector<int> res(N);
	int cur = 0;
	for (auto m : mp) {
		auto &vec = m.second;
		for (auto i : vec) {
			for (int j = -1; j <= 1; j += 2) {
				if (i + j >= 0 && i + j < N && A[i + j] >= A[i]) {
					uf.unionSet(i, i + j);
				}
			}
		}
		while (cur < uf.mxsz) {
			res[cur] = -m.first;
			cur++;
		}
	}
	for (int i = 0; i < N; i++) {
		if(i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}