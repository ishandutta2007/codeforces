#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 410, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll dp[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	dp[1][0]=dp[1][1]=1;
	for (int i=2; i<=n; i++){
		for (int c1=0; c1<=n; c1++) for (int c2=0; c2<=n; c2++) if (c1+c2+1<=n+5){
			dp[i][c1+c2]=(dp[i][c1+c2] + dp[i-1][c1]*dp[i-1][c2])%mod;
			dp[i][c1+c2+1]=(dp[i][c1+c2+1] + dp[i-1][c1]*dp[i-1][c2])%mod;
			dp[i][c1+c2]=(dp[i][c1+c2] + (dp[i-1][c1]*dp[i-1][c2]%mod)*2*(c1+c2))%mod;
			if (c1+c2) dp[i][c1+c2-1]=(dp[i][c1+c2-1] + (dp[i-1][c1]*dp[i-1][c2]%mod)*((c1+c2)*(c1+c2-1)%mod))%mod;
		}
	}
	cout<<dp[n][1]<<'\n';
	
	return 0;
}