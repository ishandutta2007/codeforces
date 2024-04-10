/*
 * Words like "tomorrow" or "future" or "fate"
 *		No matter how far they extend their hands
 *			We breathe, we dream, we raise our love
 *				In a timeless land that is far out of reach
 */
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

int dp[300001];
int w[300001];
int ans[300001];
vector<pii> queries[401];
signed main()
{
	IO;
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>w[i];
	int q,a,b;
	cin>>q;
	for(int i=1; i<=q; i++) {
		cin>>a>>b;
		if(b<=400)
			queries[b].pb({a,i});
		else
		{
			int sol=0;
			for(int i=a; i<=n; i+=b)
				sol+=w[i];
			ans[i]=sol;
		}
	}
	for(int i=1; i<=400; i++)
	{
		if(queries[i].size())
		{
			for(int j=1; j<i; j++)
				dp[j]=w[j];
			for(int j=i; j<=n; j++)
				dp[j]=dp[j-i]+w[j];
			for(auto te:queries[i])
			{
				int lol=te.fi+(((n-te.fi)/i)*i);
				ans[te.se]=dp[lol];
				if(te.fi>i)
					ans[te.se]-=dp[te.fi-i];
			}
		}
	}
	for(int i=1; i<=q; i++)
		cout<<ans[i]<<endl;
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