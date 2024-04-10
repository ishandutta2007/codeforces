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

pii minp[512];
pii piz[512];
int pref[512],pref2[512];
void solve() {
	int n,m;
	cin>>n>>m;
	fr(i,1,n) {
		int f;
		cin>>f;
		int mask=0,te;
		fr(j,1,f) {
			cin>>te;
			mask|=(1<<te);
		}
		pref2[mask>>1]++;
	}
	for(int i=0; i<512; i++) {
		for(int j=0; j<512; j++) {
			if((i&j)==j) {
				pref[i]+=pref2[j];
			}
		}
	}
	fill(minp,minp+512,pii{infl,infl});
	fr(i,1,m) {
		int cost;
		int f;
		cin>>cost>>f;
		int mask=0,te;
		fr(j,1,f) {
			cin>>te;
			mask|=(1<<te);
		}
		mask>>=1;
		if(minp[mask].fi>cost) {
			minp[mask].se=minp[mask].fi;
			piz[mask].se=piz[mask].fi;
			minp[mask].fi=cost;
			piz[mask].fi=i;
		} else if(minp[mask].se>cost) {
			minp[mask].se=cost;
			piz[mask].se=i;
		}
	}
	int ans=0,ansc=infl;
	pii pizzas={1,2};
	for(int i=0; i<512; i++) {
		for(int j=i+1; j<512; j++) {
			int mask=i|j,cost=minp[i].fi+minp[j].fi,peop=0;
			if(cost>=infl)
				continue;
			peop=pref[mask];
			trace(peop,ans,i,j);
			if((peop==ans&&ansc>cost)||peop>ans) {
				ans=peop;
				ansc=cost;
				pizzas={piz[i].fi,piz[j].fi};
			}
		}
	}
	for(int i=0; i<512; i++) {
		int mask=i,cost=minp[i].fi+minp[i].se,peop=0;
		if(cost>=infl)
			continue;
		peop=pref[mask];
		if((peop==ans&&ansc>cost)||peop>ans) {
			ans=peop;
			ansc=cost;
			pizzas={piz[i].fi,piz[i].se};
		}
	}
	cout<<pizzas.fi<<" "<<pizzas.se<<endl;
}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}