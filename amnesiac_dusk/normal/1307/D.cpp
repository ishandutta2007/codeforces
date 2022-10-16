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

int n;
vi gra[200005];
void bfs(vi &dist, int src) {
	queue<int> q;
	dist.resize(n+1,-1);
	q.push(src);
	dist[src]=0;
	while(q.size()) {
		int at=q.front();
		q.pop();
		for(int j:gra[at])
			if(dist[j]==-1) {
				dist[j]=dist[at]+1;
				q.push(j);
			}
	}
}
int troll[200005];
void solve() {
	int m,k;
	cin>>n>>m>>k;
	fr(i,1,k)
		cin>>troll[i];
	fr(i,1,m) {
		int u,v;
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	vi fwd,bac;
	bfs(fwd,1);
	bfs(bac,n);
	int ans=0;
	vector<pair<pii,int>> lolol;
	fr(i,1,k)
		lolol.pb({{fwd[troll[i]],bac[troll[i]]},troll[i]});
	sort(all(lolol));
	for(int i=0; i+1<k; i++) {
		if(ans<lolol[i].fi.fi+lolol[i+1].fi.se+1) {
			ans=lolol[i].fi.fi+lolol[i+1].fi.se+1;
		}
	}
	ans=min(ans,fwd[n]);
	cout<<ans<<endl;
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
}