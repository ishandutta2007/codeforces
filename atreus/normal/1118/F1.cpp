/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 3e5 + 10;
int a[maxn], blues = 0, reds = 0;
vector<int> t[maxn];
int b[maxn], r[maxn], answer;

void dfs(int v, int par = -1){
	r[v] += (a[v] == 1);
	b[v] += (a[v] == 2);

	for (auto u : t[v]){
		if (u != par){
			dfs(u, v);
			b[v] += b[u];
			r[v] += r[u];
		}
	}
	
	if (par != -1){
		if (b[v] == blues and r[v] == 0)
			answer ++;
		if (b[v] == 0 and r[v] == reds)
			answer ++;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int v = 1; v <= n; v++){
		cin >> a[v];
		reds += (a[v] == 1);
		blues += (a[v] == 2);
	}
	for (int i = 1; i <= n - 1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	dfs(1);
	cout << answer << endl;
}