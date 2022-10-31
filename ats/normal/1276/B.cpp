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
	int T;
	cin >> T;
	while (T--) {
		int N, M, A, B;
		cin >> N >> M >> A >> B;
		A--;
		B--;
		vector<int> X(M), Y(M);
		for (int i = 0; i < M; i++) {
			cin >> X[i] >> Y[i];
			X[i]--;
			Y[i]--;
		}
		int a1 = 0;
		int a2 = 0;
		{
			UnionFind uf(N);
			for (int i = 0; i < M; i++) {
				if (X[i] != A && Y[i] != A) {
					uf.unionSet(X[i], Y[i]);
				}
			}
			a1 = N - 1 - uf.size(B);
		}
		{
			UnionFind uf(N);
			for (int i = 0; i < M; i++) {
				if (X[i] != B && Y[i] != B) {
					uf.unionSet(X[i], Y[i]);
				}
			}
			a2 = N - 1 - uf.size(A);
		}
		cout << a1 * a2 << "\n";
	}
	return 0;
}