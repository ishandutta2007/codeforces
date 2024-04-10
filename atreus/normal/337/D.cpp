#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <set>
#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
const int maxn = 2e5 + 100;
vector <ll> v[maxn];
bool mark[maxn], visited[maxn];
pair <ll, ll> down[maxn];
ll up[maxn];

void dfs_up(int u, int par){
//	cout << u << " " << par << " = ";
	visited[u] = 1;
	if (mark[u])
		up[u] = 0;
	if (par != -1){
		if (up[par] != -1)
			up[u] = up[par] + 1;
		if (down[par].F == down[u].F + 1 and down[par].S != -1)
			up[u] = max(up[u], down[par].S + 1);
		else if (down[par].F != down[u].F + 1 and down[par].F != -1)
			up[u] = max(up[u], down[par].F + 1);
	}
//	cout << up[u] << endl;
	for (int i = 0; i < v[u].size(); i++){
		int w = v[u][i];
		if (!visited[w])
			dfs_up(w, u);
	}
}

void dfs_down(int u){
	visited[u] = 1;
	if (mark[u])
		down[u].F = 0;
	for (int i = 0; i < v[u].size(); i++){
		int w = v[u][i];
		if (!visited[w]){
			dfs_down (w);
			if (down[w].F != -1){
				down[u].S = max(down[u].S, down[w].F + 1);
				if (down[u].F < down[u].S)
					swap(down[u].F, down[u].S);
			}
		}
	}
}

int main() {
	int n, m, d;
	cin >> n >> m >> d;
	for (int i = 0; i < m; i++){
		int p;
		cin >> p;
		mark[p] = 1;
	}
	for (int i = 1; i < n; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB(w);
		v[w].PB(u);
	}
	memset (down, -1, sizeof down);
	memset (up, -1, sizeof up);
	dfs_down(1);
	memset (visited, 0, sizeof visited);
	dfs_up(1, -1);
	ll cnt = 0;
	for (int i = 1; i <= n; i++){
//		cout << down[i].F << " " << up[i] << endl;
		if (max(down[i].F, up[i]) <= d)
			cnt ++;
	}
	cout << cnt << endl;
}