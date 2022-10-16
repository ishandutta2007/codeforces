#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
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
int lazy[4*N],vals[4*N];
int start[4*N],last[4*N];
int pref[4*N],suf[4*N];
int lhill[4*N],rhill[4*N];
void pushdown(int seg,int l, int r) {
	if(lazy[seg]) {
		if(l!=r) {
			lazy[seg<<1]+=lazy[seg];
			lazy[seg<<1|1]+=lazy[seg];
		}
		start[seg]+=lazy[seg];
		last[seg]+=lazy[seg];
		lazy[seg]=0;
	}
}
void update(int seg, int ll, int rr, int l, int r, int val) {
	pushdown(seg,ll,rr);
	if(l>rr||r<ll)
		return;
	if(l<=ll&&rr<=r) {
		lazy[seg]+=val;
		pushdown(seg,ll,rr);
		return;
	}
	int left=seg<<1,right=seg<<1|1;
	update(left, ll,(ll+rr)/2, l, r, val);
	update(right,(ll+rr)/2+1,rr, l,r,val);
	int lel=(rr+ll)/2-ll+1,rel=rr-(rr+ll)/2;
	vals[seg]=max(vals[left],vals[right]);
	int leng=rr-ll+1;
	start[seg]=start[left];
	last[seg]=last[right];
	lhill[seg]=lhill[left];
	rhill[seg]=rhill[right];
	pref[seg]=pref[left];
	suf[seg]=suf[right];
	if(last[left]>start[right]) {
		vals[seg]=max(vals[seg],rhill[left]+pref[right]);
		if(pref[right]==rel)
			rhill[seg]=rhill[left]+rel;
		if(lhill[left]==lel)
			lhill[seg]+=pref[right];
		if(pref[left]==lel)
			pref[seg]=lel+pref[right];
	} else if(last[left]<start[right]) {
		vals[seg]=max(vals[seg],lhill[right]+suf[left]);
		if(suf[left]==lel)
			lhill[seg]=lhill[right]+lel;
		if(rhill[right]==rel)
			rhill[seg]+=suf[left];
		if(suf[right]==rel)
			suf[seg]=suf[left]+rel;
	}
	if(lhill[seg]==leng)
		rhill[seg]=leng;
	if(rhill[seg]==leng)
		lhill[seg]=leng;
	vals[seg]=max(vals[seg],max(suf[seg],pref[seg]));
	vals[seg]=max(vals[seg],max(lhill[seg],rhill[seg]));
//	trace(left,pref[left],suf[left],lhill[left],rhill[left]);
//	trace(right,pref[right],suf[right],lhill[right],rhill[right]);
//	trace(seg,l,r,lhill[seg],rhill[seg]);
//	trace(ll,rr,start[seg],last[seg]);
//	trace(pref[seg],suf[seg],vals[seg]);
//	cout<<endl;
}
void solve() {
	int n;
	cin>>n;
	fr(i,1,4*n) {
		lhill[i]=1;
		rhill[i]=1;
		suf[i]=1;
		pref[i]=1;
		vals[i]=1;
	}
	fr(i,1,n) {
		int te;
		cin>>te;
//		trace(i,i,te);
		update(1, 1, n, i, i,te);
//		cout<<endl<<endl;
	}
	int m;
	cin>>m;
	while(m--) {
		int l,r,d;
		cin>>l>>r>>d;
//		trace(l,r,d);
		update(1, 1, n, l, r, d);
		cout<<vals[1]<<endl;
	}
}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}