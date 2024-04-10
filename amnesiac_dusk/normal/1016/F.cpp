/*
 * 	We're a thousand miles from comfort, we have traveled land and sea
 * 		But as long as you are with me, there's no place I'd rather be
 * 			I would wait forever, exalted in the scene
 * 				As long as I am with you, my heart continues to beat
 *
 * 	If you gave me a chance I would take it
 * 		It's a shot in the dark but I'll make it
 * 			Know with all of your heart, you can't shame me
 * 				When I am with you, there's no place I'd rather be
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
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

const int N=3e5+5;
pii dist[N];
vector<pii> gra[N];
void dfs(int fr, int at, int dista, int z) {
	if(z==0)
		dist[at].fi=dista;
	else
		dist[at].se=dista;
	for(auto &te:gra[at])
		if(te.fi!=fr)
			dfs(at,te.fi,dista+te.se,z);
}
bool removed[N];
void solve() {
	int n,m,u,v,w;
	cin>>n>>m;
	fr(i,1,n-1) {
		cin>>u>>v>>w;
		gra[u].pb({v,w});
		gra[v].pb({u,w});
	}
	dfs(1,1,0,0);
	dfs(n,n,0,1);
	vi temp;
	fr(i,1,n)
		temp.pb(i);
	auto cmp=[](int i, int j)-> bool {
		if(dist[i].fi!=dist[j].fi)
			return dist[i].fi<dist[j].fi;
		return i<j;
	};
	set<int,decltype(cmp)> lol(cmp);
	sort(all(temp),[](int i, int j){
		return dist[i].se<dist[j].se;
	});
	fr(i,1,n) {
		lol.insert(i);
	}
	int ans=0;
	for(int i:temp) {
		lol.erase(i);
		removed[i]=1;
		for(auto &j:gra[i])
			if(!removed[j.fi])
				lol.erase(j.fi);
		if(!lol.empty())
			ans=max(dist[(*(--lol.end()))].fi+dist[i].se,ans);
		for(auto &j:gra[i])
			if(!removed[j.fi])
				lol.insert(j.fi);
	}
	while(m--) {
		int x;
		cin>>x;
		cout<<min(dist[n].fi,ans+x)<<endl;
	}
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}