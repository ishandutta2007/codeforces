//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=1e9;
const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(ll a, ll b) {
	int res=1;
	a%=mod;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
const int N=1e5+5;
int a[4*N],lazy[4*N],k[N];
void pushdown(int seg,int l, int r) {
	if(lazy[seg]) {
		lazy[seg<<1]+=lazy[seg];
		lazy[seg<<1|1]+=lazy[seg];
		int mid=(l+r)>>1;
		a[seg<<1]+=(mid-l+1)*lazy[seg];
		a[seg<<1|1]+=(r-mid)*lazy[seg];
		lazy[seg]=0;
	}
}
void inc(int seg, int ll, int rr,int l,int r,int val){
	if(ll>r||rr<l)
		return;
	if(l<=ll&&rr<=r) {
		lazy[seg]+=val;
		a[seg]+=val*(rr-ll+1);
		return;
	}
	pushdown(seg,ll,rr);
	inc(seg<<1,ll,(ll+rr)/2,l,r,val);
	inc(seg<<1|1,1+(ll+rr)/2,rr,l,r,val);
	a[seg]=a[seg<<1]+a[seg<<1|1];
}
int get(int seg, int ll, int rr,int l,int r){
	if(ll>r||rr<l)
		return 0;
	if(l<=ll&&rr<=r)
		return a[seg];
	pushdown(seg,ll,rr);
	return get(seg<<1,ll,(ll+rr)/2,l,r)+get(seg<<1|1,1+(ll+rr)/2,rr,l,r);
}
int n;
void inc(int l,int r, int val) {
	if(l>n)
		return;
	inc(1, 1, n, l, r, val);
}
int get(int l, int r) {
	if(l>n)
		return infl;
	return get(1,1,n,l,r);
}
void solve() {
	int te;
	cin>>n;
	set<int> unl;
	fr(i,1,n) {
		cin>>te;
		inc(1, 1, n, i, i, te);
		unl.insert(i);
	}
	fr(i,1,n-1) {
		cin>>k[i];
		trace(k[i]);
	}
	int q;
	cin>>q;
	trace(q);
	while(q--) {
		char typ;
		cin>>typ;
		if(typ=='+') {
			int i,x;
			cin>>i>>x;
			trace(i,x);
			int ii=i;
			auto lol=unl.lower_bound(i);
			while(lol!=unl.end()) {
				int lul=*lol;
				if(lul>n)
					break;
				unl.erase(lul);
				trace(i,lul,x);
				inc(i,lul,x);
				int here=get(lul,lul),next=get(lul+1,lul+1);
				if(here+k[lul]>next) {
					x=here+k[lul]-next;
				} else {
					i=lul;
					break;
				}
				trace(i,lul,x);
				i=lul+1;
				lol=unl.lower_bound(i);
			}
			unl.insert(ii-1);
			unl.insert(i);
		} else {
			int l,r;
			cin>>l>>r;
			trace(l,r);
			cout<<get(1,1,n,l,r)<<endl;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}