#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

vector<int> t[maxn];
int p[maxn], match[maxn];

void dfs2(int v, int par = -1){
	if (match[v] != 0 and match[v] != par){
		if (par != -1 and p[par] == 0){
			p[par] = match[v];
			p[match[v]] = v;
			p[v] = par;
		}
		for (auto u : t[v]){
			if (u != par and u != match[v] and match[u] == 0){
				p[u] = p[v];
				p[v] = u;
			}
		}
	}
	for (auto u : t[v])
		if (u != par)
			dfs2(u,v);
}

bool dfs(int v, int par = -1){
	for (auto u : t[v]){
		if (u == par)
			continue;
		if (dfs(u,v))
			match[v] = u;
	}
	if (match[v] == 0)
		return true;
	p[v] = match[v], p[match[v]] = v;
	match[match[v]] = v;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n-1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	dfs(1);
	dfs2(1);
	int answer = 2*n;
	for (int i = 1; i <= n; i++)
		if (match[i] != 0)
			answer --;
	cout << answer << endl;
	for (int i = 1; i <= n; i++)
		cout << p[i] << " \n"[i == n];
}