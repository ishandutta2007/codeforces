#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 2000 + 5;

vector<int> t[2][maxn];
int x[maxn], y[maxn], dp0[1005][1005], dp1[1005][1005];
int h[2][maxn], par[2][maxn], lca[2][maxn][maxn];
int a, b;
bool cmpwh;

bool cmp(int v, int u){
	return h[cmpwh][v] < h[cmpwh][u];
}

void findlca(){
	vector<int> al;
	for (int i = 0; i < a; i++)
		al.push_back(i + 1);
	cmpwh = 0;
	sort(al.begin(), al.end(), cmp);
	for (int i = 0; i < a; i++){
		lca[0][al[i]][al[i]] = al[i];
		for (int j = i + 1; j < a; j++){
			int v = al[i], u = al[j];
			if (h[0][v] == h[0][u])
				lca[0][v][u] = lca[0][par[0][v]][par[0][u]];
			else
				lca[0][v][u] = lca[0][v][par[0][u]];
			lca[0][u][v] = lca[0][v][u];
		}
	}
	al.clear();
	for (int i = 0; i < b; i++)
		al.push_back(i + 1);
	cmpwh = 1;
	sort(al.begin(), al.end(), cmp);
	for (int i = 0; i < b; i++){
		lca[1][al[i]][al[i]] = al[i];
		for (int j = i + 1; j < b; j++){
			int v = al[i], u = al[j];
			if (h[1][v] == h[1][u])
				lca[1][v][u] = lca[1][par[1][v]][par[1][u]];
			else
				lca[1][v][u] = lca[1][v][par[1][u]];
			lca[1][u][v] = lca[1][v][u];
		}
	}
}

void dfs(bool wh, int v, int p = -1){
	par[wh][v] = p;
	for (auto u : t[wh][v])
		if (u != p)
			h[wh][u] = h[wh][v] + 1, dfs(wh, u, v);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cin >> a;
	for (int i = 2; i <= a; i++){
		int p;
		cin >> p;
		t[0][p].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	cin >> b;
	for (int i = 2; i <= b; i++){
		int p;
		cin >> p;
		t[1][p].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		cin >> y[i];
	dfs(0, 1);
	dfs(1, 1);
	findlca();	
	memset(dp0, 63, sizeof dp0);
	memset(dp1, 63, sizeof dp1);
	dp0[1][0] = h[0][x[1]];
	dp1[1][0] = h[1][y[1]];
	for (int i = 2; i <= n; i++){
		for (int j = 0; j < i; j++){
			if (j < i - 1){
				dp0[i][j] = dp0[i - 1][j] + h[0][x[i]] - h[0][lca[0][x[i]][x[i - 1]]];
				dp1[i][j] = dp1[i - 1][j] + h[1][y[i]] - h[1][lca[1][y[i]][y[i - 1]]];
				continue;
			}
			else{
				for (int k = i - 2; k >= 1; k--){
					dp0[i][j] = min(dp0[i][j], dp1[i - 1][k] + h[0][x[i]] - h[0][lca[0][x[i]][x[k]]]);
					dp1[i][j] = min(dp1[i][j], dp0[i - 1][k] + h[1][y[i]] - h[1][lca[1][y[i]][y[k]]]);
				}
				dp0[i][j] = min(dp0[i][j], dp1[i - 1][0] + h[0][x[i]]);
				dp1[i][j] = min(dp1[i][j], dp0[i - 1][0] + h[1][y[i]]);
			}
		}
	}
	int answer = max(a - 1, b - 1);
	for (int i = 0; i <= n - 1; i++)
		answer = max(answer, a + b - 2 - min(dp0[n][i], dp1[n][i]));
	cout << answer << endl;
}