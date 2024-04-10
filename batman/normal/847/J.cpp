//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

using namespace std ;

int const N = 5000 + 20 ;
int	n , m , x[N] , y[N] , deg[N] , res ;
vector <int> g[N] ;

bool vis[N] ;

bool dfs (int v) {
	if (vis[v]) return 0 ;
	vis[v] = 1 ;

	if (deg[v] < res) return 1 ;
	
	for (int ed : g[v]) {
		if (x[ed] != v) continue ;

		int u = y[ed] ;

		if (dfs(u)) {
			swap(x[ed] , y[ed]) ;
			deg[v] -- , deg[u] ++ ;

			assert(deg[v] >= 0) ;

			return 1 ;
		}
	}

	return 0 ;
}

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n >> m ;

	for (int i = 0 ; i < m ; i ++) {
		cin >> x[i] >> y[i] ;
		x[i] -- , y[i] -- ;
		memset(vis , 0 , sizeof vis) ;
		if (!dfs(x[i])) {
			memset(vis , 0 , sizeof vis) ;

			if (dfs(y[i])) swap(x[i] , y[i]) ;
			else {
				res ++ ;
			}
		}

		deg[x[i]] ++ ;
	
	//	int mx = 0 ;
	//	for (int j = 0 ; j < n ; j ++) assert(deg[j] <= res) , mx = max(mx , deg[j]) ;
	//	assert(mx == res) ;

		g[x[i]].push_back(i) ;
		g[y[i]].push_back(i) ;
	}

	cout << res << '\n' ;

	for (int i = 0 ; i < m ; i ++) cout << x[i] + 1 << ' ' << y[i] + 1 << '\n' ;
}