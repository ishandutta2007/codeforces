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

int a[300001];
map<int,int> temp;
set<int> tempola;
set<int> lola;
signed main()
{
	IO;
	srand(chrono::steady_clock::now().time_since_epoch().count());
	int n;
	cin>>n;
	int lol;
	for(int i=1; i<=n; i++)
	{
		cin>>lol;
		tempola.insert(lol);
	}
	for(int i:tempola)
		for(int j=2*i; j<=300000; j+=i)
			if(tempola.count(j))
				lola.insert(j);
	for(int i:lola)
		tempola.erase(i);
	int ii=1;
	for(int i:tempola)
		a[ii++]=i;
	n=tempola.size();
	int gc=0;
	for(int i=1; i<=n; i++)
		gc=__gcd(gc,a[i]);
	if(gc!=1)
		cout<<-1<<endl;
	else
	{
		random_shuffle(a+1,a+n+1);
		int ans=7;		temp[0]=0;
		vector<pii> upd;
		vector<int> del;
		for(int i=1; i<=n; i++)
		{
			upd.clear();
			del.clear();
			for(auto j:temp)
			{
				int tol=__gcd(j.fi,a[i]);
				if(((!temp.count(tol))||temp[tol]>j.se+1)&&(j.se+1<ans))
					upd.pb({tol,j.se+1});
				if(tol==1)
					ans=min(ans,j.se+1);
			}
			for(auto j:upd)
				if(temp.count(j.fi))
					temp[j.fi]=min(temp[j.fi],j.se);
				else
					temp[j.fi]=j.se;
			for(auto j:temp)
				if(j.fi!=1&&j.se+1>=ans)
					del.pb(j.fi);
			for(auto j:del)
				temp.erase(j);
		}
		cout<<ans<<endl;
	}
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