#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;
int INF = (int)1 << 60;
struct UnionFind {
	vector<int> data;
	vector<int> sz;
	vector<int> ng;
	UnionFind(int size) : data(size, -1), ng(size, 0) {
		sz.resize(size, 0);
		for (int i = 0; i < size / 2; i++) {
			sz[i] = 1;
		}
	}
	bool unionSet(int x, int y) {
		x = root(x);
		y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y];
			data[y] = x;
			sz[x] += sz[y];
			ng[x] |= ng[y];
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
	int Num_Ons(int x) {
		int res = INF;
		int r = root(x);
		if (ng[r] == 0) {
			res = min(res, sz[r]);
		}
		r = root(x + (data.size() / 2));
		if (ng[r] == 0) {
			res = min(res, sz[r]);
		}
		return res;
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	string S;
	cin >> S;
	vector<vector<int> > es(N);
	for (int i = 0; i < M; i++) {
		int K;
		cin >> K;
		for (int j = 0; j < K; j++) {
			int a;
			cin >> a;
			es[a - 1].push_back(i);
		}
	}
	int res = 0;
	UnionFind uf(2 * M);
	for (int i = 0; i < N; i++) {
		if (es[i].size() == 1) {
			res -= uf.Num_Ons(es[i][0]);
			if (S[i] == '0') {
				int rt = uf.root(es[i][0] + M);
				uf.ng[rt] = 1;
				//cerr << "HI" << rt<<endl;
			} else {
				int rt = uf.root(es[i][0]);
				uf.ng[rt] = 1;
			}
			res += uf.Num_Ons(es[i][0]);
		} else if (es[i].size() == 2) {
			if (S[i] == '1') {
				if (!uf.findSet(es[i][0], es[i][1])) {
					res -= uf.Num_Ons(es[i][0]);
					res -= uf.Num_Ons(es[i][1]);
					uf.unionSet(es[i][0], es[i][1]);
					uf.unionSet(es[i][0] + M, es[i][1] + M);
					res += uf.Num_Ons(es[i][0]);
				}
			} else {
				if (!uf.findSet(es[i][0], es[i][1] + M)) {
					res -= uf.Num_Ons(es[i][0]);
					res -= uf.Num_Ons(es[i][1]);
					uf.unionSet(es[i][0], es[i][1] + M);
					uf.unionSet(es[i][0] + M, es[i][1]);
					res += uf.Num_Ons(es[i][0]);
				}
			}
		}
		cout << res << "\n";
	}
}