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

const ll MAXN = 4e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
//const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , MOD , dp[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	dp[1] = 1;
	cin >> n >> MOD;
	for(int i = 1 ; i < MAXN ; i++){
		dp[i] = (dp[i] + 2 * dp[i - 1]) % MOD;
		ll x = (dp[i] + MOD - dp[i - 1]) % MOD;
		for(int j = max(i + 2 , i + i) ; j < MAXN ; j += i){
			dp[j] = (dp[j] + x);
			if(dp[j] >= MOD)	dp[j] -= MOD;
		}
	}
	cout << dp[n] << endl;

    return 0;
}
/*

*/