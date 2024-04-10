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
int N;
vector<vector<int> > g;
int solve1(int a, int p, int depth) {
	int mn = 2 * N;
	int sum = 0;
	for (int i = 0; i < g[a].size(); i++) {
		if (g[a][i] != p) {
			int t = solve1(g[a][i], a, depth + 1);
			mn = min(t, mn);
			sum += t;
		}
	}
	if (mn == 2 * N) {
		return 1;
	}
	if (depth % 2 == 0) {
		return mn;
	}
	else {
		return sum;
	}
}
int solve2(int a, int p, int depth) {
	int mn = 2 * N;
	int sum = 0;
	for (int i = 0; i < g[a].size(); i++) {
		if (g[a][i] != p) {
			int t = solve2(g[a][i], a, depth + 1);
			mn = min(t, mn);
			sum += t;
		}
	}
	//cerr << a << " " << sum << " " << mn << endl;
	if (mn == 2 * N) {
		return 1;
	}
	if (depth % 2 == 1) {
		return mn;
	}
	else {
		return sum;
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N;
	g.resize(N);
	int res = 0;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
	}
	int M = 0;
	for (int i = 0; i < N; i++) {
		if ((int)g[i].size() == 0) {
			M++;
		}
	}
	//cerr << M << endl;
	cout << M + 1 - solve1(0, -1, 0) << " " << solve2(0, -1, 0) << endl;
}