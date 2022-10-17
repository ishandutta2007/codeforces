#pragma GCC optimze("Ofast")
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

int d[300005];
bool vis[300005];
vector<pii> gra[300005];
vi ans;
int dfs(int fr, int at) {
	int te=0;
	vis[at]=1;
	for(auto i:gra[at]) {
		if(i.fi!=fr&&vis[i.fi]==0) {
			int poo=dfs(at,i.fi);
			if(poo)
				ans.pb(i.se);
			te^=poo;
		}
	}
	if(d[at]==-1) {
		return 0;
	} else
		return te^d[at];
}
void solve() {
	int n,m;
	cin>>n>>m;
	fr(i,1,n)
		cin>>d[i];
	fr(i,1,m) {
		int u,v;
		cin>>u>>v;
		gra[u].pb({v,i});
		gra[v].pb({u,i});
	}
	bool done=0;
	int from=1;
	fr(i,1,n) {
		if(d[i]==-1) {
			from=i;
		}
	}
	if(dfs(from,from)){
		cout<<-1<<endl;
		return;
	}
	cout<<sz(ans)<<endl;
	for(int i:ans)
		cout<<i<<" ";
}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}