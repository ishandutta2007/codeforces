/*
 * RD
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll inf=1e18;
const int mod=1000000007;
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> gra[100005];
int dp[17][100005];
pair<pii,pii> mis[200005],mas[200005];
int depth[100005];
int ti=1;
int n,q;
pair<pii,pii> mico(pair<pii,pii> a, pair<pii,pii> b) {
	if(a.fi<b.fi) {
		if(a.se<b.fi) return a;
		else return {a.fi,b.fi};
	}
	else {
		if(a.fi>b.se) return b;
		else return {b.fi,a.fi};
	}
}
pair<pii,pii> maco(pair<pii,pii> a, pair<pii,pii> b) {
	if(a.fi>b.fi) {
		if(a.se>b.fi) return a;
		else return {a.fi,b.fi};
	}
	else {
		if(a.fi<b.se) return b;
		else return {b.fi,a.fi};
	}
}
void dfs(int fr, int at, int deep) {
	mis[n+at-1]={{ti,at},{inf,inf}};
	mas[n+at-1]={{ti,at},{0,0}};
	ti++;
	depth[at]=deep;
	dp[0][at]=fr;
	for(int i:gra[at])
		dfs(at,i,deep+1);
}
int lca(int u, int v)
{
	if(depth[u]<depth[v]) swap(u,v);
	for(int i=16; i>=0; i--) {
		if(depth[dp[i][u]]>=depth[v]) u=dp[i][u];
	}
	if(u==v) return u;
	for(int i=16; i>=0; i--)
		if(dp[i][u]!=dp[i][v])
			u=dp[i][u],v=dp[i][v];
	return dp[0][u];
}
pair<pii,pii> miquery(int l, int r)
{
	pair<pii,pii> res={{inf,inf},{inf,inf}};
	for(l+=n,r+=n; l<r; l>>=1,r>>=1) {
		if(l&1) res=mico(res,mis[l++]);
		if(r&1) res=mico(res,mis[--r]);
	}
	return res;
}
pair<pii,pii> maquery(int l, int r)
{
	pair<pii,pii> res={{0,0},{0,0}};
	for(l+=n,r+=n; l<r; l>>=1,r>>=1) {
		if(l&1) res=maco(res,mas[l++]);
		if(r&1) res=maco(res,mas[--r]);
	}
	return res;
}
void solve() {
	int u,l,r;
	cin>>n>>q;
	for(int i=2; i<=n; i++) {
		cin>>u;
		gra[u].pb(i);
	}
	dfs(1,1,0);
	for(int i=n-1; i>0; i--) {
		mis[i]=mico(mis[i<<1],mis[i<<1|1]);
		mas[i]=maco(mas[i<<1],mas[i<<1|1]);
	}
	for(int i=1; i<17; i++)
		for(int j=1; j<=n; j++)
			dp[i][j]=dp[i-1][dp[i-1][j]];
	while(q--) {
		cin>>l>>r;
		l--;
		auto lo=miquery(l, r),hi=maquery(l, r);
		if(depth[lca(lo.fi.se,hi.se.se)]>depth[lca(lo.se.se,hi.fi.se)])
			cout<<hi.fi.se<<" "<<depth[lca(lo.fi.se,hi.se.se)]<<endl;
		else
			cout<<lo.fi.se<<" "<<depth[lca(lo.se.se,hi.fi.se)]<<endl;
	}
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	auto clk=clock();
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}