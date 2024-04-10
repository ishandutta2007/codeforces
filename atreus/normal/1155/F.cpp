#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 16384 + 10;

int adj[19][19];
int hamil[maxn], a[maxn][19][19], dp[maxn], par[maxn];
vector<pair<int,int>> ops;
int n;

void print(int f, int s, int mask){
	while (mask){
		int nex;
		for (int i = 0; i < n; i++)
			if (mask & (1<<i) and a[mask^(1<<f)][f][i] and adj[i][s])
				nex = i;
		assert(adj[nex][s]);
		ops.push_back({nex,s});
		mask ^= (1<<nex);
		s = nex;
	}
	assert(adj[f][s]);
	ops.push_back({f,s});
}

int main(){
	ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		v--, u--;
		adj[v][u] = adj[u][v] = 1;
	}
	for (int i = 0; i < n; i++)
		a[(1<<i)][i][i] = 1;
	for (int mask = 0; mask < (1<<n); mask++){
		for (int i = 0; i < n; i++){
			if (!(mask & (1<<i)))
				continue;
			for (int j = 0; j < n; j++){
				if (i == j or !(mask & (1<<i)))
					continue;
				for (int k = 0; k < n; k++){
					if (k == j or !(mask & (1<<k)) or !adj[j][k])
						continue;
					a[mask][i][j] |= a[mask^(1<<j)][i][k];
				}
			}
		}
	}
	memset(dp, 63, sizeof dp);
	for (int mask = 0; mask < (1<<n); mask++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (__builtin_popcount(mask) > 2 and i != j and mask & (1<<i) and mask & (1<<j) and a[mask][i][j] and adj[j][i])
					dp[mask] = __builtin_popcount(mask);

	for (int mask = 0; mask < (1<<n); mask++){
		if (__builtin_popcount(mask) <= 2 or dp[mask] == __builtin_popcount(mask))
			continue;
		for (int sub = mask; sub; sub = (sub - 1) & mask){
			for (int i = 0; i < n; i++){
				if (!(mask & (1<<i)) or sub & (1<<i))
					continue;
				for (int j = 0; j < n; j++){
					if (!(mask & (1<<j)) or sub & (1<<j))
						continue;
					if (a[sub^(1<<i)^(1<<j)][i][j] and dp[mask^sub] + __builtin_popcount(sub) + 1 < dp[mask]){
						dp[mask] = dp[mask^sub] + __builtin_popcount(sub) + 1;
						par[mask] = sub;
					}
				}
				if (dp[sub^(1<<i)] == __builtin_popcount(sub^(1<<i)) and dp[sub^(1<<i)] + dp[mask^sub] < dp[mask]){
					dp[mask] = dp[sub^(1<<i)] + dp[mask^sub];
					par[mask] = sub;
				}
			}
		}
	}
	
	int mask = (1<<n)-1;
	cout << dp[mask] << '\n';
	while (dp[mask] != __builtin_popcount(mask)){
		bool found = 0;
		int sub = par[mask];
		for (int i = 0; !found and i < n; i++){
			if (!(mask & (1<<i)) or sub & (1<<i))
				continue;
			for (int j = 0; j < n; j++){
				if (!(mask & (1<<j)) or sub & (1<<i))
					continue;
				if (a[sub^(1<<i)^(1<<j)][i][j]){
					print(i, j, sub);
					mask ^= sub;
					if (mask == 0)
						ops.push_back({i,j});
					found = 1;
					break;
				}
			}
		}
		if (found == 0){
			for (int i = 0; i < n; i++){
				if (!(mask & (1<<i)) or sub & (1<<i))
					continue;
				if (dp[mask] != dp[sub^(1<<i)] + dp[mask^sub])
					continue;
				for (int j = 0; j < n; j++){
					if (sub & (1<<j) and a[sub^(1<<i)][i][j] and adj[i][j]){	
						found = 1;
						print(i, j, sub^(1<<j));
						ops.push_back({i,j});
						break;
					}
				}
			}
			mask ^= sub;
		}
	}
	bool found = 0;
	for (int i = 0; !found and i < n; i++)
		for (int j = 0; !found and j < n; j++)
			if (a[mask][i][j] and adj[i][j]){
				found = 1;
				print(i, j, mask^(1<<i)^(1<<j));
				assert(adj[i][j]);
				ops.push_back({i,j});
			}
	for (auto it : ops)
		cout << ++it.first << " " << ++it.second << '\n';
}