/*
* 	When the sun shines, we shine together
* 		Told you I'll be here forever
* 			Said I'll always be your friend
* 				Took an oath that I'm a stick it out till the end
* 	Now that it's raining more than ever
* 		Know that we still have each other
* 			You can stand under my umbrella
* 				You can stand under my umbrella, ella, ella, eh, eh, eh
*/
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
//#pragma GCC target ("tune=native")
#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#ifndef rd
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(x) x.begin(),x.end()
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);


vector<pii> temp;
int dp[18][100001];
int depth[100001];
int lca(int u,int v)
{
	if(depth[u]<depth[v])
		swap(u,v);
	for(int i=17; i>=0; i--)
		if(depth[dp[i][u]]>=depth[v])
			u=dp[i][u];
	if(u==v)
		return u;
	for(int i=17; i>=0; i--)
		if(dp[i][u]!=dp[i][v])
			u=dp[i][u],v=dp[i][v];
	return dp[0][u];
}
void solve()
{
	int n,x,y;
	cin>>n;
	temp.pb({0,0});
	for(int i=0; i<n; i++)
	{
		cin>>x>>y;
		temp.pb({x,y});
	}
	stack<int> tola;
	tola.push(n);
	dp[0][n]=n;
	for(int i=n-1; i>0; i--)
	{
		int tol=tola.top();
		int slopey=(temp[tol].se-temp[i].se);
		int slopex=(temp[tol].fi-temp[i].fi);
		tola.pop();
		while((!tola.empty())&&slopex*(temp[tola.top()].se-temp[i].se)>slopey*(temp[tola.top()].fi-temp[i].fi))
		{
			tol=tola.top();
			slopey=(temp[tol].se-temp[i].se);
			slopex=(temp[tol].fi-temp[i].fi);
			tola.pop();
		}
		dp[0][i]=tol;
		depth[i]=depth[tol]+1;
		tola.push(tol);
		tola.push(i);
	}
	for(int i=1; i<18; i++)
		for(int j=1; j<=n; j++)
			dp[i][j]=dp[i-1][dp[i-1][j]];
	int m;
	cin>>m;
	for(int i=1; i<=m; i++)
	{
		int u,v;
		cin>>u>>v;
		cout<<lca(u,v)<<" ";
	}
}
signed main()
{
	IO;
	srand(chrono::steady_clock::now().time_since_epoch().count());
	solve();
	return 0;
}
ll powm(ll a,ll b, ll m)
{
	ll te=1;
	while(b)
	{
		if(b&1)
			te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}