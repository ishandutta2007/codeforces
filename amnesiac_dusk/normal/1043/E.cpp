/*
 * Words like "tomorrow" or "future" or "fate"
 *		No matter how far they extend their hands
 *			We breathe, we dream, we raise our love
 *				In a timeless land that is far out of reach
 */
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

vector<pair<pii,pii>> hola;
int val[300001][2];
int scores[300001];
signed main()
{
	IO;
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		int u,v;
		cin>>u>>v;
		val[i][0]=u;
		val[i][1]=v;
		hola.pb({{v-u,i},{u,v}});
	}
	sort(all(hola));
	int i=0;
	int tola=0;
	for(auto te:hola)
	{
		scores[te.fi.se]+=i*(te.se.fi)+(n-i-1)*(te.se.se)+tola;
		tola+=te.se.se;
		i++;
	}
	tola=0;
	for(int i=n-1; i>=0; i--)
	{
		scores[hola[i].fi.se]+=tola;
		tola+=hola[i].se.fi;
	}
	for(int i=0; i<m; i++)
	{
		int u,v;
		cin>>u>>v;
		scores[u]-=min(val[u][0]+val[v][1],val[u][1]+val[v][0]);
		scores[v]-=min(val[u][0]+val[v][1],val[u][1]+val[v][0]);
	}
	for(int i=1; i<=n; i++)
		cout<<scores[i]<<" ";
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