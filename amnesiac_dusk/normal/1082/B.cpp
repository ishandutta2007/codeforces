//#define opti
#ifdef opti
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#else
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
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
#define all(con) con.begin(),con.end()
#define deb cout<<"Line: "<<__LINE__<<" plz "<<endl
typedef long long ll;
const ll inf=1e18;
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);


void solve()
{
	int n;
	string s;
	cin>>n>>s;
	vector<pii> gs,ss;
	int le=0,ty=0;
	for(int i=0; i<n; i++)
	{
		if(s[i]=='G')
		{
			if(ty==0)
				le++;
			else if(le)
			{
				gs.pb({le,1});
				ty=0;
				le=1;
			}
		}
		else
		{
			if(ty==1)
				le++;
			else if(le)
			{
				gs.pb({le,0});
				ty=1;
				le=1;
			}
		}
	}
	if(ty==1)
		if(le)
			gs.pb({le,1});
	if(ty==0)
		if(le)
			gs.pb({le,0});
	int gold=0,silver=0;
	for(int i=0; i<gs.size(); i++)
		if(gs[i].se==0)
			gold++;
		else
			silver++;
	if(gold==0)
		cout<<0<<endl;
	else if(gold==1)
	{
		for(int i=0; i<gs.size(); i++)
			if(gs[i].second==0)
				cout<<gs[i].fi<<endl;
	}
	else if(gold==2)
	{
		int ans=0;
				for(int i=0; i<gs.size(); i++)
					if(gs[i].second==1)
					{
						if(gs[i].fi==1)
						{
							if(i>0&&i+1<((int)gs.size()))
								ans=max(ans,gs[i-1].fi+gs[i+1].fi);
						}
					}
					else
						ans=max(ans,gs[i].fi+1);
		cout<<ans<<endl;
	}
	else
	{
		int ans=0;
		for(int i=0; i<gs.size(); i++)
		{
			if(gs[i].second==1){if(gs[i].fi==1)
			{
				if(i>0&&i+1<((int)gs.size()))
					ans=max(ans,gs[i-1].fi+gs[i+1].fi+1);
			}
			}
			else
				ans=max(ans,gs[i].fi+1);
		}
		cout<<ans<<endl;
	}
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	clock_t clk = clock();
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	clk = clock() - clk;
#ifdef rd
	cout<<endl<<endl<< "Time Elapsed: " << fixed << setprecision(10) << ((double)clk)/CLOCKS_PER_SEC <<endl;
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