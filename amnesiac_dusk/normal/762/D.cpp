/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 * 	I dont know the meaning of life
 * 		But i know what's truly precious
 * 			The way it's leading me to be in love
 * 				No fear i can find me always in my heart
 * 	The life it's not for comparing things
 * 		So i hold both of light and shadow
 * 			The rays of stars will bring me to you
 * 				Throught the dark night skies
 * 					See the way to be shined
 * 	I dont know what's right for our lives
 * 		But i know the truth of my love
 * 			The way it feels our breaths at the wind
 * 				And the way i should go all my life
 * 					I swear to go wherever will be
 * 						Thus the grace i wouldn't have
 * 							Will always in my heart
 * 								Thus the grace i wouldn't have
 * 									Will always in my heart
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define double long double
//typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

int dp[100005][3];
int a[100005][3];
int sum[100005];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n)
		cin>>a[i][0];
	fr(i,1,n)
		cin>>a[i][1];
	fr(i,1,n)
		cin>>a[i][2];
	fr(i,1,n) {
		sum[i]=a[i][0]+a[i][1]+a[i][2];
		fill(dp[i],dp[i]+3,-infl);
	}
	dp[1][0]=a[1][0];
	dp[1][1]=dp[1][0]+a[1][1];
	dp[1][2]=dp[1][1]+a[1][2];
	dp[2][0]=sum[1]+sum[2];
	dp[2][1]=sum[1]+a[2][1]+a[2][2];
	dp[2][2]=sum[1]+sum[2];
	fr(i,1,n)
	{
		for(int j=0; j<3; j++)
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]+a[i+1][j]);
		dp[i+2][0]=max(dp[i+2][0],dp[i][0]+sum[i+1]+sum[i+2]);
		dp[i+2][0]=max(dp[i+2][0],dp[i][2]+sum[i+1]+sum[i+2]);
		dp[i+2][2]=max(dp[i+2][2],dp[i][0]+sum[i+1]+sum[i+2]);
		dp[i+2][2]=max(dp[i+2][2],dp[i][2]+sum[i+1]+sum[i+2]);
		dp[i+1][0]=max(dp[i+1][0],dp[i][1]+a[i+1][1]+a[i+1][0]);
		dp[i+1][2]=max(dp[i+1][2],dp[i][1]+a[i+1][1]+a[i+1][2]);
		dp[i+1][2]=max(dp[i+1][2],dp[i][0]+sum[i+1]);
		dp[i+1][0]=max(dp[i+1][0],dp[i][2]+sum[i+1]);
		dp[i+1][1]=max(dp[i+1][1],dp[i][0]+a[i+1][0]+a[i+1][1]);
		dp[i+1][1]=max(dp[i+1][1],dp[i][2]+a[i+1][2]+a[i+1][1]);
		dp[i+1][0]=max(dp[i+1][0],dp[i][1]+a[i+1][1]+a[i+1][0]);
		dp[i+1][2]=max(dp[i+1][2],dp[i][1]+a[i+1][1]+a[i+1][2]);
		trace(dp[i][0],dp[i][1],dp[i][2]);
	}
	cout<<dp[n][2]<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cerr<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}