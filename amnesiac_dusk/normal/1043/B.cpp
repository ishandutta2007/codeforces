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

int a[1001];
int x[1001];
signed main()
{
	IO;
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	vector<int> ans;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
			x[j-1]=a[j]-a[j-1];
		bool b=1;
		for(int j=i+1; j<=n; j++)
			if(x[(j-1)%i]+a[j-1]!=a[j])
				b=0;
		if(b)
			ans.pb(i);
	}
	cout<<ans.size()<<endl;
	for(int i:ans)
		cout<<i<<" ";
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