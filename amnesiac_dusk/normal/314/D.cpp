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

vector<pii> pts;
int mays[100002],miys[100002];
int mayu[100002],miyu[100002];
void solve()
{
	int n,x,y;
	cin>>n;
	pts.pb({-inf,-inf});
	for(int i=0; i<n; i++)
		cin>>x>>y,pts.pb({x+y,y-x});
	sort(all(pts));
	miys[0]=inf;
	mays[0]=-inf;
	mayu[n+1]=-inf;
	miyu[n+1]=inf;
	for(int i=1; i<=n; i++) {
		mays[i]=max(mays[i-1],pts[i].se);
		miys[i]=min(miys[i-1],pts[i].se);
	}
	for(int i=n; i>0; i--) {
		mayu[i]=max(mayu[i+1],pts[i].se);
		miyu[i]=min(miyu[i+1],pts[i].se);
	}
	double lo=0,hi=6e9,mid=(lo+hi)/2;
	for(int ii=0; ii<100; ii++)
	{
		bool sat=0;
		for(int i=1,j=1; i<=n; i++)
		{
			while(j!=n&&pts[j+1].fi-pts[i].fi<=2*mid)
				j++;
			if(i==1&&j==n)
				sat=1;
			else if(i==1)
			{
				if(mayu[j+1]-miyu[j+1]<=2*mid)
					sat=1;
			}
			else if(j==n)
			{
				if(mays[i-1]-miys[i-1]<=2*mid)
					sat=1;
			}
			else if(max(mays[i-1],mayu[j+1])-min(miys[i-1],miyu[j+1])<=2*mid)
			{
				sat=1;
				break;
			}
		}
		if(sat)
			hi=mid;
		else
			lo=mid;
		mid=(lo+hi)/2;
	}
	cout<<mid<<endl;
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