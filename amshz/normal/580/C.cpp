# include <bits/stdc++.h>

using namespace std;

const int xn = 1e5+10;
vector <int> vec[xn];
bool f[xn], mark[xn];
int ans = 0, n, m;

void dfs(int v, int k){
	mark[v] = true;
	int t = 0;
	for (int i=0; i<vec[v].size(); i++){
		if (mark[vec[v][i]]) continue;
		t++;
		if (f[v] and k == m) continue;
		if (f[v]) dfs(vec[v][i], k+1);
		else dfs(vec[v][i], 0);
	}
	if (f[v]) k++;
	else k = 0;
	if (t == 0 and k <= m) ans++;
}

int main(){
	cin >> n >> m;
	int x, y;
	for (int i=0; i<n; i++) cin >> f[i];
	for (int i=0; i<n-1; i++) cin >> x >> y, vec[x-1].push_back(y-1), vec[y-1].push_back(x-1);
	dfs(0,0);
	cout << ans << endl;
}