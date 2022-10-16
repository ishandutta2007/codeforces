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

const int N=3e5+5;
pii tr[4*N];
int lazy[4*N];
int a[N];
bool disabled[N];
oset ans;
void build(int seg, int ll, int rr) {
	if(ll==rr) {
		tr[seg]={ll-1-(ll-a[ll]),ll};
	} else {
		build(seg<<1,ll,(ll+rr)/2);
		build(seg<<1|1,1+(ll+rr)/2,rr);
		tr[seg]=min(tr[seg<<1],tr[seg<<1|1]);
	}
}
void add(int seg, int ll, int rr, int l, int r, int x) {
	if(ll>r||l>rr)
		return;
	if(l<=ll&&rr<=r) {
		lazy[seg]+=x;
		tr[seg].fi+=x;
		return;
	}
	if(lazy[seg]) {
		lazy[seg<<1]+=lazy[seg];
		lazy[seg<<1|1]+=lazy[seg];
		tr[seg<<1].fi+=lazy[seg];
		tr[seg<<1|1].fi+=lazy[seg];
		lazy[seg]=0;
	}
	add(seg<<1,ll,(ll+rr)/2,l,r,x);
	add(seg<<1|1,1+(ll+rr)/2,rr,l,r,x);
	tr[seg]=min(tr[seg<<1],tr[seg<<1|1]);
}
pii get(int seg, int ll, int rr, int l, int r) {
	if(ll>r||l>rr)
		return {infl,ll};
	if(l<=ll&&rr<=r)
		return tr[seg];
	if(lazy[seg]) {
		lazy[seg<<1]+=lazy[seg];
		lazy[seg<<1|1]+=lazy[seg];
		tr[seg<<1].fi+=lazy[seg];
		tr[seg<<1|1].fi+=lazy[seg];
		lazy[seg]=0;
	}
	pii pee=min(get(seg<<1,ll,(ll+rr)/2,l,r),get(seg<<1|1,1+(ll+rr)/2,rr,l,r));
	tr[seg]=min(tr[seg<<1],tr[seg<<1|1]);
	return pee;
}
int n;
void disable(int a) {
	disabled[a]=1;
	ans.erase(a);
	add(1,1,n,a,a,infl);
	add(1,1,n,a+1,n,-1);
}

vector<pii> qur[300005];
int anser[300005];
void solve() {
	int q;
	cin>>n>>q;
//	trace(1);
	fr(i,1,n) {
		cin>>a[i];
		ans.insert(i);
	}
	build(1,1,n);
//	trace(1);
	fr(i,1,q) {
		int x,y;
		cin>>x>>y;
		qur[x+1].pb({n-y,i});
	}
//	trace(1);
	fr(i,1,n)
		if(a[i]>i) {
			disable(i);
//			trace(i);
		}
//	trace(get(1,1,n,1,13));
	fr(i,1,n) {
		pii hol=get(1,1,n,i,n);
//		trace(i,n,hol);
		while(hol.fi<0) {
//			trace(hol,i);
			disable(hol.se);
			hol=get(1,1,n,i,n);
		}
		trace(get(1,1,n,6,6));
		for(auto j:qur[i])
			anser[j.se]=ans.order_of_key(j.fi+1);
//		trace(qur[i]);
//		for(int i:ans) {
//			cout<<i<<endl;
//		}
		if(!disabled[i])
			disable(i);
	}
	trace(1);
	fr(i,1,q)
		cout<<anser[i]<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}