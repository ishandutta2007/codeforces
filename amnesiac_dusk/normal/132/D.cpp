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

int dp[1000002][3];
string s;
void solve()
{
	cin>>s;
	s="00"+s;
	int n=s.length();
	char lol='0';
	stringstream ou;
	int ans=0;
	for(int i=n-1; i; i--)
		if(s[i]!=lol)
		{
			lol=s[i-1];
			ans++;
			ou<<((lol=='1')?"-":"+")<<"2^"<<n-i-1<<"\n";
		}
	cout<<ans<<endl<<ou.str();

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