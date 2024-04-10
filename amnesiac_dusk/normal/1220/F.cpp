//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include "bits/stdc++.h"
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
//const int mod=998244353;
const int mod=1000000007;
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

int a[400005];
int b[200005],pos[200005];
pii tr[400100];
pii query(int l, int r) {
	pii an={200001,0};
	r++;
	for(l+=200005,r+=200005; l<r; l>>=1,r>>=1) {
		if(l&1) an=min(an,tr[l++]);
		if(r&1) an=min(an,tr[--r]);
	}
	return an;
}
int solve(int l, int r) {
	if(l>r)
		return 0;
	pii tol=query(l,r);
	return max(solve(l,tol.se-1),solve(tol.se+1,r))+1;
}
void solve() {
	int n;
	cin>>n;
	int st=0;
	fr(i,1,n) {
		cin>>a[i];
		a[n+i]=a[i];
		if(a[i]==1)
			st=i;
	}
	fr(i,st+1,st+n-1) {
		b[i-st]=a[i];
	}
	for(int i=1; i<n; i++) {
		tr[i+200005]={b[i],i};
	}
	for(int i=200004; i>0; i--)
		tr[i]=min(tr[i<<1],tr[i<<1|1]);
	int lo=1,hi=n-1,mid=(lo+hi)/2;
	int ans=n,ans2=0;
	while(lo<hi) {
		int val1=solve(1,mid),val2=solve(mid+1,n-1);
		if(val1>val2) {
			hi=mid-1;
		} else if(val1<val2)
			lo=mid+1;
		else {
			if(ans>max(val1,val2)) {
				ans=max(val1,val2);
				ans2=mid;
			}
			break;
		}
		if(ans>max(val1,val2)) {
			ans=max(val1,val2);
			ans2=mid;
		}
		mid=(lo+hi)/2;
	}
	int val1=solve(1,mid),val2=solve(mid+1,n-1);
	if(ans>max(val1,val2)) {
		ans=max(val1,val2);
		ans2=mid;
	}
	cout<<ans+1<<" "<<(st+mid)%n<<endl;
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