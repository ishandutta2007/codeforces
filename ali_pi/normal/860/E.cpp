#include<bits/stdc++.h>

#define pb push_back
#define ll long long 

using namespace :: std ; 

const int MAXN = 501 * 1001 ; 

vector<int> adj[MAXN] ; 

int par[MAXN][20] ; 

int h[MAXN] ; 

vector<int> v[MAXN] ; 

void dfs(int u , int p)
{
	v[h[u]].pb(u) ; 
	par[u][0] = p ; 
	for(int i = 1 ; i < 20 ; i ++ ) 
		par[u][i] = par[par[u][i-1]][i-1] ; 
	for(auto v : adj[u])
	{
		if(v==p) continue ; 
		h[v] =  h[u] + 1 ; 
		dfs(v,u) ; 
	}
}

int ipar(int x , int y)
{
	for(int i = 0 ; i < 20 ; i ++ ) 
		if(y&(1<<i))
			x = par[x][i] ; 
	return x ; 
}

int lca(int x , int y)
{
	if(h[y]<h[x]) swap(x,y) ; 
	y = ipar(y,h[y]-h[x]) ; 
	if(x==y) return x ; 
	for(int i = 19 ; i > -1 ; i -- ) 
		if(par[x][i]!=par[y][i])
			x = par[x][i] , y = par[y][i] ; 
	return par[x][0] ; 
}

ll ans[MAXN] ; 

int main()
{
	ios::sync_with_stdio(0) ; 
	cin.tie(0) ; 
	int n ;
	cin >> n ;
	int r ; 	
	for(int i = 1 ; i <= n ; i ++ ) 
	{
		int x ; 
		cin >> x ; 
		if(x) adj[x].pb(i) ; 
		else r = i ; 
	}
	dfs(r,-1) ; 
	for(int i = 1 ; i < MAXN ; i ++ ) 
	{
		if(!v[i].size()) break ; 
		for(int _ = 0 ; _ < 2 ; _ ++ ) {
			vector<int> v2 ; 
			int n = v[i].size() ; 
			for(int j = 0 ; j < n - 1 ; j ++ ) v2.pb(h[lca(v[i][j],v[i][j+1])]+1) ; 
			vector<int> st ; 
			ll Ans = 0 ;
			st.pb(-1) ; 	
			for(int j = 1 ; j < n ; j ++ ) 
			{
				while(st.size() > 1 && v2[st.back()] > v2[j-1]) 
					Ans -= 1ll * v2[st.back()] * (st.back() - st[st.size()-2]) , st.pop_back() ; 
				Ans += 1ll * (j - 1 - st.back()) * v2[j-1] ;
				ans[v[i][j]] += Ans ; 	
				st.pb(j-1) ; 
			}		
			reverse(v[i].begin(),v[i].end()) ; 
		}
		for(auto u : v[i]) ans[u] += ans[par[u][0]] + h[u] ; 
	}
	for(int i = 1 ; i <= n ; i ++ ) cout << ans[i] << ' ' ;
	cout << endl ; 
        return 0;
}