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

vector<int> gra[500001];
set<int> activefiller;
set<int> deleter[500001];
vector<int> queries[500001];
vector<int> answeroidqueries[500001];
bool answeroid[500001];
int anses[500001];
set<int>* dfs(int fr, int at)
{
	for(int i:queries[at])
		activefiller.insert(i);
	vector<set<int>*> hola;
	hola.push_back(&(deleter[at]));
	for(int i:gra[at])
		if(i!=fr)
			hola.pb(dfs(at,i));
	int mmax=0,mind=0;
	for(int i=0; i<hola.size(); i++)
		if(mmax<hola[i]->size())
		{
			mmax=hola[i]->size();
			mind=i;
		}
	for(int i=0; i<hola.size(); i++)
		if(mind!=i)
			for(int j:(*hola[i]))
				hola[mind]->insert(j);
	for(auto te:answeroidqueries[at])
	{
		if(activefiller.size())
		{
			auto lolol=(activefiller.upper_bound(te));
			if(lolol!=activefiller.begin())
			{
				--lolol;
				if(hola[mind]->size())
				{
					auto holol=(hola[mind]->upper_bound(te));
					if(holol==hola[mind]->begin())
						anses[te]=1;
					else
					{
						--holol;
						if((*lolol)>(*holol))
							anses[te]=1;
					}
				}
				else
					anses[te]=1;
			}
		}
	}
	for(int i:queries[at])
		activefiller.erase(i);
	return hola[mind];
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1; i<n; i++)
	{
		int u,v;
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	int q;
	cin>>q;
	for(int i=1; i<=q; i++)
	{
		int c,v;
		cin>>c>>v;
		if(c==1)
			queries[v].pb(i);
		else if(c==2)
			deleter[v].insert(i);
		else
		{
			answeroidqueries[v].pb(i);
			answeroid[i]=1;
		}
	}
	dfs(1,1);
	for(int i=1; i<=q; i++)
		if(answeroid[i])
			cout<<anses[i]<<endl;
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