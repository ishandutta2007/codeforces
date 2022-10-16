/*
 * 	Meet me on the battlefield
*/
#pragma GCC optimize("Ofast,unroll-loops")
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
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
#define dpr(x) cout<<#x<<": "<<x<<endl
typedef vector<int> vi;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim)
{
	uniform_int_distribution<int> uid(0,lim);
	return uid(rang);
}

int a[100005];
ll dp[100005];
int seg[200005];
ll pre[200005];
int n;
int query(int l, int r) {
	int mini=infi;
	for(l+=n,r+=n; l<r; l>>=1,r>>=1) {
		if(l&1) mini=min(mini,seg[l++]);
		if(r&1) mini=min(mini,seg[--r]);
	}
	return mini;
}
void solve()
{
	int c;
	cin>>n>>c;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
		seg[n+i-1]=a[i];
	}
	for(int i=n-1; i>0; i--)
		seg[i]=min(seg[i<<1],seg[i<<1|1]);
	fill(dp,dp+n+1,infl);
	dp[0]=0;
	for(int i=0; i<n; i++) {
		dp[i+1]=min(dp[i+1],dp[i]+a[i+1]);
		if(i+c<=n)
			dp[i+c]=min(dp[i+c],dp[i]+pre[i+c]-pre[i]-query(i,i+c));
	}
	cout<<dp[n]<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(time(0));
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}