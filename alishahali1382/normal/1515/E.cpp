#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int N=410;

ll n, m, k, u, v, x, y, t, a, b, mod;
ll dp[N][N];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>mod;
	dp[1][1]=1;
	for (int i=1; i<n; i++) for (int j=1; j<=i; j++){
		dp[i+2][j-1]=(dp[i+2][j-1] + dp[i][j]*2*(j-1))%mod;
		dp[i+3][j-1]=(dp[i+3][j] + dp[i][j]*(j-1))%mod;
		dp[i+1][j+1]=(dp[i+1][j+1] + dp[i][j]*(j+1))%mod;
		dp[i+2][j]=(dp[i+2][j] + dp[i][j]*2*j)%mod;
		dp[i+1][j]=(dp[i+1][j] + dp[i][j]*2*j)%mod;
	}
	cout<<dp[n][1]<<"\n";
	
	return 0;
}
/*
10 1000000007

322064

*/