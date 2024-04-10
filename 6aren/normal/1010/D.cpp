#include<bits/stdc++.h>

using namespace std;

const int N = 1000005;

int n;
string s[N];
queue<int> Q;
vector<int> adj[N];
bool sta[N], check[N];

void bfs() {
	Q.push(1);
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		if (s[u] == "IN") {
			check[u] = 1;
		} 
		if (s[u] == "AND") {
			int c1 = adj[u][0], c2 = adj[u][1];
			if (sta[c1] == 1) {
				Q.push(c2);
			}
			if (sta[c2] == 1) {
				Q.push(c1);
			}
		}
		if (s[u] == "OR") {
			int c1 = adj[u][0], c2 = adj[u][1];
			if (sta[c1] == 0) {
				Q.push(c2);
			}
			if (sta[c2] == 0) {
				Q.push(c1);
			}
		}
		if (s[u] == "XOR") {
			int c1 = adj[u][0], c2 = adj[u][1];
			Q.push(c1);
			Q.push(c2);			
		}
		if (s[u] == "NOT") {
			Q.push(adj[u][0]);
		}
	}
}

void dfs(int u) {
	if (s[u] == "IN") {
		return;
	}
	if (s[u] == "AND") {
		sta[u] = true;
		for (auto x : adj[u]) {
			dfs(x);
			sta[u] &= sta[x];
		}
	}
	if (s[u] == "OR") {
		sta[u] = false;
		for (auto x : adj[u]) {
			dfs(x);
			sta[u] |= sta[x];
		}
	}
	if (s[u] == "XOR") {
		sta[u] = false;
		for (auto x : adj[u]) {
			dfs(x);
			sta[u] ^= sta[x];
		}
	}
	if (s[u] == "NOT") {
		sta[u] = true;
		dfs(adj[u][0]);
		sta[u] = !sta[adj[u][0]];
	}
}

int main() {
	//freopen("in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> s[i];
		if (s[i] == "IN") {
			cin >> u;
			sta[i] = u;
		} else if (s[i] == "AND") {
			cin >> u >> v;
			adj[i].push_back(u);
			adj[i].push_back(v);
		} else if (s[i] == "OR") {
			cin >> u >> v;
			adj[i].push_back(u);
			adj[i].push_back(v);
		} else if (s[i] == "XOR") {
			cin >> u >> v;
			adj[i].push_back(u);
			adj[i].push_back(v);
		} else {
			cin >> u;
			adj[i].push_back(u);
		}
	}
	dfs(1);
	bfs();
	for (int i = 1; i <= n; i++) {
		if (s[i] == "IN") {
			cout << (check[i] ^ sta[1]);
		}
	}
	return 0;
}