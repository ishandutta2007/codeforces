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
#define holadeb cout<<"Line: "<<__LINE__<<" "<<pls<<" "
typedef long long ll;
const ll mod=1000000007;
//const ll mod=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

int a[100001];
void solve()
{
	int s,v1,v2,t1,t2;
	cin>>s>>v1>>v2>>t1>>t2;
	int s1=2*t1+s*v1;
	int s2=2*t2+s*v2;
	if(s1<s2)
		cout<<"First";
	else if(s1>s2)
		cout<<"Second";
	else
		cout<<"Friendship";


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