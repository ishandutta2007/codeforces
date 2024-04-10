/*
 * 	Just close your eyes
 * 		The sun is going down
 * 			You'll be alright...
 * 				No one can hurt you now
 * 					Come, morning light...
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
//#define int long long
typedef long long ll;
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll inf=1e18;
const int mod=998244353;
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vi> dp[501];
ll lul[505],plul[505];
void solve() {
	int n,k;
	cin>>n>>k;
	for(int i=0; i<=500; i++)
	{
		dp[i].resize(i+1,vi());
		for(int j=0; j<=i; j++)
			dp[i][j].resize(j+1);
	}
	dp[0][0][0]=1;
	for(int i=0; i<500; i++)
		for(int j=0; j<=i; j++)
		{
			for(int k=0; k<j; k++)
			{
				dp[i+1][j][k+1]+=dp[i][j][k];
				dp[i+1][j][1]+=dp[i][j][k];
				if(dp[i+1][j][k+1]>=mod)
					dp[i+1][j][k+1]-=mod;
				if(dp[i+1][j][1]>=mod)
					dp[i+1][j][1]-=mod;
			}
			dp[i+1][j+1][j+1]+=dp[i][j][j];
			dp[i+1][j][1]+=dp[i][j][j];
			if(dp[i+1][j][1]>=mod)
				dp[i+1][j][1]-=mod;
			if(dp[i+1][j+1][1]>=mod)
				dp[i+1][j+1][1]-=mod;
		}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
			lul[i]+=dp[n][i][j];
		lul[i]%=mod;
		plul[i]=(lul[i]+plul[i-1])%mod;
	}
	ll ans=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(i*j<k)
				ans=(ans+lul[i]*lul[j])%mod;
	cout<<(ans*2)%mod<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	auto clk=clock();
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}