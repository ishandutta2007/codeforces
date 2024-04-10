#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int maxn = 1e5 + 10;

vector<int> t[maxn];

int cnt, dad[maxn], h[maxn];
bool odd, eve;

void dfs(int v, int par = -1){
	if (t[v].size() == 1){
		if (h[v] & 1)
			odd |= 1;
		else
			eve |= 1;
		if (dad[par] == 0){
			dad[par] = 1;
			cnt ++;
		}
		return;
	}
	if (par != -1)
		cnt ++;
	for (auto u : t[v])
		if (u != par)
			h[u] = h[v] + 1, dfs(u, v);
}

int main(){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	int r = 1;
	for (int i = 2; i <= n; i++)
		if (t[i].size() != 1)
			r = i;
	dfs(r);
	int mnm = 1;
	if (eve & odd)
		mnm = 3;
	cout << mnm << " " << cnt << endl;
}