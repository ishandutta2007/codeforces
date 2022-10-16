/*
 * RD
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
//#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
//#define int long long
typedef double f80;
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
typedef long long ll;
const ll inf=1e18;
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);


int dp[100001][18],depth[100000];
vector<int> gra[100001];
vector<int> ord,anti;
void dfs(int fr, int at,int lol)
{
	ord.pb(at);
	dp[at][0]=fr;
	depth[at]=lol;
	for(int i:gra[at])
		if(i!=fr)
			dfs(at,i,lol+1);
}
int lca(int u, int v)
{
	int leva=depth[u]-depth[v];
	if(leva<0)
	{
		leva*=-1;
		swap(u,v);
	}
	for(int i=0; i<18; i++)
		if(leva&(1<<i))
			u=dp[u][i];
	if(u==v)
		return u;
	for(int i=17; i>=0; i--)
		if(dp[u][i]!=dp[v][i])
			u=dp[u][i],v=dp[v][i];
	return dp[u][0];
}
int dist(int u, int v)
{
	return depth[u]+depth[v]-2*depth[lca(u,v)];
}
set<int> active;
int temp(int a)
{
	if(active.size()==0)
		return 1;
	if(active.size()==1)
		return dist(ord[*active.begin()],a);
	auto te=active.lower_bound(anti[a]);
	if(te!=active.begin()&&te!=active.end())
	{
		int u=ord[*te];te--;int v=ord[*te];
//		deb<<u<<" "<<v<<endl;
		return min(dist(lca(u,a),a),dist(lca(v,a),a));
	}
	else
	{
		int mi=lca(ord[*active.begin()],ord[*active.rbegin()]);
		int mi2=lca(mi,a);
//		deb<<mi<<" "<<mi2<<endl;
		if(mi2==mi)
		{
			if(te==active.end())
			{
//				deb<<lca(ord[*(--te)],a)<<endl;
				return dist(a,lca(ord[*(--te)],a));
			}
			else
				return dist(a,lca(ord[*te],a));
		}
		else
			return dist(mi,a);
	}
}
void solve()
{
	int n,k,u,v;
	cin>>n>>k;
	ord.pb(0);
	for(int i=1; i<n; i++) {
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
//	deb<<endl;
	dfs(1,1,0);
//	deb<<endl;
	anti.resize(n+1);
	for(int i=1; i<=n; i++)
		anti[ord[i]]=i;
	for(int i=1; i<18; i++)
		for(int j=1; j<=n; j++)
			dp[j][i]=dp[dp[j][i-1]][i-1];
	int val=0;
	int ans=0;
	for(int i=1,j=1; i<=n&&j<=n;)
	{
		while(val<=k&&j<=n) {
			val+=temp(j);
			active.insert(anti[j]);
			j++;
			if(val<=k)
				ans=max(j-i,ans);
//			deb<<"val "<<val<<endl;
		}
		while(val>k) {
			active.erase(anti[i]);
			val-=temp(i);
			i++;
//			deb<<"val "<<val<<endl;
		}
	}
	cout<<ans<<endl;
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