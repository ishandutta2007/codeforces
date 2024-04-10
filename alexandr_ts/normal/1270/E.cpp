#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cstdlib>
#include <map>
#include <string>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 1e5 + 1;
const int EPS = 1e-9;
const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 10;
const int N = 1e3 + 10;

pair<ll, ll> a[N];

vector<int> g[2][N];

int color[N];
ll dist[N][N];

void dfs(int v, int col) {
	color[v] = col;
	for (auto u : g[0][v]) {
		if (!color[u]) {
			dfs(u, col);
		}
	}
	for (auto u : g[1][v]) {
		if (!color[u]) {
			dfs(u, 3 - col);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	if (n == 2) {
		cout << "1\n1";
		return;
	}

	set<ll> dists;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			dist[i][j] = (a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second);
			dists.insert(dist[i][j]);
		}
	}

	int sh = 100;
	for (auto x : dists) {
		int cnt = 0;
		while (x % 2 == 0) {
			x /= 2;
			cnt++;
		}
		sh = min(sh, cnt);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] >>= sh;
		}
	}

	color[0] = 1;
	for (int i = 1; i < n; i++) {
		if (dist[0][i] % 2) {
			color[i] = 2;
		}
		else {
			color[i] = 1;
		}
	}
		
	vector<int> answer;
	for (int i = 0; i < n; i++) {
		assert(color[i]);
		if (color[i] == 1) {
			answer.push_back(i);
		}
	}
	assert(answer.size() < n);
	cout << answer.size() << "\n";
	for (auto x : answer) {
		cout << x + 1 << " ";
	}
}


int main() {
	//auto trash = freopen("a.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();

}