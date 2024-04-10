/*
* 	When the sun shines, we shine together
* 		Told you I'll be here forever
* 			Said I'll always be your friend
* 				Took an oath that I'm a stick it out till the end
* 	Now that it's raining more than ever
* 		Know that we still have each other
* 			You can stand under my umbrella
* 				You can stand under my umbrella, ella, ella, eh, eh, eh
* 	This one: https://www.youtube.com/watch?v=pFOinFPctHs :D
*/
//#pragma GCC optimize("Ofast,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#ifndef rd
//#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(x) x.begin(),x.end()
#define shuffle(a,b) random_shuffle(a,b,rng)
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

vector<int> gra[1001];
set<int> mine,his;
int finde;
bool fol;
void dfs(int fr, int at)
{
	if(mine.count(at))
	{
		finde=at;
		fol=false;
		return;
	}
	for(int i:gra[at])
		if(i!=fr&&fol)
			dfs(at,i);
}
void solve()
{
	int n;
	cin>>n;
	mine.clear();
	his.clear();
	for(int i=1; i<=n; i++)
		gra[i].clear();
	for(int i=1,u,v; i<n; i++)
	{
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	int k1,inp;
	cin>>k1;
	for(int i=0; i<k1; i++)
	{
		cin>>inp;
		mine.insert(inp);
	}
	int k2;
	cin>>k2;
	for(int i=0; i<k2; i++)
	{
		cin>>inp;
		his.insert(inp);
	}
	cout<<"B "<<inp<<endl;
	int mind;
	cin>>mind;
	if(mine.count(mind))
	{
		cout<<"C "<<mind<<endl;
		return;
	}
	fol=true;
	dfs(mind,mind);
	cout<<"A "<<finde<<endl;
	cin>>mind;
	if(his.count(mind))
	{
		cout<<"C "<<finde<<endl;
		return;
	}
	cout<<"C -1"<<endl;
	return;
}
signed main()
{
	IO;
	srand(chrono::steady_clock::now().time_since_epoch().count());
	#ifdef rd
//		clock_t clk = clock();
	#endif
	int t=1;
	cin>>t;
	while(t--)
		solve();
	#ifdef rd
//		clk = clock() - clk;
//		cout<<endl<<endl<< "Time Elapsed: " << fixed << setprecision(10) << ((double)clk)/CLOCKS_PER_SEC <<endl;
	#endif
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