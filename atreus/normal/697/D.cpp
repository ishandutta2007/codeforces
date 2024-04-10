#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

const int maxn = 1e5 + 100;
double expe[maxn];
bool mark[maxn];
int f[maxn];
vector <int> v[maxn];

void find_subtree(int u){
	mark[u] = 1;
	f[u] = 1;
	for (int i = 0; i < v[u].size(); i++){
		if (!mark[v[u][i]]){
			find_subtree (v[u][i]);
			f[u] += f[v[u][i]];
		}
	}
}

void dfs (int u, int dad){
	mark[u] = 1;
	int k = f[u] - 1;
	for (int i = 0; i < v[u].size(); i++){
		int w = v[u][i];
		if (!mark[w]){
			expe[w] = 1.0 * (k - f[w]) / 2 + expe[u] + 1;
			dfs (w, u);
		}
	}
}

int main (){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++){
		int u;
		cin >> u;
		v[i].push_back(u);
		v[u].push_back(i);
	}
	expe[1] = 1.0;
	find_subtree(1);
	memset (mark, 0, sizeof mark);
	dfs (1, 0);
	for (int i = 1; i <= n; i++)
		cout << fixed << setprecision(1) << expe[i] << " ";
}