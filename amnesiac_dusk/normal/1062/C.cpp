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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
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
#define all(x) x.begin(),x.end()
#define shuffle(a,b) random_shuffle(a,b,rng)
typedef long long ll;
const ll mod=1000000007;
//const ll mod=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

int a[400000];
int n;
int query(int l, int r)
{
	int res=0;
	for(l+=n,r+=n; l<r; l>>=1,r>>=1)
	{
		if(l&1) res+=a[l++];
		if(r&1) res+=a[--r];
	}
	return res;
}
int po[200001];
void solve()
{
	int q;
	cin>>n>>q;
	string s;
	cin>>s;
	for(int i=0; i<n; i++)
		a[n+i]=s[i]-'0';
	for(int i=n-1; i>0; i--)
		a[i]=a[i<<1]+a[i<<1|1];
	po[0]=1;
	for(int i=1; i<=100050; i++)
	{
		po[i]=po[i-1]<<1;
		if(po[i]>=mod)
			po[i]-=mod;
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		l--;
		int te=query(l,r);
		if(te==0)
			cout<<0<<endl;
		else
			cout<<((po[te]-1)*(po[r-l-te]))%mod<<endl;
	}
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