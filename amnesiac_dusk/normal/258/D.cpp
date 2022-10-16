// :(
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
#define deb cout<<"Line: "<<__LINE__<<" plz "
typedef long long ll;
const ll inf=1e18;
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

double prob[1001][1001];
int a[1001];
void solve()
{
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(a[i]>a[j])
				prob[i][j]=1;
	while(m--) {
		cin>>u>>v;
		for(int i=1; i<=n; i++)
			if(i!=u&&i!=v)
			{
				prob[u][i]=(prob[u][i]+prob[v][i])/2;
				prob[v][i]=prob[u][i];
				prob[i][u]=1-prob[u][i];
				prob[i][v]=1-prob[v][i];
			}
		prob[u][v]=0.5;
		prob[v][u]=0.5;
	}
	double ans=0;
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			ans+=prob[i][j];
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