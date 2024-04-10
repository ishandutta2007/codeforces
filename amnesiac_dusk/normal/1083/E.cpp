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

vector<pair<pii,int>> rects;
int consta[1000001];
bool removed[1000001];
deque<pair<pii,double>> yi;
void solve()
{
	int n;
	cin>>n;
	int x,y,c;
	for(int i=1; i<=n; i++)
	{
		cin>>x>>y>>c;
		rects.pb({{x,y},c});
	}
	sort(all(rects));
	int ans=0;
	yi.pb({{0,0},0});
	//yi first - answer,
	//second - xi value;
	// third - activation enthalpy yi
	for(int i=0; i<n; i++)
	{
		auto lol=yi.front();
		while(lol.second>rects[i].fi.se)
		{
			yi.pop_front();
			lol=yi.front();
		}
//		cout<<lol.fi.fi<<" "<<lol.fi.se<<" "<<lol.se<<endl;
		ans=max(ans,lol.fi.fi-lol.fi.se*rects[i].fi.se+rects[i].fi.se*rects[i].fi.fi-rects[i].se);
		auto pop=yi.back();
		yi.pop_back();
		if(!yi.empty())
		{
		auto top=yi.back();
		while((!yi.empty())&&top.fi.fi-top.fi.se*top.se<ans-rects[i].fi.fi*top.se)
		{
			pop=yi.back();
			yi.pop_back();
			if(!yi.empty())
				top=yi.back();
		}
		}
		double optiheight=(ans-pop.fi.fi)/(rects[i].fi.fi-pop.fi.se+0.0);
		yi.push_back({pop.fi,optiheight});
		yi.push_back({{ans,rects[i].fi.fi},0});
//		cout<<ans<<endl;
	}
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