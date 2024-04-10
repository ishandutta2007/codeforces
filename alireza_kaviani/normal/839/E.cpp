#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 20;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , adj[MAXN] , dp[2][(1 << LOG)];
double k;

void solve(int id , int l , int r){
	dp[id][0] = (1ll << 40) - 1;
	for(int i = 1 ; i < (1 << (r - l)) ; i++){
		int x = __builtin_ctz(i);
		dp[id][i] = (dp[id][i - (1 << x)] & adj[x + l]);
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> k;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			int x; cin >> x;
			if(x){
				adj[i] |= (1ll << j);
			}
		}
		adj[i] |= (1ll << i);
	}
	solve(0 , 0 , n / 2);
	solve(1 , n / 2 , n);
	for(int i = 0 ; i < (1 << LOG) ; i++){
		if((dp[0][i] & i) == i){
			dp[0][i] = __builtin_popcount(i);
		}
		else{
			dp[0][i] = 0;
		}
		for(int j = 0 ; j < LOG ; j++){
			if(i & (1 << j)){
				dp[0][i] = max(dp[0][i] , dp[0][i ^ (1 << j)]);
			}
		}
	}
	int x = n / 2 , y = (1 << x) - 1 , ans = 0;
	for(int i = 0 ; i < (1 << (n - x)) ; i++){
		if(((dp[1][i] >> x) & i) != i)	continue;
		ans = max((ll)ans , __builtin_popcount(i) + dp[0][(dp[1][i] & y)]);
	}
	double res = (k / ans) * (k / ans) * ans * (ans - 1) / 2;
	printf("%.10f" , res);

    return 0;
}
/*

*/