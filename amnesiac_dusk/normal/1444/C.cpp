#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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

int c[500005];
int waste[500005];
int dsu[500005];
int par[500005];
int bip;
vector<vector<pair<int&,int>>> change;
int fpar(int u) {
	if(dsu[u]<0) {
		return u;
	}
	int ppar=dsu[u];
	change.back().pb({dsu[u],dsu[u]});
	dsu[u]=fpar(dsu[u]);
	change.back().pb({par[u],par[u]});
	par[u]=par[ppar]^par[u];
	return dsu[u];
}
bool merge(int u, int v) {
	change.pb(vector<pair<int&,int>>());
	int uu=u,vv=v;
	trace(u,v);
	if((u=fpar(u))!=(v=fpar(v))) {
		trace(u,v);
		if(dsu[u]>dsu[v])
			swap(u,v);
		change.back().pb({dsu[u],dsu[u]});
		dsu[u]+=dsu[v];
		change.back().pb({dsu[v],dsu[v]});
		dsu[v]=u;
		change.back().pb({par[v],par[v]});
		par[v]=par[vv]^par[uu]^1;
	} else {
		if(par[uu]^par[vv]^1) {
			change.back().pb({bip,bip});
			bip=1;
			return 0;
		}
	}
	return 1;
}
void rollback() {
	for(auto &i:change.back())
		i.fi=i.se;
	change.pop_back();
}
vector<pii> inside[500005];
map<pii,vector<pii>> outer;
void solve() {
	memset(dsu,-1,sizeof(dsu));
	int n,m,k;
	cin>>n>>m>>k;
	fr(i,1,n)
		cin>>c[i];
	fr(i,1,m) {
		int u,v;
		cin>>u>>v;
		if(c[u]==c[v]) {
			inside[c[u]].pb({u,v});
		} else {
			if(c[u]>c[v])
				swap(u,v);
			outer[{c[u],c[v]}].pb({u,v});
		}
	}
	int tot=k;
	fr(i,1,k) {
		int bbs=0;
		for(auto j:inside[i]) {
			bbs++;
			if(!merge(j.fi,j.se)) {
				waste[i]=1;
				tot--;
				while(bbs>0) {
					bbs--;
					rollback();
				}
				break;
			}
		}
		change.clear();
	}
	int answer=(tot*(tot-1))/2;
	for(auto &j:outer) {
		if(waste[j.fi.fi]==0&&waste[j.fi.se]==0) {
			for(auto &k:outer[j.fi]) {
				if(!merge(k.fi,k.se)) {
					answer--;
					break;
				}
			}
			while(sz(change))
				rollback();
		}
	}
	cout<<answer<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(2);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}