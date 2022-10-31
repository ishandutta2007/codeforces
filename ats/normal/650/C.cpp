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
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
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
	int N, M;
	cin >> N >> M;
	vector<vector<int> > A(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	UnionFind uf(N * M);
	vector<vector<int> > g(N * M);
	vector<int> C(N*M, 0);
	for (int i = 0; i < N; i++) {
		vector<pair<int, int> > vp(M);
		for (int j = 0; j < M; j++) {
			vp[j] = make_pair(A[i][j], i * M + j);
		}
		sort(vp.begin(), vp.end());

		for (int j = 1; j < M; j++) {
			if (vp[j - 1].first == vp[j].first) {
				uf.unionSet(vp[j - 1].second, vp[j].second);
			}
		}
	}
	for (int i = 0; i < M; i++) {
		vector<pair<int, int> > vp(N);
		for (int j = 0; j < N; j++) {
			vp[j] = make_pair(A[j][i], j * M + i);
		}
		sort(vp.begin(), vp.end());

		for (int j = 1; j < N; j++) {
			if (vp[j - 1].first == vp[j].first) {
				uf.unionSet(vp[j - 1].second, vp[j].second);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		vector<pair<int, int> > vp(M);
		for (int j = 0; j < M; j++) {
			vp[j] = make_pair(A[i][j], uf.root(i * M + j) );
		}
		sort(vp.begin(), vp.end());

		for (int j = 1; j < M; j++) {
			if (vp[j - 1].first == vp[j].first) {
			}
			else {
				g[vp[j - 1].second].push_back(vp[j].second);
				C[vp[j].second]++;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		vector<pair<int, int> > vp(N);
		for (int j = 0; j < N; j++) {
			vp[j] = make_pair(A[j][i], uf.root(j * M + i) );
		}
		sort(vp.begin(), vp.end());

		for (int j = 1; j < N; j++) {
			if (vp[j - 1].first == vp[j].first) {
			}
			else {
				g[vp[j - 1].second].push_back(vp[j].second);
				C[vp[j].second]++;
			}
		}
	}

	queue<int> qu;

	vector<int> res(N * M);

	for (int i = 0; i < N*M; i++) {
		if (C[i] == 0) {
			qu.push(i);
			res[i] = 1;
		}
	}


	while (qu.size() > 0) {
		int a = qu.front(); qu.pop();

		for (int i : g[a]) {
			C[i]--;
			res[i] = max(res[i], res[a] + 1);
			if (C[i] == 0) {
				qu.push(i);
			}
		}

	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (j > 0)cout << " ";
			cout << res[uf.root(i * M + j)];
		}
		cout << endl;
	}

}