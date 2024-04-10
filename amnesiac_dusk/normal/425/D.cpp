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

const int N=1e5+1;
unordered_set<int> xx[100001];
vector<int> x[100001],y[100001];
vector<pii> points;
signed main()
{
	IO;
	int n;
	cin>>n;
	int tex,tey;
	for(int i=0; i<n; i++)
	{
		cin>>tex>>tey;
		points.pb({tex,tey});
		xx[tex].insert(tey);
		x[tex].pb(tey);
		y[tey].pb(tex);
	}
	int ans=0;
	for(pii te:points)
		if(y[te.se].size()>x[te.fi].size())
		{	for(int j:x[te.fi])
				if(te.fi+j-te.se>=0&&te.fi+j-te.se<=100000)
					if(xx[te.fi+j-te.se].count(te.se)&&xx[te.fi+j-te.se].count(j))
						ans++;
		}
		else
  			for(int j:y[te.se])
  				if(xx[te.fi].count(te.se-te.fi+j)&&xx[j].count(te.se+j-te.fi))
  					ans++;
	ans-=n;
	ans/=2;
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