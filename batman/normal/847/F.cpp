//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

using namespace std ;

int const N = 100 + 20 ;
int n , k , m , cur , g[N] , a[N][N] , cnt[N] , last[N]  ;

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n >> k >> m >> cur ;

	for (int i = 0 ; i < cur ; i ++) cin >> g[i] , g[i] -- , cnt[g[i]] ++ , last[g[i]] = i ;

	for (int i = 0 ; i < n ; i ++) {
		for (int j = 0 ; j < n ; j ++) {
			if (i == j) continue ;
		
			if (cnt[i] > cnt[j]) a[i][j] = 0 ;
			else if (cnt[i] < cnt[j]) a[i][j] = cnt[j] - cnt[i] + 1 ;
			else if (!cnt[i]) a[i][j] = 1 ;
			else a[i][j] = (last[i] > last[j]) ;
		}
	}

	if (n == 1 && m) return cout << "1\n" , 0 ;

	for (int i = 0 ; i < n ; i ++) {
		vector <int> vec ;

		for (int j = 0 ; j < n ; j ++) 
			if (i != j) vec.push_back(a[i][j]) ;

		sort(vec.begin() , vec.end()) ;

		bool f1 = 0 , f2 = 0 ;

		if (k < n && vec[n - k - 1] <= m - cur ) f1 = 1 ;	
		else if (k == n) f1 = 1 ;

		if (!cnt[i] && m == cur) f1 = 0 ;
		
		vec.clear() ;

		for (int j = 0 ; j < n ; j ++)
			if (i != j) vec.push_back(a[j][i]) ;

		sort(vec.begin() , vec.end()) ;

		int sum = 0 ;

		if (!cnt[i]) f2 = 1 ;
		else if (k == n) f2 = 0 ;
		else {
			for (int j = 0 ; j < k ; j ++) sum += vec[j] ;
			if (sum <= m - cur) f2 = 1 ;
		}

		if (!f1) cout << "3 " ;
		else if (!f2) cout << "1 " ;
		else cout << "2 " ;
	}

	cout << '\n' ;
}