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


vi gra[100005];
int maxi;
int dfs(int fr, int at) {
	pii hol={0,0};
	for(int i:gra[at]) {
		if(i!=fr) {
			int te=dfs(at,i);
			if(hol.fi<te) {
				hol.se=hol.fi;
				hol.fi=te;
			} else if(hol.se<te)
				hol.se=te;
		}
	}
	maxi=max(maxi,hol.fi+hol.se);
	return hol.fi+1;
}
int to;
int dfs2(int fr, int at) {
	if(at==to)
		return 0;
	int hol=infl;
	for(int i:gra[at])
		if(i!=fr)
			hol=min(hol,dfs2(at,i));
	return hol+1;
}
void solve() {
	int n,a,b,da,db;
	cin>>n>>a>>b>>da>>db;
	to=b;
	fr(i,1,n)
		gra[i].clear();
	rep(i,1,n) {
		int u,v;
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	maxi=0;
	dfs(1,1);
	int dista=dfs2(a,a);
	trace(maxi,da,db,dista);
	if(2*da>=db||2*da>=maxi||da>=dista) {
		cout<<"Alice"<<endl;
	} else
		cout<<"Bob"<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}