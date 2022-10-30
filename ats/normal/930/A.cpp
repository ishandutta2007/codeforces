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
vector<vector<int> > ed;
vector<int> d;
void dfs(int a, int depth) {
	d[depth]++;
	for (int i = 0; i < ed[a].size(); i++) {
		dfs(ed[a][i], depth + 1);
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	int res = 0;
	int p;
	ed.resize(N);
	d.resize(N, 0);
	for (int i = 0; i < N - 1; i++) {
		cin >> p;
		p--;
		ed[p].push_back(i + 1);
	}
	dfs(0, 0);
	for (int i = 0; i < N; i++) {
		res += d[i] % 2;
	}
	cout << res << endl;
}