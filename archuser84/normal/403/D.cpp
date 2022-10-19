///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int mod = 1e9+7;
const int N = 1010;
int dp[N][N]; // max-sum, count
int dpp[N][N];

void solve(){
	dpp[0][0] = dp[0][0] = 1;
	Loop(sum,1,N){
		dp[sum][0] = 1;
		Loop(n,1,N){
			for(int x = 1; x*n <= sum; ++x){
				dp[sum][n] += dpp[sum-x*n][n-1];
				dp[sum][n] -= dp[sum][n] >= mod? mod: 0;
			}
		}
		Loop(i,0,N) {
			dpp[sum][i] = dpp[sum-1][i]+dp[sum][i];
			dpp[sum][i] -= dpp[sum][i] >= mod? mod: 0;
		}
	}
	ll fct = 1;
	Loop(n,0,N){
		Loop(sum,0,N)
			dp[sum][n] = fct*dp[sum][n] % mod;
		fct = fct*(n+1) % mod;
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	solve();
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		cout << dp[n][k] << '\n';
	}
}