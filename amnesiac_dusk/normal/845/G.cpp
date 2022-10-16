/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 * 	I dont know the meaning of life
 * 		But i know what's truly precious
 * 			The way it's leading me to be in love
 * 				No fear i can find me always in my heart
 * 	The life it's not for comparing things
 * 		So i hold both of light and shadow
 * 			The rays of stars will bring me to you
 * 				Throught the dark night skies
 * 					See the way to be shined
 * 	I dont know what's right for our lives
 * 		But i know the truth of my love
 * 			The way it feels our breaths at the wind
 * 				And the way i should go all my life
 * 					I swear to go wherever will be
 * 						Thus the grace i wouldn't have
 * 							Will always in my heart
 * 								Thus the grace i wouldn't have
 * 									Will always in my heart
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
//#define int long long
typedef long long ll;
#define double long double
//typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

vector<pii> gra[100005];
int n;
vi inde;
int lulol=0;
bool vis[100005];
int ans=0;
void dfs(int at, int here) {
	vis[at]=1;
	if(at==n) {
		ans=here;
		return;
	}
	for(auto i:gra[at])
		if(!vis[i.fi])
			dfs(i.fi,here^i.se);
}
int timestamp[100005];
bool already(int i) {
	trace(i);
	i^=(1<<28)-1;
	for(int ii:inde)
	{
		trace(ii);
		if((i^ii)>i)
			i^=ii;
	}
	return (i==((1<<28)-1));
}
void add(int ii) {
	inde.pb(ii);
	trace(ii);
	vi ne;
	for(int i=27; i>=0; i--) {
		for(int j=0; j<sz(inde); j++) {
			if(inde[j]&(1<<i)) {
				int tem=inde[j];
				ne.pb(inde[j]);
				for(int k=0; k<sz(inde); k++) {
					if(inde[k]&(1<<i))
						inde[k]^=tem;
				}
				break;
			}
		}
	}
	ne.swap(inde);
}
void dfs2(int at, int here) {
	timestamp[at]=here;
	for(auto i:gra[at]) {
		if(timestamp[i.fi]==-1) {
			dfs2(i.fi,here^i.se);
		} else if(!already(here^i.se^timestamp[i.fi])) {
			add(here^i.se^timestamp[i.fi]);
			dfs2(i.fi,here^i.se);
		}
	}
}
void solve() {
	int m;
	cin>>n>>m;
	fr(i,1,m) {
		int u,v,w;
		cin>>u>>v>>w;
		gra[u].pb({v,w});
		gra[v].pb({u,w});
	}
	fill(timestamp+1,timestamp+n+1,-1);
	dfs(1,0);
	dfs2(1,0);
//	fr(i,1,n)
	int i=ans^((1<<28)-1);
	for(int ii:inde) {
		trace(ii);
		if((i^ii)>i)
			i^=ii;
	}
	cout<<(i^((1<<28)-1));
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cerr<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}