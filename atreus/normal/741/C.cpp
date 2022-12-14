#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

bool visited[maxn], a[maxn];
vector<int> g[maxn];
pair<int,int> e[maxn];

void dfs(int v){
	visited[v] = 1;
	for (auto u : g[v]){
		if (!visited[u]){
			a[u] = a[v] ^ 1;
			dfs(u);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int edge = 1; edge <= n; edge++){
		int v, u;
		cin >> v >> u;
		g[v].push_back(u);
		g[u].push_back(v);
		e[edge] = {v, u};
	}
	for (int i = 1; i <= n; i++){
		g[2 * i + 0].push_back(2 * i + 1);
		g[2 * i + 1].push_back(2 * i + 0);
	}
	for (int i = 1; i <= 2 * n; i++)
		if (!visited[i])
			dfs(i);
	for (int i = 1; i <= n; i++){
		if (a[e[i].first] == 1)
			cout << "1 2\n";
		else
			cout << "2 1\n";
	}
}