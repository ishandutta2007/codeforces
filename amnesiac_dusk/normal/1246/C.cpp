#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define trace(...)
//#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}


char a[2005][2005];
int dp[2005][2005],dp2[2005][2005];
int poc[2005][2005],por[2005][2005];
void solve() {
	int n,m;
	cin>>n>>m;
	fr(i,1,n)
		fr(j,1,m) {
			cin>>a[i][j];
			if(a[i][j]=='R')
				poc[i][j]=por[i][j]=1;
		}
	for(int i=n-1; i>0; i--)
		fr(j,1,m)
			poc[i][j]+=poc[i+1][j];
	fr(i,1,n)
		for(int j=m-1; j>0; j--)
			por[i][j]+=por[i][j+1];
	if(n==1) {
		if(por[1][1]==0) {
			cout<<1<<endl;
		} else
			cout<<0<<endl;
		return;
	}
	if(m==1) {
		if(poc[1][1]==0) {
			cout<<1<<endl;
		} else
			cout<<0<<endl;
		return;
	}
	dp[1][2]=1;
	dp2[2][1]=1;
	dp[1][m-por[1][1]+1]--;
	dp2[n-poc[1][1]+1][1]--;
////	trace(n-poc[1][1]+1);
//	fr(i,1,n) {
//		fr(j,1,m) {
//			cout<<por[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
//	fr(i,1,n) {
//		fr(j,1,m) {
//			cout<<poc[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	fr(i,1,n) {
		fr(j,1,m) {
			dp[i][j]+=dp[i][j-1];
			dp2[i][j]+=dp2[i-1][j];
			dp[i][j]%=mod;
			dp2[i][j]%=mod;
			dp2[i+1][j]+=dp[i][j];
			dp2[n-poc[i+1][j]+1][j]-=dp[i][j];
			dp[i][j+1]+=dp2[i][j];
			dp[i][m-por[i][j+1]+1]-=dp2[i][j];
		}
	}
//	fr(i,1,n) {
//		fr(j,1,m) {
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
//	fr(i,1,n) {
//		fr(j,1,m) {
//			cout<<dp2[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<((dp[n][m]+dp2[n][m])%mod+mod)%mod<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	fr(i,1,t)	{
//		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}