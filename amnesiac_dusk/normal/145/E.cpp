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
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	const char *comma=strchr(names+1,',');
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
//#define int long long
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
 
const int N=1e6+5;
int tr4[2*N],tr47[2*N],tr74[2*N],tr7[2*N];
int lazy[2*N];
void update(int seg, int ll, int rr, int l, int r) {
	if(ll>r||l>rr)
		return;
//	trace(seg,ll,rr);
//	trace(tr47[seg],tr74[seg],tr4[seg],tr7[seg]);
	if(l<=ll&&rr<=r) {
		swap(tr4[seg],tr7[seg]);
		swap(tr47[seg],tr74[seg]);
		lazy[seg]^=1;
//		return;
	} else {
		int mid=(ll+rr)/2;
		int left=seg+1,right=seg+2*(mid-ll+1);
		if(lazy[seg]) {
			swap(tr4[left],tr7[left]);
			swap(tr47[left],tr74[left]);
			swap(tr4[right],tr7[right]);
			swap(tr47[right],tr74[right]);
			lazy[left]^=1;
			lazy[right]^=1;
			lazy[seg]=0;
		}
		update(left, ll, mid, l, r);
		update(right,mid+1,rr,l,r);
		tr47[seg]=max(tr47[left]+tr7[right],tr4[left]+tr47[right]);
		tr74[seg]=max(tr74[left]+tr4[right],tr7[left]+tr74[right]);
		tr4[seg]=tr4[left]+tr4[right];
		tr7[seg]=tr7[left]+tr7[right];
	}
//	trace(seg,ll,rr);
//	trace(tr47[seg],tr74[seg],tr4[seg],tr7[seg]);
}
string s;
void build(int seg, int ll, int rr) {
	if(ll==rr) {
		if(s[ll]=='4') {
			tr4[seg]=1;
		} else
			tr7[seg]=1;
		tr47[seg]=1;
		tr74[seg]=1;
	} else {
		int mid=(ll+rr)/2;
		int left=seg+1,right=seg+2*(mid-ll+1);
		build(left,ll,mid);
		build(right,mid+1,rr);
		tr47[seg]=max(tr47[left]+tr7[right],tr4[left]+tr47[right]);
		tr74[seg]=max(tr74[left]+tr4[right],tr7[left]+tr74[right]);
		tr4[seg]=tr4[left]+tr4[right];
		tr7[seg]=tr7[left]+tr7[right];
	}
//	trace(seg,ll,rr);
//	trace(tr47[seg],tr74[seg],tr4[seg],tr7[seg]);
}
void solve() {
	int n,m;
	cin>>n>>m>>s;
	s='4'+s;
	build(1,1,n);
	while(m--) {
		string ty;
		cin>>ty;
		if(ty=="count") {
			cout<<max(tr47[1],max(tr4[1],tr7[1]))<<endl;
		} else {
			int l,r;
			cin>>l>>r;
			update(1, 1, n, l, r);
//			cout<<endl;
		}
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