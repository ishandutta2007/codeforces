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

vector<int> a[200001];
void solve()
{
	int t,a,b,n,k;
	cin>>t>>n>>a>>b>>k;
	int cla=a*((n+1)/2)+b*(n/2);
	if(n==k)
		cout<<min(min(a,b),t)<<endl;
	else if(n<k)
		cout<<0<<endl;
	else if(min(t,cla/k)>=a&&min(t,cla/k)>=b)
		cout<<min(t,cla/k)<<endl;
	else if(min(t,cla/k)<b){
		k-=n/2;
		cla=a*((n+1)/2);
		cout<<min(t,cla/k)<<endl;
	}
	else
	{
		k-=(n+1)/2;
		cla=b*(n/2);
		cout<<min(t,cla/k);
	}
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	auto clk=clock();
//	cin>>t;
	while(t--)
		solve();
//#ifdef rd
//	clk=clock()-clk;
//	cout<<endl<<endl<< "Time Elapsed: " << ((double)clk)/CLOCKS_PER_SEC <<endl;
//#endif
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