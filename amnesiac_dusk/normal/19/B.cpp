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
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define int long long
#define double long double
#define fr(a,b,c) for(int a=b; a<=c; a++)
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);
int a[4001],b[4001];
signed main()
{
	IO;
	for(int i=0; i<=4000; i++)
	{
		a[i]=-1e13;
		b[i]=-1e13;
	}
	a[2000]=0;
	int n;
	cin>>n;
	vector<pii> tola;
	int t,p;
	for(int i=0; i<n; i++)
	{
		cin>>t>>p;
		tola.pb({t,p});
	}
	int sum=0;
	for(int i=0; i<n; i++)
	{
		sum+=tola[i].se;
		for(int j=0; j<=4000; j++)
		{
			b[min(4000LL,j+tola[i].fi)]=max(a[j],b[min(4000LL,j+tola[i].fi)]);
			b[max(0LL,j-1)]=max(b[max(0LL,j-1)],a[j]+tola[i].se);
		}
		for(int j=0; j<=4000; j++)
		{
			a[j]=b[j];
			b[j]=-1e13;
		}
	}
	int ans=0;
	for(int j=2000; j<=4000; j++)
		ans=max(ans,a[j]);
	cout<<sum-ans<<endl;
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