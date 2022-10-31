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

pair<int, int> dfs(int a, int p = -1) {
	pair<int, int> res;
	res.second = 0;
	int cnt = 0;
	for (int i : g[a]) {
		if (p != i) {
			pair<int, int> t = dfs(i, a);
			res.second += t.second;
			cnt += t.first;
		}
	}
	if (cnt <= 1) {
		res.first = 1;
	}
	else if (cnt >= 2) {
		res.first = 0;
		res.second += cnt - 1;
	}


	return res;

}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, X, Y;
	cin >> N >> X >> Y;
	g.resize(N);
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int res = 0;

	if (X < Y) {
		pair<int,int> t = dfs(0);
		int y = t.first + t.second - 1;
		int x = N - 1 - y;
		res = x * X + y * Y;
	}
	else {
		bool ok = true;
		for (int i = 0; i < N; i++) {
			if ((int)g[i].size() == N - 1) {
				ok = false;
			}
		}
		if (ok) {
			res = (N - 1) * Y;
		}
		else {
			res = X + (N - 2) * Y;
		}


	}


	cout << res << endl;
}