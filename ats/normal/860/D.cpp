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
vector<int> visited;
vector<int> depth;
vector<int>res1;
vector<int>res2;
vector<int>res3;
bool dfs(int a, int from,int d) {
	depth[a] = d;
	visited[a] = 1;
	int v1 = -1;
	bool f;
	for (int i = 0; i < ed[a].size(); i++) {
		f = true;
		if (visited[ed[a][i]] == 0) {
			f = dfs(ed[a][i], a,d+1);
		}
		if (ed[a][i] != from && depth[a]<=depth[ed[a][i]]) {
			if (f) {
				if (v1 == -1) {
					v1 = ed[a][i];
				}
				else {
					res1.push_back(v1);
					res2.push_back(a);
					res3.push_back(ed[a][i]);
					v1 = -1;
				}

			}
		}
	}
	if (v1 != -1) {
		if (from != -1) {
			res1.push_back(v1);
			res2.push_back(a);
			res3.push_back(from);
			return false;
		}
	}
	return true;
}
signed main() {
	
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,M;
	cin >> N>>M;
	ed.resize(N);
	depth.resize(N);
	visited.resize(N,0);
	
	vector<int> A(N);
	int res = 0;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--;
		b--;
		ed[a].push_back(b);
		ed[b].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		if (visited[i] == 0) {
			dfs(i, -1,0);
		}
	}
	cout << res1.size() << endl;
	for (int i = 0; i < res1.size(); i++) {
		cout << res1[i]+1 << " "<<res2[i]+1 << " "<<res3[i]+1 << endl;
	}
}