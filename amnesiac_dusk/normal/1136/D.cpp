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

const int N=3e5+5;
set<int> s[N];
int p[N];
void solve() {
	int n,m;
	cin>>n>>m;
	fr(i,1,n)
		cin>>p[i];
	fr(i,1,m) {
		int u,v;
		cin>>u>>v;
		s[u].insert(v);
	}
	set<int> swaps;
	fr(i,1,n-1) {
		if(s[p[i]].count(p[i+1])) {
			swaps.insert(i);
		}
	}
	int place=n;
	while(!swaps.empty()) {
		int tol=*swaps.rbegin();
		swaps.erase(tol);
		swap(p[tol],p[tol+1]);
		trace(tol,p[tol]);
		if(tol+1==place)
			place--;
		if(tol>1) {
			if(s[p[tol-1]].count(p[tol])) {
				swaps.insert(tol-1);
				trace(tol-1);
			}
		}
		if(tol+2<=place) {
			if(s[p[tol+1]].count(p[tol+2])) {
				swaps.insert(tol+1);
				trace(tol+1);
			}
		}
	}
	cout<<n-place<<endl;
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