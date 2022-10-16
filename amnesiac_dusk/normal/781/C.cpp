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
bool merge(int u, int v) {
	if((u=fpar(u))!=(v=fpar(v))) {
		if(dsu[u]>dsu[v])
			swap(u,v);
		dsu[u]+=dsu[v];
		dsu[v]=u;
		return 1;
	} else
		return 0;
}
vi gra[200005];
vi pol;
void dfs(int fr, int at) {
	pol.pb(at);
	for(int i:gra[at]) {
		if(i!=fr) {
			dfs(at,i);
			pol.pb(at);
		}
	}
}
void solve() {
	memset(dsu,-1,sizeof(dsu));
	int n,m,k;
	cin>>n>>m>>k;
	fr(i,1,m) {
		int u,v;
		cin>>u>>v;
		if(merge(u,v)) {
			gra[u].pb(v);
			gra[v].pb(u);
		}
	}
	dfs(1,1);
	int lol=(2*n+k-1)/k;
	rep(i,0,k) {
		if(sz(pol)) {
			cout<<min(sz(pol),lol);
			for(int j=1; j<=lol&&sz(pol); j++) {
				cout<<" "<<pol.back();
				pol.pop_back();
			}
			cout<<endl;
		} else {
			cout<<"1 1"<<endl;
		}
	}
}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}