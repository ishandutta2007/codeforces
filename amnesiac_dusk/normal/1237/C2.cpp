#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

void solve() {
	vector<vi> a;
	int n;
	cin>>n;
	map<pii,vector<pii>> snap;
	fr(i,1,n) {
		int x,y,z;
		cin>>x>>y>>z;
		a.pb({x,y,z,i});
	}
	vector<pii> ans;
	for(auto i:a) {
		int x=i[0],y=i[1],z=i[2];
		if(snap.find({x,y})==snap.end())
			snap[{x,y}]=vector<pii>();
		snap[{x,y}].pb({z,i[3]});
	}
	a.clear();
	for(auto &i:snap) {
		sort(all(i.se));
		if(i.se.size()&1) {
			a.pb({i.fi.fi,i.se.back().fi,i.fi.se,i.se.back().se});
			i.se.pop_back();
		}
		for(int j=0; j<sz(i.se); j+=2) {
			ans.pb({i.se[j].se,i.se[j+1].se});
		}
	}
	snap.clear();
	for(auto i:a) {
		int x=i[0],y=i[1],z=i[2];
		if(snap.find({x,y})==snap.end())
			snap[{x,y}]=vector<pii>();
		snap[{x,y}].pb({z,i[3]});
	}
	a.clear();
	for(auto &i:snap) {
		sort(all(i.se));
		if(i.se.size()&1) {
			a.pb({i.fi.se,i.se.back().fi,i.fi.fi,i.se.back().se});
			i.se.pop_back();
		}
		for(int j=0; j<sz(i.se); j+=2) {
			ans.pb({i.se[j].se,i.se[j+1].se});
		}
	}
	snap.clear();
	for(auto i:a) {
		int x=i[0],y=i[1],z=i[2];
		if(snap.find({x,y})==snap.end())
			snap[{x,y}]=vector<pii>();
		snap[{x,y}].pb({z,i[3]});
	}
	a.clear();
	for(auto &i:snap) {
		sort(all(i.se));
		if(i.se.size()&1) {
			a.pb({i.fi.se,i.se.back().fi,i.fi.fi,i.se.back().se});
			i.se.pop_back();
		}
		for(int j=0; j<sz(i.se); j+=2) {
			ans.pb({i.se[j].se,i.se[j+1].se});
		}
	}
	map<int,vector<pair<pii,int>>> fx;
	for(auto i:a) {
		if(fx.find(i[0])==fx.end())
			fx[i[0]]=vector<pair<pii,int>>();
		fx[i[0]].pb({{i[1],i[2]},i[3]});
	}
	a.clear();
	vector<vi> fin;
	for(auto &i:fx) {
		sort(all(i.se));
		if(i.se.size()&1) {
			fin.pb({i.fi,i.se.back().fi.fi,i.se.back().fi.se,i.se.back().se});
			i.se.pop_back();
		}
		for(int j=0; j<sz(i.se); j+=2) {
			ans.pb({i.se[j].se,i.se[j+1].se});
		}
	}
	sort(all(fin));
	for(auto i=0; i<sz(fin); i+=2) {
		ans.pb({fin[i][3],fin[i+1][3]});
	}
	for(auto i:ans)
		cout<<i.fi<<" "<<i.se<<endl;



}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	fr(i, 1, t)
	{
//		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}