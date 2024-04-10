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
vector<vector<int> > g;
vector<vector<char> > col;
vector<int> V;
char X;
bool ok = true;
vector<vector<int> > vs;
int dfs(int a, int t) {
	if (V[a] == -1) {
		V[a] = t;
		vs[t].push_back(a);
		for (int i = 0; i < g[a].size(); i++) {
			if (col[a][i] == X) {
				dfs(g[a][i], t);
			}
			else {
				dfs(g[a][i], 1 - t);
			}
		}
	}
	else {
		if (V[a] != t) {
			ok = false;
		}
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	g.resize(N);
	col.resize(N);
	int a, b;
	char c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
		col[a].push_back(c);
		col[b].push_back(c);
	}
	X = 'B';
	vector<vector<int> > res(2);
	for (int t = 0; t < 2; t++) {
		V.clear();
		V.resize(N, -1);
		ok = true;
		for (int i = 0; i < N; i++) {
			if (V[i] == -1) {
				vs.clear();
				vs.resize(2);
				dfs(i, 0);

				if (vs[0].size() < vs[1].size()) {
					for (int j = 0; j < vs[0].size(); j++) {
						res[t].push_back(vs[0][j]);
					}
				}
				else {
					for (int j = 0; j < vs[1].size(); j++) {
						res[t].push_back(vs[1][j]);
					}
				}

			}
		}
		if (!ok) {
			res[t].clear();
			res[t].resize(N + 1, 0);
		}

		X = 'R';
	}

	if (res[0].size() < res[1].size()) {
		a = 0;
	}
	else {
		a = 1;
	}
	if ((int)res[a].size() == N + 1) {
		cout << -1 << endl;
	}
	else {
		cout << res[a].size() << endl;
		for (int i = 0; i < res[a].size(); i++) {
			if (i > 0)cout << " ";
			cout << res[a][i] + 1;
		}
		cout << endl;
	}
}