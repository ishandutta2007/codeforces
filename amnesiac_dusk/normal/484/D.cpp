/*
 * Words like "tomorrow" or "future" or "fate"
 *		No matter how far they extend their hands
 *			We breathe, we dream, we raise our love
 *				In a timeless land that is far out of reach
 */
//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
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
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

int a[1000001],dp[1000001];
void solve()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	int mini=-a[1],maxi=a[1];
	int ans=0;
	for(int i=2; i<=n; i++)
	{
		dp[i]=max(dp[i-1],max(mini+a[i],maxi-a[i]));
		ans=max(ans,dp[i]);
		mini=max(mini,dp[i-1]-a[i]);
		maxi=max(maxi,dp[i-1]+a[i]);
	}
	cout<<ans<<endl;
}
signed main()
{
	IO;
	srand(chrono::steady_clock::now().time_since_epoch().count());
	// cin >> t;
		solve();
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