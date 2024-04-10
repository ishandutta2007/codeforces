#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int inf = 1e9;

vector<int> t[maxn];
vector<pair<int,int>> ops;

void dfs(int v, int time, int par = -1){
	int bef = time;
	int d = (int)t[v].size() - (par != -1);
	ops.push_back({v, time});
	for (auto u : t[v]){
		if (u == par)
			continue;
		if (v != 1 and time + d != bef - 1 and d <= bef - 1){
			time = bef - d - 1;
			ops.push_back({v, time});
		}
		dfs(u, ++time, v);
		ops.push_back({v, time});
		d --;
	}
	if (v != 1 and time != bef - 1)
		ops.push_back({v, bef-1});
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	dfs(1, 0);
	cout << ops.size() << endl;
	for (auto it : ops)
		cout << it.first << " " << it.second << '\n';
}