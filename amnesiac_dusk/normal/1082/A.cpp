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
	int n,x,y,d;
	cin>>n>>x>>y>>d;
	if((y-x)%d==0)
		cout<<(abs(y-x))/d<<endl;
	else
	{
		int st=(x+d-2)/d;
		int min1=inf;
		if((y-1)%d==0)
			min1=(y-1)/d+st;
		int end=(n-x+d-1)/d;
		int min2=inf;
		if((n-y)%d==0)
			min2=end+(n-y)/d;
		int ans=min(min1,min2);
		if(ans!=inf)
			cout<<ans<<endl;
		else
			cout<<-1<<endl;
	}
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	clock_t clk = clock();
	int t=1;
	cin>>t;
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