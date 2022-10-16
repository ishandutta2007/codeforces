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


int w[3005];
int dsu[3005];
int fpar(int i) {
	return (dsu[i]<0)?i:dsu[i]=fpar(dsu[i]);
}
void merge(int i, int j) {
	if((i=fpar(i))!=(j=fpar(j))) {
		if(dsu[i]>dsu[j])
			swap(i,j);
		dsu[i]+=dsu[j];
		w[i]+=w[j];
		dsu[j]=i;
	}
}

vi gra[3005];
pii dp[3005][3005],dp2[3005][3005];
int sz[3005];
void dfs(int fr, int at) {
	dp[at][0]={0,w[at]};
	int subtr=1;
	sz[at]=1;
	for(int i:gra[at]) {
		if(i==fr)
			continue;
		dfs(at,i);
		for(int j=0; j<sz[at]; j++)
			for(int k=0; k<sz[i]; k++)
				dp2[at][j+k]=max(dp2[at][j+k],{dp[at][j].fi+dp[i][k].fi+(dp[i][k].se>0),dp[at][j].se});
		for(int j=0; j<sz[at]; j++)
			for(int k=0; k<sz[i]; k++)
				dp2[at][j+k+1]=max(dp2[at][j+k+1],{dp[at][j].fi+dp[i][k].fi,dp[at][j].se+dp[i][k].se});
		sz[at]+=sz[i];
		rep(j,0,sz[at]) {
			dp[at][j]=dp2[at][j];
			dp2[at][j]={-infi,-infi};
		}
	}
}
void solve() {
	int n,m;
	cin>>n>>m;
	memset(w,0,sizeof(w));
	memset(dsu,-1,sizeof(dsu));
	memset(sz,0,sizeof(sz));
	fr(i,1,n)
		gra[i].clear();
	fr(i,1,n)
		fr(j,0,n) {
			dp[i][j]={-infi,-infi};
			dp2[i][j]={-infi,-infi};
		}
	fr(i,1,n) {
		int te;
		cin>>te;
		w[i]-=te;
	}
	fr(i,1,n) {
		int te;
		cin>>te;
		w[i]+=te;
	}
	vector<pii> edges;
	rep(i,1,n) {
		int u,v;
		cin>>u>>v;
//		if(w[fpar(u)]<=0&&w[fpar(v)]<=0) {
//			merge(u,v);
//			m++;
//		} else
			edges.pb({u,v});
	}
	for(auto i:edges) {
		gra[fpar(i.fi)].pb(fpar(i.se));
		gra[fpar(i.se)].pb(fpar(i.fi));
	}
	int mergings=n-m;
	int star=1;
	dfs(star,star);
	if(dp[star][mergings].se>0)
		dp[star][mergings].fi++;
	cout<<dp[star][mergings].fi<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t;
	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}