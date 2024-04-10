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
struct T {
	int idx;
	int t;
	int x;
	bool operator<(const T &right) const {
		return ((idx == right.idx) ? (t < right.t) : (idx < right.idx));
	}
};
vector <vector<int> >g;
vector<int> depth;
vector<int> idx;
vector<int> R;
vector<int> V;
vector<int> res;
vector<vector<T> > X;
int c = 0;
void dfs(int a, int p, int d) {
	//cerr << a << " " << p <<" " <<  d << endl;
	idx[a] = c;
	c++;
	depth[a] = d;
	X[d].push_back(T{ idx[a],1,a });
	for (int i = 0; i < g[a].size(); i++) {
		if (g[a][i] != p) {
			dfs(g[a][i], a, d + 1);
		}
	}
	R[a] = c;
	c++;
}
void dfs2(int a, int p, int x) {
	x += V[a];
	res[a] = x;
	for (int i = 0; i < g[a].size(); i++) {
		if (g[a][i] != p) {
			dfs2(g[a][i], a, x);
		}
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	g.resize(N);
	depth.resize(N);
	idx.resize(N);
	R.resize(N);
	X.resize(N);
	V.resize(N);
	res.resize(N);
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0, -1, 0);
	int Q;
	cin >> Q;
	int v, d, x;
	for (int i = 0; i < Q; i++) {
		cin >> v >> d >> x;
		v--;
		X[depth[v]].push_back(T{ idx[v],0,x });
		X[depth[v]].push_back(T{ idx[v] + 1,0,-x });
		if (depth[v] + d + 1 < N) {
			X[depth[v] + d + 1].push_back(T{ idx[v],0,-x });
			X[depth[v] + d + 1].push_back(T{ R[v],0,x });
		}
	}
	for (int i = 0; i < N; i++) {
		sort(X[i].begin(), X[i].end());
		int sum = 0;
		for (int j = 0; j < X[i].size(); j++) {
			if (X[i][j].t == 0) {
				sum += X[i][j].x;
			}
			else {
				V[X[i][j].x] = sum;
			}
		}

	}
	/*for (int i = 0; i < N; i++) {
		cout << V[i] << " ";
	}
	cout << endl;*/
	dfs2(0, -1, 0);
	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}