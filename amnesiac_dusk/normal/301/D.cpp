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

int a[200001];
vector<pair<pii,int>> queries;
int tr[400001];
int rp[200001];
int anses[200001];
vector<int> delayed[200001];
int nn;
int query(int l, int r)
{
	int sum=0;
	r++;
	for(l+=nn,r+=nn; l<r; l>>=1,r>>=1)
	{
		if(l&1) sum+=tr[l++];
		if(r&1) sum+=tr[--r];
	}
	return sum;
}
void add(int pos)
{
	for(pos+=nn; pos>0; pos>>=1)
		tr[pos]++;
}
signed main()
{
	IO;
	int n,m;
	cin>>n>>m;
	nn=n+1;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=n; i++)
		rp[a[i]]=i;
	for(int i=1,u,v; i<=m; i++) {
		cin>>u>>v;
		queries.pb({{v,u},i});
	}
	sort(all(queries));
	int updated=0;
	for(auto te:queries)
	{
		while(updated<te.fi.fi)
		{
			updated++;
			for(int i:delayed[updated])
				add(i);
			for(int i=a[updated]; i<=n; i+=a[updated])
				if(rp[i]<=updated)
					add(rp[i]);
				else
					delayed[rp[i]].pb(updated);
		}
		anses[te.se]=query(te.fi.se,te.fi.fi);
	}
	for(int i=1; i<=m; i++)
		cout<<anses[i]<<endl;
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