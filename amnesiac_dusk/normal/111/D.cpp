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
#define int long long
typedef long long ll;
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll inf=1e18;
const int mod=1e9+7;
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll fact[1000005],ifact[1000005];
ll dp[1005];
inline ll ncr(int n, int r) {
	if(r>n) return 0;
	return (fact[n]*((ifact[r]*ifact[n-r])%mod))%mod;
}
ll powm(ll a, ll b) {
	ll an=1;
	while(b) {
		if(b&1)
			an=(an*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return an;
}
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	fact[0]=1;
	for(int i=1; i<=1000000; i++)
		fact[i]=(fact[i-1]*i)%mod;
	ifact[1000000]=powm(fact[1000000],mod-2);
	for(int i=999999; i>=0; i--)
		ifact[i]=(ifact[i+1]*(i+1))%mod;
	for(int i=1; i<=1000; i++)
	{
		dp[i]=powm(i,n);
		for(int j=1; j<i; j++)
			dp[i]=(dp[i]-dp[j]*ncr(i,j))%mod;
		dp[i]+=mod;
		dp[i]%=mod;
	}
	if(m==1) {
		cout<<powm(k,n);
		return;
	}
	ll ans=0;
	for(int i=1; i<=n; i++)
		for(int j=0; j<=i; j++)
			ans=(ans+((((((powm(j,(m-2)*n)*ncr(k,j))%mod)*ncr(k-j,i-j))%mod)*ncr(k-i,i-j))%mod)*powm(dp[i],2))%mod;
	cout<<ans;
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