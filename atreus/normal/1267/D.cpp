#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 300 + 5;
const ll inf = 1e18 + 10;

int a[maxn], b[maxn], cnt, candid[maxn];
vector<int> g[maxn];
bool deg[maxn], mark[maxn], visited[maxn];
bool F[maxn];
int n, M;

void DFS(int v){
	mark[v] = 1;
	for (auto u : g[v])
		if (!mark[u])
			DFS(u);
}

void dfs(int v){
	mark[v] = 1;
	for (int i = 0; i < n; i++){
		if (!mark[i] and a[i] == (a[v] & b[v])){
			g[v].push_back(i);
			M ++;
			dfs(i);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 3; j++){
			int k;
			cin >> k;
			a[i] += (k << j);
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 3; j++){
			int k;
			cin >> k;
			b[i] += (k << j);
		}
	}
	dfs(0);
	for (int i = 0; i < n; i++)
		if (mark[i])
			visited[a[i]] = 1;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (!mark[i] or !mark[j])
				continue;
			int f = (a[i] & b[i]), s = (a[j] & b[j]);
			if (!visited[f | s]){
				visited[f | s] = 1;
				for (int k = 0; k < n; k++){
					if (a[k] == (f | s)){
						g[i].push_back(k);
						g[j].push_back(k);
						M += 2;
						F[k] = true;
						for (int x = 0; x < n; x++){
							if (a[x] == a[k] and x != k){
								g[k].push_back(x);
								M ++;
							}
						}
						break;
					}
				}
			}
		}
	}
	memset(mark, 0, sizeof mark);
	DFS(0);
	for (int i = 0; i < n; i++)
		if (!mark[i])
			return cout << "Impossible\n", 0;
	cout << "Possible\n";
	for (int i = 0; i < n; i++)
		cout << 1 - F[i] << " ";
	cout << endl;
	cout << M << endl;
	for (int i = 0; i < n; i++){
		for (auto j : g[i]){
			cout << i + 1 << " " << j + 1 << endl;
		}
	}
}