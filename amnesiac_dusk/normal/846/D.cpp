#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define int long long
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

int a[505][505];
int n,m,k;
bool check() {
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			a[i][j]+=a[i][j-1];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			a[i][j]+=a[i-1][j];
	for(int i=k; i<=n; i++)
		for(int j=k; j<=m; j++)
			if(a[i][j]+a[i-k][j-k]-a[i][j-k]-a[i-k][j]==k*k)
				return 1;
	return 0;
}
void solve() {
	int q;
	cin>>n>>m>>k>>q;
	vector<pair<int,pii>> broke;
	int x,y,t;
	while(q--) {
		cin>>x>>y>>t;
		broke.pb({t,{x,y}});
	}
	sort(all(broke));
	int lo=0,hi=1e9+5,mid=(lo+hi)/2;
	while(lo<hi) {
		for(int i=0; i<=500; i++) {
			fill(a[i],a[i]+501,0);
		}
		for(int i=0; i<sz(broke); i++) {
			if(broke[i].fi>mid)
				break;
			a[broke[i].se.fi][broke[i].se.se]=1;
		}
		if(check())
			hi=mid;
		else
			lo=mid+1;
		mid=(lo+hi)/2;
	}
	if(mid>1e9)
		mid=-1;
	cout<<mid<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
	cout<<fixed<<setprecision(10);
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cerr<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}