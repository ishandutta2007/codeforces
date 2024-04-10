/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
*/
#pragma GCC optimize("Ofast")
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


int grid[1001][1001];
void solve()
{
	vector<pii> pts;
	int x,y;
	for(int i=0; i<3; i++) {
		cin>>x>>y;
		pts.pb({x,y});
	}
	sort(all(pts));
	for(int i=pts[0].fi; i<=pts[1].fi; i++)
		grid[i][pts[0].se]=1;
	for(int i=pts[2].fi; i>=pts[1].fi; i--)
		grid[i][pts[2].se]=1;
	for(int i=min(pts[0].se,min(pts[1].se,pts[2].se)); i<=max(max(pts[0].se,pts[1].se),pts[2].se); i++)
		grid[pts[1].fi][i]=1;
	int ans=0;
	vector<pii> top;
	for(int i=0; i<=1000; i++)
		for(int j=0; j<=1000; j++)
		{
			if(grid[i][j])
			{
				ans++;
				top.pb({i,j});
			}
		}
	cout<<top.size()<<endl;;
	for(auto tem:top)
		cout<<tem.fi<<" "<<tem.se<<endl;
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