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
const int N = 200005;
int tr[4*N],lazy[4*N],mini[4*N],maxi[4*N];
int a[N];
void go(int seg,int ll, int rr, int val) {
	lazy[seg]=val;
	tr[seg]=val*(rr-ll+1);
	mini[seg]=val;
	maxi[seg]=val;
}
void pushdown(int seg, int ll, int rr) {
	if(lazy[seg]) {
		go(seg<<1,ll,(ll+rr)/2,lazy[seg]);
		go(seg<<1|1,1+(ll+rr)/2,rr,lazy[seg]);
		lazy[seg]=0;
	}
}
void update(int seg, int ll, int rr, int l, int r, int val) {
	if(ll>r||l>rr||mini[seg]>=val)
		return;
	if(l<=ll&&rr<=r&&maxi[seg]<=val) {
		go(seg,ll,rr,val);
		return;
	}
	pushdown(seg,ll,rr);
	update(seg<<1,ll,(ll+rr)/2,l,r,val);
	update(seg<<1|1,(ll+rr)/2+1,rr,l,r,val);
	tr[seg]=tr[seg<<1]+tr[seg<<1|1];
	mini[seg]=min(mini[seg<<1],mini[seg<<1|1]);
	maxi[seg]=max(maxi[seg<<1],maxi[seg<<1|1]);
}
int val,cnt;
void sunext(int seg, int ll, int rr, int l, int r) {
	if(ll>r||l>rr||mini[seg]>val)
		return;
	if(l<=ll&&rr<=r&&tr[seg]<=val) {
		cnt+=rr-ll+1;
		val-=tr[seg];
		return;
	}
	pushdown(seg,ll,rr);
	sunext(seg<<1,ll,(ll+rr)/2,l,r);
	sunext(seg<<1|1,1+(ll+rr)/2,rr,l,r);
	tr[seg]=tr[seg<<1]+tr[seg<<1|1];
	mini[seg]=min(mini[seg<<1],mini[seg<<1|1]);
}
void solve() {
	int n,q;
	cin>>n>>q;
	fr(i,1,n) {
		cin>>a[i];
		update(1,1,n,i,i,a[i]);
	}
	while(q--) {
		int t,x,y;
		cin>>t>>x>>y;
		if(t==1) {
			update(1,1,n,1,x,y);
		} else {
			val=y;
			cnt=0;
			sunext(1,1,n,x,n);
			cout<<cnt<<endl;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
}