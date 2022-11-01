//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define int long long

using namespace std ;

int const N = 3e5 + 20 ;
int n , k , cnt[N] ;

inline void err () {
	cout << "Impossible\n" ;
	exit(0) ;
}

void dfs (int v) {
	cnt[v] -- ;

	cout << '(' ;

	while (cnt[v + 1]) dfs(v + 1) ;

	cout << ')' ;
}

int32_t main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n >> k ;

	for (int i = 0 ; i <= k ; i ++) {
		k -= i ;
		cnt[i] ++ ;
		n -- ;
	
		if (n < 0) err() ;
	}

	if (k) cnt[k] ++ , n -- ;

	if (n < 0) err() ;

	while (n) cnt[0] ++ , n -- ;

	while (cnt[0]) dfs(0) ;	

	cout << '\n' ;
}