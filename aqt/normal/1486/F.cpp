
// Problem : F. Pairs of Paths
// Contest : Codeforces - Codeforces Round #703 (Div. 2)
// URL : https://codeforces.com/contest/1486/problem/F
// Memory Limit : 512 MB
// Time Limit : 6000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[300005];
int u[300005], v[300005], w[300005], a[300005], b[300005];
int dep[300005];
int par[300005];
int tbl[20][300005];
vector<int> lst[300005];
int dif[300005];
int fre[300005];

int lca(int u, int v){
	if(dep[u] < dep[v]){
		swap(u, v);
	}
	for(int d = 19; d>=0; d--){
		if(dep[tbl[d][u]] >= dep[v]){
			u = tbl[d][u];
		}
	}
	if(u == v){
		return u;
	}
	for(int d = 19; d>=0; d--){
		if(tbl[d][u] != tbl[d][v]){
			u = tbl[d][u];
			v = tbl[d][v];
		}
	}
	return tbl[0][u];
}

int clmb(int n, int x){
	if(dep[n] < x){
		return 0;
	}
	for(int d = 19; d>=0; d--){
		if(dep[tbl[d][n]] >= x){
			n = tbl[d][n];
		}
	}
	return n;
}

void dfs1(int n){
	for(int e : graph[n]){
		if(e != par[n]){
			dep[e] = dep[n] + 1;
			tbl[0][e] = par[e] = n;
			dfs1(e);
		}
	}
}

void dfs2(int n){
	for(int e : graph[n]){
		if(e != par[n]){
			dfs2(e);
			dif[n] += dif[e];
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<N; i++){
		int p, q;
		cin >> p >> q;
		graph[p].push_back(q);
		graph[q].push_back(p);
	}
	cin >> M;
	for(int i =1 ; i<=M; i++){
		cin >> u[i] >> v[i];
	}
	dep[1] = 1;
	dfs1(1);
	for(int d = 1; d<20; d++){
		for(int n = 1; n<=N; n++){
			tbl[d][n] = tbl[d-1][tbl[d-1][n]];
		}
	}
	for(int i = 1; i<=M; i++){
		w[i] = lca(u[i], v[i]);
		a[i] = clmb(u[i], dep[w[i]]+1);
		b[i] = clmb(v[i], dep[w[i]]+1);
		dif[u[i]]++;
		dif[v[i]]++;
		dif[w[i]] -= 2;
		if(a[i]){
			fre[a[i]]++;
		}
		if(b[i]){
			fre[b[i]]++;
		}
		lst[w[i]].push_back(i);
	}
	dfs2(1);
	long long ans = 0;
	for(int n = 1; n<=N; n++){
		map<int, int> mp1;
		map<pair<int, int>, int> mp2;
		int tot = 0;
		for(int k : lst[n]){
			ans += tot;
			tot++;
			if(a[k] > b[k]){
				swap(a[k], b[k]);
			}
			if(a[k]){
				ans -= mp1[a[k]];
				mp1[a[k]]++;
			}
			if(b[k]){
				ans -= mp1[b[k]];
				mp1[b[k]]++;
			}
			if(a[k] && b[k]){
				ans += mp2[make_pair(a[k], b[k])];
				mp2[make_pair(a[k], b[k])]++;
			}
		}
		for(int k : lst[n]){
			ans += dif[n];
			ans -= dif[a[k]] - fre[a[k]];
			ans -= dif[b[k]] - fre[b[k]];
		}
	}
	cout << ans;
}