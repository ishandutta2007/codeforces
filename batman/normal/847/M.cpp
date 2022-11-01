//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

using namespace std ;

int const N = 100 + 20 ;
int n , a[N] ;
bool fl = 1 ;

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n ;

	for (int i = 0 ; i < n ; i ++) cin >> a[i] ;

	for (int i = 2 ; i < n ; i ++) fl &= ((a[i] - a[i - 1]) == (a[i - 1] - a[i - 2])) ;


	cout << (!fl ? a[n - 1] : 2 * a[n - 1] - a[n - 2]) << '\n' ;
}