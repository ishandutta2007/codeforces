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

int ans;
int a[100001];
inline int dist(pii a,pii b)
{
	return (a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se);
}
void solve(vector<pii> tex,vector<pii>tey)
{
	if(tex.size()<=3)
	{
		for(int i=0; i<tex.size(); i++)
			for(int j=i+1; j<tex.size(); j++)
				ans=min(ans,dist(tex[i],tex[j]));
		return;
	}
	vector<pii> texa,teya;
	vector<pii> texb,teyb;
	int x=tex[tex.size()/2].fi;
	for(int i=0; i<tex.size()/2; i++)
		texa.pb(tex[i]);
	for(int i=tex.size()/2; i<tex.size(); i++)
		texb.pb(tex[i]);
	for(auto te:tey)
		if(te.fi<x)
			teya.pb(te);
		else
			teyb.pb(te);
	solve(texa,teya);
	solve(texb,teyb);
	vector<pii> poin;
	for(auto te:tey)
		if((x-te.fi)*(x-te.fi)<ans)
			poin.pb(te);
	for(int i=0; i<poin.size(); i++)
		for(int j=i+1; j<poin.size()&&((poin[j].se-poin[i].se)*(poin[j].se-poin[i].se)<ans); j++)
			ans=min(ans,dist(poin[i],poin[j]));
}
bool comp(pii a,pii b)
{
	return a.se>b.se;
}
signed main()
{
	IO;
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		a[i]+=a[i-1];
	}
	vector<pii> pointsx,pointsy;
	for(int i=1; i<=n; i++) {
		pointsx.pb({i,a[i]});
		pointsy.pb({i,a[i]});
	}
	sort(all(pointsx));
	sort(all(pointsy),comp);
	ans=1e18;
	solve(pointsx,pointsy);
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