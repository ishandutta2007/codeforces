#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 2e2 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll dp[Maxn][Maxn][2];
ll a[Maxn];


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	memset(dp, 31, sizeof dp);
	dp[0][0][0] = 0;
	dp[0][0][1] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= n; j++){
			for(int b = 0; b < 2; b++)
			for(int k = 0; k < 2; k++){
				if((a[i + 1] != 0) && ((a[i + 1] & 1) != k)) continue;
				
				dp[i + 1][j + k][k] = min(dp[i + 1][j + k][k], dp[i][j][b] + ((b != k ? 1: 0)));
			}
		}
	}
	//cout << dp[4][0][1] << '\n';
	cout << min(dp[n][(n + 1)/2][0], dp[n][(n+1)/2][1]);
	
	return 0;
}