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

const ll MAXN = 1e5 + 10;
const ll LOG = 60;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , A[MAXN] , val[LOG][MAXN] , dp[LOG][MAXN];

int index(int ind , ll x){
	int res = lower_bound(val[ind] , val[ind] + n , x) - val[ind];
	return res;
}

int count(int ind , ll L , ll R){
	return index(ind , R) - index(ind , L);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> A[i];
	}
	for(int i = 0 ; i < LOG ; i++){
		for(int j = 0 ; j < n ; j++){
			val[i][j] = (A[j] & ((1ll << i) - 1));
		}
		val[i][n] = (1ll << i);
		sort(val[i] , val[i] + n);
	}
	fill(dp[LOG - 1] , dp[LOG - 1] + MAXN , MOD);
	dp[LOG - 1][n] = 0;
	for(int i = LOG - 2 ; i >= 0 ; i--){
		for(int j = 0 ; j <= n ; j++){
			int c1 = count(i + 1 , val[i][j] , val[i][j] + (1ll << i));
			dp[i][j] = min(dp[i + 1][index(i + 1 , val[i][j])] + c1 , 
					dp[i + 1][index(i + 1 , val[i][j] + (1ll << i))] + n - c1);
		}
	}
	cout << dp[0][n] << endl;

    return 0;
}
/*

*/