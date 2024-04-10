#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	const char *comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef float f80;
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

const int N=1e5+5;
vector<vi> changes;
vector<pii> tr[4*N];
map<pii,
int> active;
int dsu[N],par[N];
void add(int seg, int ll, int rr, int l, int r, pii edge) {
	if(ll>r||l>rr)
		return;
	if(l<=ll&&rr<=r) {
		tr[seg].pb(edge);
		return;
	}
	add(seg<<1,ll,(ll+rr)/2,l,r,edge);
	add(seg<<1|1,1+(ll+rr)/2,rr,l,r,edge);
}
int fpar(int i) {
	return (dsu[i]<0)?i:fpar(dsu[i]);
}
int fp(int i) {
	return (dsu[i]<0)?0:(par[i]^fp(dsu[i]));
}
bool merge(int i, int j) {
	int ori=i,orj=j;
	if((i=fpar(i))!=(j=fpar(j))) {
		if(dsu[i]>dsu[j])
			swap(i,j);
		changes.pb({i,dsu[i],j,dsu[j],par[j]});
		dsu[i]+=dsu[j];
		par[j]=fp(ori)^fp(orj)^1;
		dsu[j]=i;
		return 1;
	} else {
		changes.pb({});
		if(fp(ori)^fp(orj)!=1)
			return 0;
		return 1;
	}
}
void dfs(int seg, int ll, int rr) {
	bool valid=1;
	for(pii te : tr[seg]) {
		valid&=merge(te.fi,te.se);
//		trace(te.fi,te.se);
	}
//	trace(valid,sz(tr[seg]),ll,rr);
//	fr(i,1,3) {
//		cout<<dsu[i]<<" "<<par[i]<<endl;
//	}
	if(valid) {
		if(ll!=rr) {
			dfs(seg<<1,ll,(ll+rr)/2);
			dfs(seg<<1|1,1+(ll+rr)/2,rr);
		} else {
			cout<<"YES"<<endl;
		}
	} else {
		for(int i=ll;i<=rr;i++)
			cout<<"NO"<<endl;
	}
	for(int i=0;i<sz(tr[seg]);i++) {
		if(changes.back().size()) {
			auto &c=changes.back();
			dsu[c[0]]=c[1];
			dsu[c[2]]=c[3];
			par[c[2]]=c[4];
		}
		changes.pop_back();
	}
}
void solve() {
	int n,q;
	memset(dsu,-1,sizeof(dsu));
	cin>>n>>q;
	fr(i,1,q)
	{
		int x,y;
		cin>>x>>y;
		if(x>y)
			swap(x,y);
		auto it=active.find({x,y});
		if(it!=active.end()) {
			add(1,1,q,(*it).se,i-1,{x,y});
			active.erase(it);
		} else
			active[{x,y}]=i;
	}
	for(auto i : active) {
		add(1,1,q,i.se,q,i.fi);
	}
	dfs(1,1,q);
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
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