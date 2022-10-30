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
vector<int> col;
vector<int> v;
void dfs(int a, int c) {
	v[a] = 1;
	col[a] = c;
	for (int i = 0; i < ed[a].size(); i++) {
		if (v[ed[a][i]] == 0) {
			dfs(ed[a][i], 1 - c);
		}
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	ed.resize(N);
	col.resize(N);
	v.resize(N,0);
	int res = 0;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		a--;
		b--;
		ed[a].push_back(b);
		ed[b].push_back(a);
	}
	dfs(0, 0);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (col[i] == 0) {
			cnt++;
		}
	}
	cout << (cnt*(N - cnt) - N + 1) << endl;
}