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
#define shuffle(a,b) random_shuffle(a,b,rng)
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

priority_queue<int,std::vector<int>, std::greater<int>> xa;
priority_queue<int,std::vector<int>, std::greater<int>> xb;
map<int,vector<pii>>tola;
void solve()
{
	int n,m;
	cin>>n>>m;
	int tel;
	for(int i=1; i<=n; i++) {
		cin>>tel;
		xa.push(tel);
	}
	xa.push(1e9+5);
	int x1,x2,y;
	for(int i=1; i<=m; i++) {
		cin>>x1>>x2>>y;
		if(!tola.count(y))
			tola[y]=vector<pii>();
		tola[y].pb({x1,x2});
	}
	int conans=0;
	for(auto te:tola)
	{
		sort(all(te.second));
		te.se.pb({(int)1e9+5,(int)1e9+6});
		if(te.se[0].fi!=1)
			continue;
		for(int j=0; 1+j<te.second.size(); j++)
			if(te.second[j].se!=te.second[j+1].fi)
			{
				if(te.second[j].se!=1e9)
				xb.push(te.second[j].se);
				else
				conans++;
				break;
			}
	}
	int ans=xb.size();
	int te=0;
	while(!xb.empty())
	{
		if(xb.top()<xa.top())
			xb.pop();
		else
		{
			xa.pop();
			te++;
		}
		ans=min(ans,((int)xb.size())+te);
	}
	cout<<ans+conans<<endl;
}
signed main()
{
	IO;
	srand(chrono::steady_clock::now().time_since_epoch().count());
	#ifdef rd
//		clock_t clk = clock();
	#endif
	int t=1;
//	cin>>t;
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