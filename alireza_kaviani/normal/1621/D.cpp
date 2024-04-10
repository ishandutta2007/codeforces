#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 510;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll q , n , C[MAXN][MAXN];

ll sum(int xl , int yl , int xr , int yr){
	ll ans = 0;
	for(int i = xl ; i <= xr ; i++){
		for(int j = yl ; j <= yr ; j++){
			ans += C[i][j];
		}
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		ll res = 0 , ans = INF;
		cin >> n;
		for(int i = 0 ; i < n + n ; i++){
			for(int j = 0 ; j < n + n ; j++){
				cin >> C[i][j];
				if(i >= n && j >= n){
					res += C[i][j];
					C[i][j] = 0;
				}
			}
		}
		/*for(int i = 0 ; i < n ; i++){
			for(int j = n ; j < n + n ; j++){
				ll x = min(sum(i , n , i , j) , sum(i , j , i , n + n - 1));
				ll y = min(sum(i , j , n , j) , sum(0 , j , i , j));
				ans = min(ans , x + y - C[i][j]);
			}
		}
		for(int i = n ; i < n + n ; i++){
			for(int j = 0 ; j < n ; j++){
				ll x = min(sum(n , j , i , j) , sum(i , j , n + n - 1 , j));
				ll y = min(sum(i , j , i , n) , sum(i , 0 , i , j));
				ans = min(ans , x + y - C[i][j]);
			}
		}*/
		ans = min({C[0][n] , C[0][n + n - 1] , C[n - 1][n] , C[n - 1][n + n - 1]});
		ans = min({C[n][0] , C[n + n - 1][0] , C[n][n - 1] , C[n + n - 1][n - 1] , ans});
		cout << ans + res << endl;
	}

    return 0;
}
/*

*/