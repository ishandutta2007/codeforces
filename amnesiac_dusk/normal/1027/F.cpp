/*
 * 	i could never find the right way to tell you
 * 		have you noticed i've been gone?
 * 			cause i left behind the home that you made me
 * 				but i will carry it along
 * 	mm it's a long way forward
 * 		so trust in me
 * 			i'll give them shelter like you've done for me
 * 				and i know i'm not alone
 * 					you'll be watching over us
 * 						until you're gone
 * 	when i'm older i'll be silent beside you
 * 		I know that words are not enough
 * 			and they won't need to know our names or our faces
 * 				but they will carry on for us
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
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
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
const ll infl=1e18;
const int infi=2e9;
const int mod=1e9+7;
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim)
{
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
const int N=2e6+5;
vector<pii> edges;
unordered_map<int,int> ind;
int dsu[N];
int nedges[N];
pii mx[N];
int par(int i) {
	return dsu[i]<0?i:dsu[i]=par(dsu[i]);
}
void merge(int i, int j) {
	if((i=par(i))!=(j=par(j))) {
		if(dsu[i]>dsu[j])
			swap(i,j);
		dsu[i]+=dsu[j];
		nedges[i]+=nedges[j];
		dsu[j]=i;
		if(mx[i].fi<mx[j].fi) {
			if(mx[i].fi<mx[j].se) {
				mx[i]=mx[j];
			} else {
				mx[i].se=mx[i].fi;
				mx[i].fi=mx[j].fi;
			}
		} else {
			if(mx[i].se<mx[j].fi)
				mx[i].se=mx[j].fi;
		}
	}
	nedges[i]++;
}
void solve() {
	int n,a,b;
	cin>>n;
	vi lol;
	for(int i=0; i<n; i++) {
		cin>>a>>b;
		lol.pb(a);
		lol.pb(b);
		edges.pb({a,b});
	}
	sort(all(lol));
	lol.resize(unique(all(lol))-lol.begin());
	fill(dsu,dsu+sz(lol),-1);
	for(int i=0; i<sz(lol); i++) {
		ind[lol[i]]=i;
		mx[i].fi=i;
	}
	for(auto &edge:edges)
		merge(ind[edge.fi],ind[edge.se]);
	int ans=0;
	for(int i=0; i<sz(lol); i++)
		if(dsu[i]<0) {
			trace(mx[i].fi,mx[i].se);
			if(nedges[i]+dsu[i]>0) {
				cout<<-1<<endl;
				return;
			} else if(nedges[i]+dsu[i]==0) {
				ans=max(ans,mx[i].fi);
			} else
				ans=max(ans,mx[i].se);
		}
	cout<<lol[ans]<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
//	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}