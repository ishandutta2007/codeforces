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

const int mod=998244353;
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

int dist[100005];
vector<pii> gra[100005];
int ff[100005];
int lo[300005],
hi[300005],mid[300005],ans[300005];
pii ab[300005];
int dsu[300005];
int fpar(int i) {
	return (dsu[i]<0)?i:dsu[i]=fpar(dsu[i]);
}
void merge(int u, int v) {
	if((u=fpar(u))!=(v=fpar(v))) {
		if(dsu[u]>dsu[v])
			swap(u,v);
		dsu[u]+=dsu[v];
		dsu[v]=u;
	}
}
vector<int> check[600005];
void solve() {
	int n,m,k,q;
	cin>>n>>m>>k>>q;
	memset(dist,0x3f,sizeof(dist));
	fr(i,1,m)
	{
		int u,v,w;
		cin>>u>>v>>w;
		gra[u].pb({v,w});
		gra[v].pb({u,w});
	}
	priority_queue<pii, vector<pii>, greater<pii>> qu;
	fr(i,1,k) {
		qu.push({0,i});
		ff[i]=i;
		dist[i]=0;
	}
	vector<pair<int,pii>> edges;
	while(qu.size()) {
		pii at=qu.top();
		qu.pop();
		if(dist[at.se]!=at.fi)
			continue;
		for(auto i : gra[at.se])
			if(dist[i.fi]>at.fi+i.se) {
				dist[i.fi]=at.fi+i.se;
				qu.push({dist[i.fi],i.fi});
				ff[i.fi]=ff[at.se];
			}
	}
	fr(i,1,n)
		for(auto j : gra[i])
			if(ff[j.fi]!=ff[i])
				edges.pb({dist[j.fi]+j.se+dist[i],{ff[j.fi],ff[i]}});
	sort(all(edges));
	fr(i,1,q) {
		lo[i]=1;
		hi[i]=sz(edges);
		cin>>ab[i].fi>>ab[i].se;
	}
	rep(ii,0,21) {
		memset(dsu,-1,sizeof(dsu));
		fr(i,0,sz(edges))
			check[i].clear();
		fr(i,1,q) {
			mid[i]=(lo[i]+hi[i])/2;
			check[mid[i]].pb(i);
		}
		rep(i,0,sz(edges)) {
			merge(edges[i].se.fi,edges[i].se.se);
			for(int j:check[i])
				if(fpar(ab[j].fi)==fpar(ab[j].se)) {
					hi[j]=mid[j];
					ans[j]=edges[i].fi;
				} else
					lo[j]=mid[j]+1;
		}
	}
	fr(i,1,q) {
		cout<<ans[i]<<endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}