//#define opti
#ifdef opti
#define min(x, y) (y ^ ((x ^ y) & -(x < y)))
#define max(x, y) (x ^ ((x ^ y) & -(x < y)))
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif
#ifndef opti
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#ifndef rd
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
//#define int long long
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(x) x.begin(),x.end()
#define shuffle(a,b) random_shuffle(a,b,rng)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
//const ll mod=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

int a[1048576],p2[1048576];
void solve()
{
	int n,te;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&te);
		a[te]++;
	}
	for(int j=0; j<20; j++)
		for(int i=1000000; i>0; i--)
			if(i&(1<<j)){
				a[i^(1<<j)]+=a[i];
				if(a[i^(1<<j)]>=mod)
					a[i^(1<<j)]-=mod;
			}
	p2[0]=1;
	for(int i=1; i<=1000000; i++)
	{
		p2[i]=(p2[i-1]<<1);
		if(p2[i]>=mod)
			p2[i]-=mod;
	}
	ll ans=0,x;
	for(int i=0; i<1048576; i++)
	{
		x=1;
		for(int j=0; j<20; j++)
			if(i&(1<<j))
				x*=-1;
		ans+=(x*p2[a[i]]);
	}
	cout<<(ans%mod+mod)%mod<<endl;

}
signed main()
{
	IO;
	srand(chrono::steady_clock::now().time_since_epoch().count());
	#ifdef rd
		clock_t clk = clock();
	#endif
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	#ifdef rd
		clk = clock() - clk;
		cout<<endl<<endl<< "Time Elapsed: " << fixed << setprecision(10) << ((double)clk)/CLOCKS_PER_SEC <<endl;
	#endif
	return 0;
}
ll powm(ll a,ll b, ll m)
{
	ll te=1;
	while(b)
	{
		if(b&1)
			te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}