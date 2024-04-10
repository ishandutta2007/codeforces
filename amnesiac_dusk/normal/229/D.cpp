/*
* 	When the sun shines, we shine together
* 		Told you I'll be here forever
* 			Said I'll always be your friend
* 				Took an oath that I'm a stick it out till the end
* 	Now that it's raining more than ever
* 		Know that we still have each other
* 			You can stand under my umbrella
* 				You can stand under my umbrella, ella, ella, eh, eh, eh
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

int dp[5001][2];
int a[5001],pref[5001];
void solve()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1]+a[i];
	}
	for(int i=1; i<=n; i++)
		for(int j=0; j<i; j++)
		{
			if(dp[j][1]>=dp[i][1]&&dp[j][0]<=pref[i]-pref[j])
			{
				dp[i][1]=dp[j][1]+1;
				dp[i][0]=pref[i]-pref[j];
			}
			else if(dp[i][1]==dp[j][1]+1&&dp[j][0]<=pref[i]-pref[j])
				dp[i][0]=min(dp[i][0],pref[i]-pref[j]);
		}
	cout<<n-dp[n][1]<<endl;
}
signed main()
{
	IO;
	srand(chrono::steady_clock::now().time_since_epoch().count());
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