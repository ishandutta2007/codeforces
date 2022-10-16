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
const ll infl=1e18;
const int infi=1e9;
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
	}
	return res;
}


void solve() {
	int n;
	cin>>n;
	vector<pair<int,pii>> hori,verti;
	fr(i,1,n) {
		int xi1,yi1,xi2,yi2;
		cin>>xi1>>yi1>>xi2>>yi2;
		if(xi1!=xi2) {
			if(xi1>xi2)
				swap(xi1,xi2);
			hori.pb({yi1,{xi1,xi2}});
		}
		if(yi1!=yi2) {
			if(yi1>yi2)
				swap(yi1,yi2);
			verti.pb({xi1,{yi1,yi2}});
		}
	}
	sort(all(hori),[](auto &i, auto &j){
		return i.se.se<j.se.se;
	});
	sort(all(verti));
	int ans=0;
	vector<pii> tod;
	for(int i=0; i<sz(verti); i++) {
		oset ho;
		tod.clear();
		for(auto j:hori) {
			if(j.se.fi<=verti[i].fi&&j.se.se>=verti[i].fi&&verti[i].se.fi<=j.fi&&j.fi<=verti[i].se.se) {
				ho.insert(j.fi);
				tod.pb({j.se.se,j.fi});
			}
		}
		for(int j=i+1,k=0; j<sz(verti)&&k<sz(tod); j++) {
			while(k<sz(tod)&&verti[j].fi>tod[k].fi) {
				ho.erase(tod[k].se);
				k++;
			}
			int segs=ho.order_of_key(verti[j].se.se+1)-ho.order_of_key(verti[j].se.fi);
			ans+=(segs*(segs-1))/2;
		}
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