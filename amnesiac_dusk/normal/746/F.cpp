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

const int N=1e4+5;
int t[200005],a[200005];
pii tr[4*N];
int query(int seg, int ll, int rr, int k) {
	if(tr[seg].fi<=k)
		return tr[seg].se;
	if(ll==rr)
		return ll*k;
	if(tr[seg<<1|1].fi<k) {
		return tr[seg<<1|1].se+query(seg<<1,ll,(ll+rr)/2,k-tr[seg<<1|1].fi);
	}
	return query(seg<<1|1,(ll+rr)/2+1,rr,k);
}
void update(int seg, int ll, int rr, int p,int val) {
	if(ll>p||p>rr)
		return;
	tr[seg].fi+=val;
	tr[seg].se+=val*p;
	if(ll==rr)
		return;
	update(seg<<1, ll,(ll+rr)/2, p, val);
	update(seg<<1|1,1+(ll+rr)/2,rr, p, val);

}
void solve() {
	int n,w,k;
	cin>>n>>w>>k;
	fr(i,1,n)
		cin>>a[i];
	fr(i,1,n)
		cin>>t[i];
	t[n+1]=10*k;
	int ans=0,sum=0,plea=0;
	for(int i=1,j=0; i<=n; i++) {
		while(j<=n&&sum-query(1,1,1e4,w)<=k) {
			ans=max(ans,plea);
			j++;
			update(1, 1, 1e4, t[j]/2, 1);
			sum+=t[j];
			plea+=a[j];
		}
		update(1, 1, 1e4, t[i]/2, -1);
		sum-=t[i];
		plea-=a[i];
	}
	cout<<ans<<endl;
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