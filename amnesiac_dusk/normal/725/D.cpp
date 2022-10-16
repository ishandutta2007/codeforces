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

const int N=300005;
pair<pii,int> tw[N];
pair<int,int> lol[4*N];
void update(int seg, int l, int r, int p, int val) {
	if(p>r||l>p)
		return;
	if(l==p&&p==r) {
		lol[seg].fi=val;
		lol[seg].se=1;
		return;
	}
	update(seg<<1,l,(l+r)/2,p,val);
	update(seg<<1|1,1+(l+r)/2,r,p,val);
	lol[seg].fi=lol[seg<<1].fi+lol[seg<<1|1].fi;
	if(lol[seg].fi>infl)
		lol[seg].fi=infl;
	lol[seg].se++;
}
int query(int seg, int l, int r,int val) {
	if(l==r) {
		return (lol[seg].fi<=val)?lol[seg].se:0;
	}
	if(lol[seg<<1].fi<=val) {
		return lol[seg<<1].se+query(seg<<1|1,(l+r)/2+1,r,val-lol[seg<<1].fi);
	} else
		return query(seg<<1,l,(l+r)/2,val);
}
int indices[N];
int po[N];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n) {
		cin>>tw[i].fi.fi>>tw[i].fi.se;
		tw[i].se=i;
		indices[i]=i;
	}
	sort(indices+2,indices+n+1,[](int i, int j) {
		return tw[i].fi.fi-tw[i].fi.se>tw[j].fi.fi-tw[j].fi.se;
	});
	fr(i,1,n) {
		po[indices[i]]=i;
	}
	sort(tw+2,tw+n+1);
	reverse(tw+2,tw+n+1);
	int ans=n;
	int ball=tw[1].fi.fi;
	for(int i=2; i<=n; i++) {
		int spare=ball-tw[i].fi.fi;
		if(spare>=0) {
			ans=min(ans,i-1-query(1,1,n,spare));
			trace(i,ans,spare,query(1,1,n,spare));
		}
		update(1,1,n,po[tw[i].se],tw[i].fi.se+1-tw[i].fi.fi);
		trace(po[tw[i].se],tw[i].fi.se+1-tw[i].fi.fi);
	}
	ans=min(ans,n-query(1,1,n,ball));
	cout<<ans<<endl;

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