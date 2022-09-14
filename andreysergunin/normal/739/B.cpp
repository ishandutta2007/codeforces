#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

typedef long long ll;

using namespace std;	

vector<vector<int>> g;
vector<vector<ll>> d;
vector<set<pair<ll, int>>> st;
vector<ll> delta;
vector<int> ans;
vector<int> a;

void dfs(int v) {
	if (sz(g[v]) == 0) {
		st[v].insert({a[v], v});
		ans[v] = 0;
		delta[v] = 0;
		return;
	}

	for (int i = 0; i < sz(g[v]); ++i) 
		dfs(g[v][i]);

	for (int i = 0; i < sz(g[v]); ++i) {
		int u = g[v][i];
		
		delta[u] -= d[v][i];
		while (!st[u].empty() && (*st[u].begin()).first + delta[u] < 0)
			st[u].erase(st[u].begin());
	}

	int cur = g[v][0];

	for (int i = 1; i < sz(g[v]); ++i) {
		int u = g[v][i];

		if (sz(st[cur]) < sz(st[u])) 
			swap(cur, u);

		while (!st[u].empty()) {
			pair<ll, int> x = *st[u].begin();
			st[u].erase(x);
			x.first += delta[u];
			x.first -= delta[cur];
			st[cur].insert(x);
		}
	}

	swap(st[cur], st[v]);
	delta[v] = delta[cur];
	st[v].insert({a[v] - delta[v], v});
	ans[v] = sz(st[v]) - 1;
}

int main()
{
	// ifstream cin("input.txt");
	// ofstream cout("output.txt");

	iostream::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	g.resize(n);
	d.resize(n);
	a.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];


	for (int i = 1; i < n; ++i) {
		int p;
		ll w;
		cin >> p >> w;
		--p;
		g[p].push_back(i);
		d[p].push_back(w);
	}

	st.resize(n);
	delta.resize(n);
	ans.resize(n);
	dfs(0);

	for (int i = 0; i < n; ++i)
		cout << ans[i] << " ";
	cout << endl;


	return 0;
}