#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
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
//#define int long long
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
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

vi gra[200005];
pii fart(int fr, int at) {
	pii ol={0,at};
	for(int i:gra[at]) {
		if(i!=fr) {
			ol=max(ol,fart(at,i));
		}
	}
	ol.fi++;
	return ol;
}
pii one,two;
int essential[200005];
int depth[200005];
int color[200005];
int color2[200005];
pii thetwo[200005];
int n,k;
queue<int> done;
pii dfs(int fr, int at, int depth) {
	if(at==two.se) {
		color[at]=depth%k+1;
		thetwo[at].fi=depth;
		return {1,0};
	}
	for(int i:gra[at]) {
		if(i!=fr) {
			pii lol=dfs(at,i,depth+1);
			if(lol.fi==1) {
				color[at]=depth%k+1;
				done.push(at);
				thetwo[at].fi=depth;
				thetwo[at].se=lol.se;
				return {lol.fi,lol.se+1};
			}
		}
	}
	return {0,0};
}
bool coldfs(int fr, int at, int depth) {
	bool toc=0;
	if(depth>=k) {
		toc=1;
	}
	for(int i:gra[at])
		if(i!=fr)
			toc|=coldfs(at,i,depth+1);
	if(toc) {
		color[at]=depth%k+1;
	}
	return toc;
}
bool coldfs2(int fr, int at, int acdepth,int depth) {
	bool toc=0;
	if(acdepth>=k) {
		toc=1;
	}
	for(int i:gra[at])
		if(i!=fr)
			toc|=coldfs2(at,i,acdepth+1,(depth+k-2)%k+1);
	if(toc)
		color2[at]=depth;
	return toc;
}

void solve() {
	cin>>n>>k;
	fr(i,2,n) {
		int u,v;
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	one=fart(1,1);
	two=fart(one.se,one.se);
	coldfs(one.se,one.se,1);
	coldfs2(two.se,two.se,1,color[two.se]);
	fr(i,1,n) {
		if(color[i]!=0&&color2[i]!=0&&color[i]!=color2[i]) {
			cout<<"No"<<endl;
			return;
		}
	}
	cout<<"Yes"<<endl;
	fr(i,1,n) {
		if(color[i]!=0)
			cout<<color[i]<<" ";
		else if(color2[i]!=0)
			cout<<color2[i]<<" ";
		else
			cout<<1<<" ";
	}
}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}