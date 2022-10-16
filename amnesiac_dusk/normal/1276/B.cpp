#pragma GCC optimize("Ofast")
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
#define forn(i, x, y) for(int i = x; i <= y; i++)
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
const int mod=998244353;
//const int mod=1000000007;
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


int dsu[200005];
int fpar(int i) {
	return (dsu[i]<0)?i:dsu[i]=fpar(dsu[i]);
}
void merge(int i, int j) {
	if((i=fpar(i))!=(j=fpar(j))) {
		if(dsu[i]>dsu[j])
			swap(i,j);
		dsu[i]+=dsu[j];
		dsu[j]=i;
	}
}
void solve() {
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	memset(dsu,-1,sizeof(int)*(n+5));
	vector<pii> edg;
	fr(i,1,m) {
		int u,v;
		cin>>u>>v;
		edg.pb({u,v});
	}
	for(auto i:edg)
		if(i.fi!=a&&i.se!=a)
			merge(i.fi,i.se);
	int nonb=0;
	fr(i,1,n)
		if(i!=a&&fpar(i)!=fpar(b))
			nonb++;
	memset(dsu,-1,sizeof(int)*(n+5));
	swap(a,b);
	for(auto i:edg)
		if(i.fi!=a&&i.se!=a)
			merge(i.fi,i.se);
	int nona=0;
	fr(i,1,n)
		if(i!=a&&fpar(i)!=fpar(b))
			nona++;
	cout<<nona*nonb<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}