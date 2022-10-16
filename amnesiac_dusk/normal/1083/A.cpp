/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
*/
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
//typedef double f80;
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
#define deb cout<<"Line: "<<__LINE__<<" plz "
typedef long long ll;
const ll inf=1e18;
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

int w[300001];
vector<pii> gra[300001];
int dp[300001];
int ans=0;
int dfs(int fr, int at, int val)
{
	int lol=w[at];
	int lol1=0;
	for(auto i:gra[at])
		if(i.fi!=fr)
		{
			int temp=dfs(at,i.fi,max(max(0LL,lol1+lol-i.se),lol+val-i.se));
			lol1=max(lol1,temp-i.se);
		}
	ans=max(ans,val+w[at]+lol1);
	return lol1+lol;
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>w[i];
	int u,v,c;
	for(int i=1; i<n; i++)
	{
		cin>>u>>v>>c;
		gra[u].pb({v,c});
		gra[v].pb({u,c});
	}
	dfs(1,1,0);
	cout<<ans<<endl;
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
	auto clk=clock();
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	clk=clock()-clk;
	cout<<endl<<endl<< "Time Elapsed: " << ((double)clk)/CLOCKS_PER_SEC <<endl;
#endif
	return 0;
}
ll powm(ll a,ll b, ll m) {
	ll te=1;
	while(b) {
		if(b&1) te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}