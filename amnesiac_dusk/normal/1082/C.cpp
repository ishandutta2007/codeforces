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

vector<int> skill[100001];
vector<int> preskill[100001];
bool cmp(vector<int> &a,vector<int> &b)
{
	if(a.size()==b.size())
		return a<b;
	return a.size()<b.size();
}
void solve()
{
	int n,m;
	cin>>n>>m;
	int s,r;
	for(int i=1; i<=n; i++)
	{
		cin>>s>>r;
		skill[s].pb(r);
	}
	int sz=n;
	for(int j=1; j<=m; j++)
	{
		if(skill[j].size())
		{
			sort(all(skill[j]));
			reverse(all(skill[j]));
			preskill[j].pb(skill[j][0]);
			for(int i=1; i<skill[j].size(); i++)
				preskill[j].pb(preskill[j][i-1]+skill[j][i]);
		}
	}
//	for(int i=1; i<=m; i++)
//		cout<<preskill[i].size()<<endl;
	sort(preskill+1,preskill+m+1,cmp);
	reverse(preskill+1,preskill+m+1);
//	for(int i=1; i<=m; i++)
//		cout<<preskill[i].size()<<endl;
	int ans=0;
	for(int i=1; i<=n; i++)
	{
		int teans=0;
		for(int j=1; j<=m; j++)
		{
			if(preskill[j].size()<i)
				break;
			if(preskill[j][i-1]>0)
				teans+=preskill[j][i-1];
		}
		ans=max(ans,teans);
	}
	cout<<ans<<endl;
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