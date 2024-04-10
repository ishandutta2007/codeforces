#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 5010;

ll n, a, b, k, x, y, ans;
ll dp[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>a>>b>>k;
	dp[0][a]=1;
	for (int i=0; i<k; i++){
		for (int x=1; x<b; x++){
			dp[i+1][max(1ll, 2*x-b+1)]=(dp[i+1][max(1ll, 2*x-b+1)]+dp[i][x])%mod;
			dp[i+1][x]=(dp[i+1][x]-dp[i][x])%mod;
			dp[i+1][x+1]=(dp[i+1][x+1]+dp[i][x])%mod;
			dp[i+1][b]=(dp[i+1][b]-dp[i][x])%mod;
		}
		for (int x=b+1; x<=n; x++){
			dp[i+1][b+1]=(dp[i+1][b+1]+dp[i][x])%mod;
			dp[i+1][x]=(dp[i+1][x]-dp[i][x])%mod;
			dp[i+1][x+1]=(dp[i+1][x+1]+dp[i][x])%mod;
			dp[i+1][min(n+1, 2*x-b)]=(dp[i+1][min(n+1, 2*x-b)]-dp[i][x])%mod;
		}
		for (int j=1; j<MAXN; j++) dp[i+1][j]=(dp[i+1][j-1]+dp[i+1][j]+mod)%mod;
		//for (int j=1; j<MAXN; j++) dp[i+1][j]=(dp[i+1][j]-dp[i][j]+mod)%mod;
	}
	/*
	for (int i=0; i<=k; i++){
		for (int j=1; j<=n; j++) cerr<<dp[i][j]<<' ';cerr<<endl;
	}*/
	
	for (int i=1; i<=n; i++) ans=(ans+dp[k][i])%mod;
	cout<<(ans+mod)%mod<<endl;
	return 0;
}