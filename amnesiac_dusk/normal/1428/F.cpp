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

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
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

const int N=5e5+5;
int tr[4*N],lazy[4*N],lazy2[4*N];
void apply(int seg, int ll, int rr, int pp) {
	tr[seg]+=(rr-ll+1)*pp;
	lazy[seg]+=pp;
}
void pushdown(int seg, int ll, int rr) {
	if(lazy[seg]&&ll!=rr) {
		apply(seg<<1,ll,(ll+rr)/2,lazy[seg]);
		apply(seg<<1|1,(ll+rr)/2+1,rr,lazy[seg]);
		lazy[seg]=0;
	}
}
void add(int seg, int ll, int rr, int l, int r) {
	if(ll>r||l>rr)
		return;
	if(l<=ll&&rr<=r) {
		apply(seg,ll,rr,1);
		return;
	}
	pushdown(seg,ll,rr);
	add(seg<<1,ll,(ll+rr)/2,l,r);
	add(seg<<1|1,(ll+rr)/2+1,rr,l,r);
	tr[seg]=tr[seg<<1]+tr[seg<<1|1];
}
void mexi(int seg, int ll, int rr, int l, int r, int val) {
//	if(l==6&&r==7) {
//		trace(tr[seg],ll,rr,seg);
//	}
	if(ll>r||l>rr)
		return;
	pushdown(seg,ll,rr);
	if(l<=ll&&rr<=r) {
		tr[seg]=val*(rr-ll+1);
		lazy[seg]=0;
		return;
	}
	mexi(seg<<1,ll,(ll+rr)/2,l,r,val);
	mexi(seg<<1|1,(ll+rr)/2+1,rr,l,r,val);
	tr[seg]=tr[seg<<1]+tr[seg<<1|1];
}
void solve() {
	string s;
	int n;
	cin>>n;
	cin>>s;
	s='0'+s;
	int laster=-1;
	vector<pii> potol;
	potol.pb({infi,0});
	int ans=0;
	fr(i,1,n) {
		if(s[i]=='1') {
			if(laster==-1)
				laster=i;
			int val=i-laster+1;
			add(1,1,n,laster,i);
			while(val>=potol.back().fi)
				potol.pop_back();
			int to=potol.back().se+1;
			if(potol.back().se!=0)
				to=potol.back().se+potol.back().fi-val+1;
			mexi(1,1,n,to,laster-1,val);
			potol.pb({val,laster});
		} else
			laster=-1;
		ans+=tr[1];
	}
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}