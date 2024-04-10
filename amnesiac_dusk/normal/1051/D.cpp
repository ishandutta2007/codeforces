/*
 * 	i could never find the right way to tell you
 * 		have you noticed i've been gone?
 * 			cause i left behind the home that you made me
 * 				but i will carry it along
 * 	mm it's a long way forward
 * 		so trust in me
 * 			i'll give them shelter like you've done for me
 * 				and i know i'm not alone
 * 					you'll be watching over us
 * 						until you're gone
 * 	when i'm older i'll be silent beside you
 * 		I know that words are not enough
 * 			and they won't need to know our names or our faces
 * 				but they will carry on for us
 */

#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
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
const ll infl=1e18;
const int infi=2e9;
const int mod=998244353;
#define dpr(x) cout<<#x<<": "<<x<<endl
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim)
{
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

int dp[1005][2005][4];
void solve() {
	int n,k;
	cin>>n>>k;
	dp[1][1][0]=dp[1][2][1]=dp[1][2][2]=dp[1][1][3]=1;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=k; j++) {
			for(int l=0; l<4; l++)
				dp[i][j][l]%=mod;
			//0 to something
			dp[i+1][j][0]+=dp[i][j][0];
			dp[i+1][j+1][1]+=dp[i][j][0];
			dp[i+1][j+1][2]+=dp[i][j][0];
			dp[i+1][j+1][3]+=dp[i][j][0];
			//1 to something
			dp[i+1][j][0]+=dp[i][j][1];
			dp[i+1][j][1]+=dp[i][j][1];
			dp[i+1][j+2][2]+=dp[i][j][1];
			dp[i+1][j][3]+=dp[i][j][1];
			//2 to something
			dp[i+1][j][0]+=dp[i][j][2];
			dp[i+1][j+2][1]+=dp[i][j][2];
			dp[i+1][j][2]+=dp[i][j][2];
			dp[i+1][j][3]+=dp[i][j][2];
			//3 to something
			dp[i+1][j+1][0]+=dp[i][j][3];
			dp[i+1][j+1][1]+=dp[i][j][3];
			dp[i+1][j+1][2]+=dp[i][j][3];
			dp[i+1][j][3]+=dp[i][j][3];
		}
	}
	cout<<(dp[n][k][0]+dp[n][k][1]+dp[n][k][2]+dp[n][k][3])%mod<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}
/**/