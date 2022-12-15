#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef complex<long double> cd;

const int maxn = 3e4 + 5;
const int maxk = 200 + 5;

int h[maxn];
int can[maxn], par[maxn], d[maxk][maxn], a[maxn], up[maxk][maxn];
vector<int> t[maxn], vec[maxn];

void dfs(int v, int p = -1){
	for (auto u : t[v])
		if (u != p)
			h[u] = h[v] + 1, dfs(u, v);
}

bool cmp(int v, int u){
	return h[v] < h[u];
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++){
		int v, cnt = 0;
		for (int j = 1; j <= n; j++){
			cin >> d[i][j];
			if (d[i][j] == 0){
				v = j;
				cnt ++;
			}
		}
		if (cnt != 1)
			return cout << -1 << endl, 0;
		can[i] = v;
	}
	memset(par, -1, sizeof par);
	int root = can[1];
	for (int i = 1; i <= n; i++)
		h[i] = d[1][i];
	up[1][0] = root;
	for (int i = 2; i <= k; i++){
		for (int j = 1; j <= n; j++){
			if (h[j] + d[i][j] == h[can[i]]){
				a[h[j]] = j;
			}
		}
		for (int j = 1; j <= h[can[i]]; j++){
			if (par[a[j]] == -1)
				par[a[j]] = a[j - 1];
			up[i][j] = a[j];
		}
		up[i][0] = root;
	}
	vector<int> x;
	for (int i = 1; i <= n; i++)
		if (par[i] == -1 and i != root)
			x.push_back(i);
	for (int i = 1; i <= n; i++)
		vec[i].push_back(i);
	sort(x.begin(), x.end(), cmp);
	for (auto v : x){
		int u = -1;
		for (int j = 1; j <= k; j++){
			int y = (h[can[j]] + h[v] - d[j][v]) / 2;
			if (u == -1 or y >= h[u])
				u = up[j][y];
		}
		int diff = h[v] - h[u];
		if (diff == 0)
			return cout << -1 << endl, 0;
		if (vec[u].size() + 1 < diff)
			return cout << -1 << endl, 0;
		par[v] = vec[u][diff - 1];
		if (diff == vec[u].size())
			vec[u].push_back(v);
	}
	for (int i = 1; i <= n; i++){
		if (i == root)
			continue;
		t[i].push_back(par[i]);
		t[par[i]].push_back(i);
	}
	for (int i = 1; i <= k; i++){
		h[can[i]] = 0;
		dfs(can[i]);
		for (int j = 1; j <= n; j++)
			if (d[i][j] != h[j])
				return cout << -1 << endl, 0;
	}
	for (int i = 1; i <= n; i++)
		if (i != root)
			cout << i << " " << par[i] << endl;
}