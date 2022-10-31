#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;
struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) {}
	bool unionSet(int x, int y) {
		x = root(x);
		y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y];
			data[y] = x;
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
	vector<string> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		int k = 0;
		for (int j = 0; j < M; j++) {
			if (A[i][j] == '#' && k == 0) {
				k = 1;
			} else if (A[i][j] == '.' && k == 1) {
				k = 2;
			} else if (A[i][j] == '#' && k == 2) {
				k = 3;
			}
		}
		if (k == 3) {
			cout << -1 << endl;
			return 0;
		}
	}
	for (int j = 0; j < M; j++) {
		int k = 0;
		for (int i = 0; i < N; i++) {
			if (A[i][j] == '#' && k == 0) {
				k = 1;
			} else if (A[i][j] == '.' && k == 1) {
				k = 2;
			} else if (A[i][j] == '#' && k == 2) {
				k = 3;
			}
		}
		if (k == 3) {
			cout << -1 << endl;
			return 0;
		}
	}
	UnionFind uf(N + M);
	set<int> si;
	set<int> sj;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] == '#') {
				uf.unionSet(i, j + N);
				si.insert(i);
				sj.insert(j);
			}
		}
	}
	if ((si.size() == N && sj.size() < M) || (si.size() < N && sj.size() == M)) {
		cout << -1 << endl;
		return 0;
	}
	set<int> st;
	for (int i = 0; i < N + M; i++) {
		if (uf.size(i) > 1) {
			if (st.count(uf.root(i)) == 0) {
				res++;
				st.insert(uf.root(i));
			}
		}
	}
	cout << res << endl;
}