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

int a[500005];
vi gra[500005];
int dp[20][500005];
void dfs(int fr, int at) {
	dp[0][at]=fr;
	for(int i:gra[at])
		if(i!=fr)
			dfs(at,i);
}
void solve()
{
	int n,u,v;
	cin>>n;
	int rt=1;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]<a[rt])
			rt=i;
	}
	for(int i=1; i<n; i++) {
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	dfs(rt,rt);
	for(int i=1; i<20; i++)
		for(int j=1; j<=n; j++)
			dp[i][j]=dp[i-1][dp[i-1][j]];
	ll ans=0;
	for(int i=1; i<=n; i++)
		if(i!=rt) {
			ll mi=infl;
			for(int j=0; j<20; j++)
				mi=min(mi,(j+1LL)*a[dp[j][i]]);
			ans+=a[i]+mi;
		}
	cout<<ans<<endl;
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