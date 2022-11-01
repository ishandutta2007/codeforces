#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int n, x[100000], y[100000], pw[200001], ret = 1;
map<int, vector<int>> mx, my;
vector<int> g[100000];
vector<bool> was(100000, false);
bool cyc;
set<int> X, Y;

void dfs(int v, int p) {
	X.insert(x[v]);
	Y.insert(y[v]);
	was[v] = true;
	for(int to : g[v]) {
		if(to == p) continue;
		if(was[to]) cyc = true;
		else dfs(to, v);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		mx[x[i]].push_back(i);
		my[y[i]].push_back(i);
	}
	for(auto it = mx.begin(); it != mx.end(); it++) {
		vector<int> v = it->second;
		sort(v.begin(), v.end());
		for(int i = 1; i < v.size(); i++) {
			g[v[i - 1]].push_back(v[i]);
			g[v[i]].push_back(v[i - 1]);
		}
	}
	for(auto it = my.begin(); it != my.end(); it++) {
		vector<int> v = it->second;
		sort(v.begin(), v.end());
		for(int i = 1; i < v.size(); i++) {
			g[v[i - 1]].push_back(v[i]);
			g[v[i]].push_back(v[i - 1]);
		}
	}
	pw[0] = 1;
	for(int i = 1; i <= 200000; i++) pw[i] = pw[i - 1] * 2 % mod;
	for(int i = 0; i < n; i++) {
		if(was[i]) continue;
		cyc = false;
		X.clear();
		Y.clear();
		dfs(i, -1);
		int mul = pw[X.size() + Y.size()];
		if(!cyc) mul = (mul - 1 + mod) % mod;
		ret = 1LL * ret * mul % mod;
	}
	cout << ret;
}