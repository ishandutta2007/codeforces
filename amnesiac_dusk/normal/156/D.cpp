/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
*/
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef double f80;
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

vector<int> gra[100001];
int cc=0;
int vis[100001];
void dfs(int at)
{
	cc++;
	vis[at]=1;
	for(int i:gra[at])
		if(!vis[i])
			dfs(i);
}
void solve()
{
	int n,m,k,u,v;
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	int ans=1;
	int com=0;
	for(int i=1; i<=n; i++)
		if(!vis[i])
		{
			com++;
			cc=0;
			dfs(i);
			ans=(ans*cc)%k;
		}
	if(com==1)
		cout<<1%k<<endl;
	else
		cout<<(ans*powm(n,com-2,k))%k<<endl;
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	auto clk=clock();
//	cin>>t;
	while(t--)
		solve();
//#ifdef rd
//	clk=clock()-clk;
//	cout<<endl<<endl<< "Time Elapsed: " << ((double)clk)/CLOCKS_PER_SEC <<endl;
//#endif
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