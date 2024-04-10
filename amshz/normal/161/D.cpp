# include <bits/stdc++.h>

using namespace std;

const int xn = 5e4+10;
const int xk = 5e2+10;
vector <int> vec[xn];
vector <int> byb[xn];
bool mark[xn];
int n, k;
int t[xn][xk];

void dfs(int v){
	mark[v] = true;
	t[v][0] = 1;
	int p = 0;
	for (int i=0; i<vec[v].size(); i++){
		if (mark[vec[v][i]]) continue;
		byb[v].push_back(vec[v][i]);
		p++;
		dfs(vec[v][i]);
		for (int j=1; j<=k; j++) t[v][j] += t[vec[v][i]][j-1];
	}
	t[v][0] = 1;
}

int main(){
	cin >> n >> k;
	int x, y;
	for (int i=0; i<n-1; i++) cin >> x >> y, vec[x-1].push_back(y-1), vec[y-1].push_back(x-1);
	dfs(0);
	long long ans = 0, s, q = k/2;
	for (int r=1; r<(k+1)/2; r++){
		for (int v=0; v<n; v++){
			s = 0;
			for (int u=0; u<byb[v].size(); u++) s += t[byb[v][u]][r-1];
			for (int u=0; u<byb[v].size(); u++) ans += (s - t[byb[v][u]][r-1]) * (t[byb[v][u]][k-r-1]);
		}
	}
	if (k%2 == 0){
		for (int v=0; v<n; v++){
			if (byb[v].size() == 0) continue;
			s = t[byb[v][0]][q-1];
			for (int u=1; u<byb[v].size(); u++) ans += s * t[byb[v][u]][q-1], s += t[byb[v][u]][q-1];
		}
	}
	for (int v=0; v<n; v++) ans += t[v][k];
	cout << ans << endl;
}