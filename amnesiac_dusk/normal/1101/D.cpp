/*
 * 	I believe if I knew where I was going I'd lose my way
 * 	I believe that the words that he told you are not your grave
 * 	I know that we are not the weight of all our memories
 * 	I believe in the things that I am afraid to say
 *
 * 	I believe that today it's okay to be not okay
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define double long double
//typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
#define dpr(x) cout<<#x<<": "<<x<<endl
typedef vector<int> vi;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim)
{
	uniform_int_distribution<int> uid(0,lim);
	return uid(rang);
}
int ans=1;
int x[200005];
vector<pii> a[200005];
vi gra[200005];
int smpf[200005];
vi pfs[200005];
void dfs(int fr, int at) {
	a[at].resize(pfs[x[at]].size(),{0,0});
	for(int i:gra[at])
		if(i!=fr) {
			dfs(at,i);
			for(auto j=0; j<pfs[x[i]].size(); j++)
				for(int k=0; k<pfs[x[at]].size(); k++)
					if(pfs[x[i]][j]==pfs[x[at]][k]) {
						if(a[at][k].fi<=a[i][j].fi) {
							a[at][k].se=a[at][k].fi;
							a[at][k].fi=a[i][j].fi;
						} else if(a[at][k].se<a[i][j].fi) {
							a[at][k].se=a[i][j].fi;
						}
					}
		}
	for(auto &i:a[at])
		i.fi++;
}
void solve()
{
	for(int i=1; i<=200000; i++)
		smpf[i]=i;
	for(int i=2; i<=200000; i++) {
		if(smpf[i]==i)
			for(int j=i; j<=200000; j+=i)
			{
				smpf[j]=i;
				pfs[j].pb(i);
			}
	}
	int n,u,v;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>x[i];
	for(int i=1; i<n; i++) {
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	dfs(1,1);
	int ans=0;
	for(int i=1; i<=n; i++)
		for(auto &j:a[i])
			ans=max(j.fi+j.se,ans);
	cout<<ans<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}