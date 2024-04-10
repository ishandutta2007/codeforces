//#define opti
#ifdef opti
//#pragma GCC optimize("Ofast,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#else
#pragma GCC optimize("O3,unroll-loops")
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
const ll inf=5e9;
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);
//int ii=1;
//#define cout tem
//stringstream tem;
void solve()
{
	int n;
	cin>>n;
	int nn=n;
	vector<int> pfs;
	bool prime=1;
	for(int i=2; i*i<=n; i++)
		if(n%i==0)
			prime=0;
	if(prime)
	{
		cout<<"NO"<<endl;
		return;
	}
	for(int i=2; i*i<=n; i++)
		if(n%i==0)
		{
			pfs.pb(i);
			while(n%i==0)
				n/=i;
		}
	if(n!=1)
		pfs.pb(n);
	if(pfs.size()<=1)
		cout<<"NO"<<endl;
	else
	{
		int a=pfs[1],b=pfs[0];
		assert(__gcd(a,b)==1);
		int y=((nn-1)*powm(b,a-2,a))%a;
		int x=(nn-1-b*y)/a;
		int c=nn/(a*b);
		cout<<"YES\n2\n";
		int gcd1=__gcd(x,b*c),gcd2=__gcd(y,a*c);
		cout<<x/gcd1<<" "<<(b*c)/gcd1<<endl;
		cout<<y/gcd2<<" "<<(a*c)/gcd2<<endl;
	}
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
//	int t=1;
//	cin>>t;
//	ii=1e9-1e4;
//	for(;ii<1e9; ii++)
//	{
//		clock_t clk = clock();
		solve();
//		clk = clock() - clk;
//		if(((double)clk)/CLOCKS_PER_SEC>1)
//		{
//			printf("%lld\n",ii);
//		}
//	}
//#ifdef rd
//	cout<<endl<<endl<< "Time Elapsed: " << fixed << setprecision(10) <<  <<endl;
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