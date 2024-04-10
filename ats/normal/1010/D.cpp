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
vector<string> S;
vector<int> V;
int dfs(int a) {
	int v[2];
	for (int i = 0; i < g[a].size(); i++) {
		v[i] = dfs(g[a][i]);
	}
	if (S[a] == "IN") {
	}
	else if (S[a] == "NOT") {
		V[a] = 1 - v[0];
	}
	else if (S[a] == "AND") {
		V[a] = v[0] & v[1];
	}
	else if (S[a] == "OR") {
		V[a] = v[0] | v[1];
	}
	else if (S[a] == "XOR") {
		V[a] = v[0] ^ v[1];
	}
	return V[a];
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	g.resize(N);
	S.resize(N);
	V.resize(N);
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
		if (S[i] == "IN") {
			cin >> V[i];
		}
		else if (S[i] == "NOT") {
			cin >> a; a--;
			g[i].push_back(a);
		}
		else {
			cin >> a >> b;
			a--;
			b--;
			g[i].push_back(a);
			g[i].push_back(b);
		}
	}
	int ans = dfs(0);
	queue<int> qu;
	qu.push(0);
	vector<int> res(N, 0);
	res[0] = 1;
	while ((int)qu.size() > 0) {
		int c = qu.front(); qu.pop();
		if (S[c] == "NOT") {
			res[g[c][0]] = 1;
			qu.push(g[c][0]);
		}
		else if (S[c] == "XOR") {
			res[g[c][0]] = 1;
			qu.push(g[c][0]);
			res[g[c][1]] = 1;
			qu.push(g[c][1]);
		}
		else if (S[c] == "OR") {
			if (((1 - V[g[c][0]]) | V[g[c][1]]) != V[c]) {
				res[g[c][0]] = 1;
				qu.push(g[c][0]);
			}
			if (((1 - V[g[c][1]]) | V[g[c][0]]) != V[c]) {
				res[g[c][1]] = 1;
				qu.push(g[c][1]);
			}
		}
		else if (S[c] == "AND") {
			if (((1 - V[g[c][0]]) & V[g[c][1]]) != V[c]) {
				res[g[c][0]] = 1;
				qu.push(g[c][0]);
			}
			if (((1 - V[g[c][1]]) & V[g[c][0]]) != V[c]) {
				res[g[c][1]] = 1;
				qu.push(g[c][1]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (S[i] == "IN") {
			cout << (res[i] ^ ans);
		}
	}
	cout << endl;

}