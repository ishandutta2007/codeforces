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
vector<int> cc;
vector<int> X;
int N, M;
void dfs(int a) {
	X[a] = 1;
	if (a < N) {
		cc.push_back(a);
	}
	for (int i : g[a]) {
		if (X[i] == 0) {
			dfs(i);
		}
	}

}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	g.resize(N + M);
	X.resize(N + M, 0);
	int k;
	int t;
	for (int i = 0; i < M; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> t; t--;
			g[N + i].push_back(t);
			g[t].push_back(N + i);
		}
	}
	vector<int> res(N);
	for (int i = 0; i < N; i++) {
		cc.clear();
		if (X[i] == 0) {
			dfs(i);
			for (int j = 0; j < cc.size(); j++) {
				res[cc[j]] = cc.size();
			}
		}

	}

	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}