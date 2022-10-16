#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
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
//#define int long long
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
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(int a, int b, int mod) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

#define rsz(x, n) x.resize(n)
#define clr(x) x.clear()
class SCC {
public:
	int n,cnt; // cnt -> number of scc's formed
	vector<vector<int>> g,rg,sg; // sg -> dag with all nodes compressed.
	vector<int> scc,order;
	vector<bool> vis;
	void reset() {
		clr(g),clr(rg),clr(sg),clr(scc),clr(order),clr(vis);
	}
	void init(int _n) {
		reset();
		n=_n,cnt=0;
		_n+=2;
		rsz(g, _n),rsz(rg,_n),rsz(sg,_n);
		scc.resize(_n,0);
		vis.resize(_n,0);
	}
	void add(int u, int v) {
		g[u].push_back(v);
		rg[v].push_back(u);
	}
	void compute() {
		fr(i, 1, n)
			if(!vis[i])
				dfs1(i);
		fill(all(vis),0);
		for(int i=n-1; i>=0; i--)
			if(!vis[order[i]])
				dfs2(order[i],++cnt);
	}
	void dfs1(int u) {
		vis[u]=1;
		for(int v : g[u])
			if(!vis[v])
				dfs1(v);
		order.pb(u);
	}
	void dfs2(int u, int c) {
		vis[u]=1;
		scc[u]=c;
//		comp[c].pb(u);
		for(int v : rg[u]) {
			if(!vis[v])
				dfs2(v,c);
			if(vis[v]&&c!=scc[v])
				sg[scc[v]].pb(c);
		}
	}
};

int inc[1000005];
int num[1000005];
void solve() {
	int n,m;
	cin>>n>>m;
	SCC G;
	{
		vector<vi> a(n+1,vi(m+1));
		fr(i,1,n) {
			a[i].resize(m+1);
			fr(j,1,m)
				cin>>a[i][j];
		}
		G.init(n*m);
		fr(i,1,n) {
			vector<pii> lol;
			fr(j,1,m)
				lol.pb({a[i][j],j});
			sort(all(lol));
			for(int j=0; j+1<sz(lol); j++)
				G.add((i-1)*m+lol[j].se,(i-1)*m+lol[j+1].se);
			for(int j=0; j+1<sz(lol); j++) {
				int k=j;
				while(k+1<sz(lol)&&lol[j].fi==lol[k+1].fi)
					k++;
				if(k!=j)
					G.add((i-1)*m+lol[k].se,(i-1)*m+lol[j].se);
				j=k;
			}
		}
		fr(j,1,m) {
			vector<pii> lol;
			fr(i,1,n)
				lol.pb({a[i][j],(i-1)*m});
			sort(all(lol));
			for(int i=0; i+1<sz(lol); i++)
				G.add(j+lol[i].se,j+lol[i+1].se);
			for(int i=0; i+1<sz(lol); i++) {
				int k=i;
				while(k+1<sz(lol)&&lol[i].fi==lol[k+1].fi)
					k++;
				if(k!=i)
					G.add(j+lol[k].se,j+lol[i].se);
				i=k;
			}
		}
	}
	G.compute();
	fr(i,1,G.cnt) {
		num[i]=1;
		for(int j:G.sg[i])
			inc[j]++;
	}
	queue<int> pol;
	fr(i,1,G.cnt)
		if(inc[i]==0)
			pol.push(i);
	while(!pol.empty()) {
		int at=pol.front();
		pol.pop();
		for(int j:G.sg[at]) {
			inc[j]--;
			if(inc[j]==0)
				pol.push(j);
			num[j]=max(num[j],num[at]+1);
		}
	}
	fr(i,1,n) {
		fr(j,1,m)
			cout<<num[G.scc[(i-1)*m+j]]<<" ";
		cout<<endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(20);
	int t=1;
//	cin>>t;
	fr(i,1,t)
	{
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}