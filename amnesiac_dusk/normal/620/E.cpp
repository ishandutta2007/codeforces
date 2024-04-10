/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 * 	I don't know the meaning of life
 * 		But i know what's truly precious
 * 			The way it's leading me to be in love
 * 				No fear i can find me always in my heart
 * 	The life it's not for comparing things
 * 		So i hold both of light and shadow
 * 			The rays of stars will bring me to you
 * 				Throught the dark night skies
 * 					See the way to be shined
 * 	I dont know what's right for our lives
 * 		But i know the truth of my love
 * 			The way it feels our breaths at the wind
 * 				And the way i should go all my life
 * 					I swear to go wherever will be
 * 						Thus the grace i wouldn't have
 * 							Will always in my heart
 * 								Thus the grace i wouldn't have
 * 									Will always in my heart
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define double long double
//typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
const double M_PI=acos(-1);
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

const int N=4e5+5;
vi gra[N];
int tr[4*N],c[N],lazy[4*N];
int tin[N],tout[N];
int cnt=1;
void dfs(int fr, int at) {
	tin[at]=cnt;
	cnt++;
	for(int i:gra[at])
		if(i!=fr)
			dfs(at,i);
	tout[at]=cnt;
}
void pushdown(int node) {
	if(lazy[node]) {
		tr[node*2]=lazy[node];
		tr[node*2+1]=lazy[node];
		lazy[node*2]=lazy[node];
		lazy[node*2+1]=lazy[node];
		lazy[node]=0;
	}
}
void assign(int node, int l, int r, int ll, int rr, int val) {
	if(l>rr||ll>r)
		return;
	if(l<=ll&&rr<=r) {
		tr[node]=val;
		lazy[node]=val;
		return;
	}
	pushdown(node);
	assign(2*node,l,r,ll,(ll+rr)/2,val);
	assign(2*node+1,l,r,1+(ll+rr)/2,rr,val);
	tr[node]=tr[2*node]|tr[2*node+1];
}
int query(int node, int l, int r, int ll, int rr) {
	if(l>rr||ll>r)
		return 0;
	if(l<=ll&&rr<=r)
		return tr[node];
	pushdown(node);
	return query(node*2,l,r,ll,(ll+rr)/2)|query(node*2+1,l,r,(ll+rr)/2+1,rr);
}
void solve() {
	int n,m,u,v;
	cin>>n>>m;
	fr(i,1,n)
		cin>>c[i];
	for(int i=1; i<n; i++) {
		cin>>u>>v;
		gra[u].pb(v);
		gra[v].pb(u);
	}
	dfs(1,1);
	fr(i,1,n) {
		assign(1,tin[i],tin[i],1,n,1LL<<c[i]);
	}
	fr(i,1,m) {
		int ty;
		cin>>ty;
		if(ty==1) {
			int vk,ck;
			cin>>vk>>ck;
			assign(1,tin[vk],tout[vk]-1,1,n,1LL<<ck);
		} else {
			int vk;
			cin>>vk;
			trace(tin[vk],tout[vk]);
			cout<<__builtin_popcountll(query(1, tin[vk], tout[vk]-1, 1, n))<<endl;
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cerr<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}