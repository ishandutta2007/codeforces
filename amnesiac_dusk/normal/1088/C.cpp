/*
 * 	Yet there's no way to cast away the past we left
 * 		But maybe, someday there's hope for me
 * 			The light you see envelopes me as sunshine brightens up the night
 * 				My heart it melts, the pain once felt had dissolved when you entered my life
 * 					Thoughts in my brain won't be the same, but everyone has got to change
 * 						But even if I leave it all, with you I'll never fall
 * 							Although I know its just you and me
 * 								So high we'll fly now I am finally free.
 */
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

int a[2001];
void solve()
{
	int n;
	cin>>n;
	cout<<n+1<<endl;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=n; i>0; i--)
	{
		int te=((i-a[i])%(n+1)+(n+1))%(n+1)+n+1;
		cout<<1<<" "<<i<<" "<<te<<endl;
		for(int j=1; j<=i; j++)
			a[j]=a[j]+te;
	}
	cout<<2<<" "<<n<<" "<<n+1<<endl;
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