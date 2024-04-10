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
//typedef double f80;
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
#ifdef rd
#define deb cout<<"Line: "<<__LINE__<<" plz "
#endif
typedef long long ll;
const ll inf=1e18;
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

int par[100001];
bool vis[100001];
vector<int> gra[100001];
int tesize[100001],totsize[100001];
vector<pair<pii,pii>> edges;
int root(int i)
{
	return par[i]<0?i:par[i]=root(par[i]);
}
void merge(int i, int j)
{
	if((i=root(i))!=(j=root(j)))
	{
		if(par[i]<par[j])
			swap(i,j);
		par[j]+=par[i];
		par[i]=j;
	}
}
int dfs(int fr, int at)
{
	vis[at]=1;
	tesize[at]=-par[at];
	for(int i:gra[at])
		if(i!=fr)
			tesize[at]+=dfs(at,i);
	return tesize[at];
}
void assign(int fr, int at, int val)
{
	totsize[at]=val;
	for(int i:gra[at])
		if(i!=fr)
			assign(at,i,val);
}
int anses[100001];
void solve()
{
	int n,u,v,w;
	cin>>n;
	for(int i=1; i<n; i++) {
		cin>>u>>v>>w;
		edges.pb({{w,i},{u,v}});
	}
	sort(all(edges));
	for(int i=1; i<=n; i++)
		par[i]=-1;
	for(int i=0; i<n-1; )
	{
		int j=i;
		while(j!=n-1&&edges[j].first.first==edges[i].first.first)
			j++;
		for(int k=i; k<j; k++) {
			edges[k].se.fi=root(edges[k].se.fi);
			edges[k].se.se=root(edges[k].se.se);
			gra[edges[k].se.fi].clear();
			gra[edges[k].se.se].clear();
			vis[edges[k].se.fi]=0;
			vis[edges[k].se.se]=0;
		}
		for(int k=i; k<j; k++) {
			gra[edges[k].se.fi].pb(edges[k].se.se);
			gra[edges[k].se.se].pb(edges[k].se.fi);
		}
		for(int k=i; k<j; k++)
			if(!vis[edges[k].se.fi])
				assign(edges[k].se.fi,edges[k].se.fi,dfs(edges[k].se.fi,edges[k].se.fi));
		for(int k=i; k<j; k++)
		{
			int lul=min(tesize[edges[k].se.fi],tesize[edges[k].se.se]);
			anses[edges[k].fi.se]=(totsize[edges[k].se.fi]-lul)*lul;
		}
		for(int k=i; k<j; k++)
			merge(edges[k].se.fi,edges[k].se.se);
		i=j;
	}
	int maxi=0;
	for(int i=1; i<n; i++)
		maxi=max(maxi,anses[i]);
	stringstream top;
	int an=0;
	for(int i=1; i<n; i++)
		if(maxi==anses[i])
		{
			an++;
			top<<i<<" ";
		}
	cout<<maxi*2<<" "<<an<<endl;
	cout<<top.str();
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
	auto clk=clock();
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<< "Time Elapsed: " << ((double)(clock()-clk))/CLOCKS_PER_SEC <<endl;
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