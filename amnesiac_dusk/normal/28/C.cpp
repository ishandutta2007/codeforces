/*
 * Words like "tomorrow" or "future" or "fate"
 *		No matter how far they extend their hands
 *			We breathe, we dream, we raise our love
 *				In a timeless land that is far out of reach
 */
#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#ifndef rd
//#define endl '\n'
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

vector<double> mul(vector<double> &a, vector<double> &b, int sizes)
{
	vector<double> c(a.size()+sizes-1,0);
	for(int i=0; i<a.size(); i++)
		for(int j=0; j<sizes; j++)
			c[i+j]+=a[i]*b[j];
	return c;
}
int a[60];
signed main()
{
	IO;
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=m; i++)
		cin>>a[i];
	vector<double> hola;
	hola.pb(0);
	double fact[61];
	fact[0]=1;
	vector<double> te;
	te.pb(1);
	for(int i=1; i<=60; i++)
	{
		fact[i]=fact[i-1]/i;
		te.pb(fact[i]);
	}
	for(int i=1; i<=n+1; i++)
	{
		vector<double> res;
		res.pb(1);
		for(int j=1; j<=m; j++)
		{
			int sz=1;
			for(int l=1; l<=i*a[j]; l++)
				sz++;
			sz=min(sz,(int)te.size());
			res=mul(res,te,sz);
			res.resize(n+1);
		}
		hola.pb(res[n]);
	}
	for(int i=1; i<=n+1; i++)
		hola[i]/=hola[n+1];
	double ans=0;
	for(int i=n+1; i>0; i--)
		hola[i]-=hola[i-1];
	for(int i=1; i<=n; i++)
		ans+=(hola[i]*i);
	cout<<fixed<<setprecision(12);
	cout<<ans<<endl;
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