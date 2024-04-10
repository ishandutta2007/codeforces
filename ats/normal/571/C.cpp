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
#include <assert.h>
using namespace std;
#define int long long
int MOD = 1000000007;
vector<int> ok;
vector<vector<int> > g;
vector<vector<int> > idx;
vector<vector<int> > ty;
vector<int> res;
void dfs1(int a) {

	for (int i = 0; i < g[a].size(); i++) {

		if (ok[g[a][i]] == 0) {
			ok[g[a][i]] = 1;
			res[idx[a][i]] = 1 - ty[a][i];
			dfs1(g[a][i]);
		}
	}
}
int es;
int vs;
int cy;
void dfs2(int a, int prev = -1) {
	vs++;
	es += g[a].size();
	ok[a] = 1;
	for (int i = 0; i < g[a].size(); i++) {
		if (idx[a][i] != prev) {
			if (ok[g[a][i]] == 0) {
				dfs2(g[a][i], idx[a][i]);
			}
			else {
				cy = a;
			}
		}
	}
}
vector<int>V;
void dfs3(int a, int prev = -1) {
	V[a] = 1;
	for (int i = 0; i < g[a].size(); i++) {
		if (idx[a][i] != prev && res[idx[a][i]] == -1) {
			if (V[g[a][i]] == 0) {
				res[idx[a][i]] = 1 - ty[a][i];

				dfs3(g[a][i], idx[a][i]);
			}
			else if(g[a][i] == cy){
				cy = -1;
				res[idx[a][i]] = 1 - ty[a][i];
			}
		}
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<pair<int, int> >  e(M + 1, pair<int, int>(-1, -1));
	vector<pair<int, int> >  s(M + 1);

	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		int a;
		for (int j = 0; j < k; j++) {
			cin >> a;
			if (e[abs(a)].first == -1) {
				e[abs(a)].first = i;
				s[abs(a)].first = (a > 0 ? 1 : 0);
			}
			else {
				e[abs(a)].second = i;
				s[abs(a)].second = (a > 0 ? 1 : 0);
			}
		}
	}
	ok.resize(N, 0);
	V.resize(N, 0);
	g.resize(N);
	idx.resize(N);
	ty.resize(N);
	res.resize(M, -1);
	for (int i = 1; i <= M; i++) {
		if (e[i].first == -1)continue;
		if (e[i].second == -1) {
			ok[e[i].first] = 1;
			res[i - 1] = s[i].first;
		}
		else {
			if (s[i].first == s[i].second) {
				ok[e[i].first] = 1;
				ok[e[i].second] = 1;
				res[i - 1] = s[i].first;
			}
			else {
				g[e[i].first].push_back(e[i].second);
				g[e[i].second].push_back(e[i].first);
				idx[e[i].first].push_back(i - 1);
				idx[e[i].second].push_back(i - 1);
				ty[e[i].first].push_back(s[i].first);
				ty[e[i].second].push_back(s[i].second);
			}
		}
	}
	
	//cerr << "hi" << endl;
	for (int i = 0; i < N; i++) {
		if (ok[i] == 1) {
			dfs1(i);
		}
	}
	
	for (int i = 0; i < N; i++) {
		if (ok[i] == 0) {
			vs = 0;
			es = 0;
			cy = -1;
			dfs2(i);
			//cerr << vs << " " << es << endl;
			if (cy == -1) {
				cout << "NO" << endl;
				return 0;
			}

			dfs3(cy);
			assert(cy == -1);
		}
	}
	for (int i = 0; i < res.size(); i++) {
		if (res[i] == -1)res[i] = 0;
	}
	cout << "YES" << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
	}
	cout << endl;
}