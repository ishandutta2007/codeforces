/*
 * Words like "tomorrow" or "future" or "fate"
 *		No matter how far they extend their hands
 *			We breathe, we dream, we raise our love
 *				In a timeless land that is far out of reach
 */
#pragma GCC optimize("Ofast")
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
const ll mod=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

bool cmp(pair<int,pii> &a,pair<int,pii> &b)
{
	return a.fi>b.fi;
}
int a[1001][1001],tol[1001][1001];
bool lol[1001][1001];
vector<pair<int,pii>> hol;
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) {
			cin>>a[i][j];
			hol.pb({a[i][j],{i,j}});
		}
	sort(all(hol),cmp);
	for(auto te:hol)
	{
		lol[te.se.fi][te.se.se]=1;
		for(int i=1; i<=n; i++)
			if(i!=te.se.fi)
				if(lol[i][te.se.se])
				{
					tol[i][te.se.fi]++;
					tol[te.se.fi][i]++;
					if(tol[i][te.se.fi]==2)
					{
						cout<<te.fi<<endl;
						return;
					}
				}
	}
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