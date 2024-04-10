/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
//#define endl '\n'
#endif
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
#endif
#define pb push_back
#define fi first
#define se second
//#define int long long
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
//const int mod=998244353;
#define mod 1000000007
//const int mod=1000000007;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
const int N=2e6+5;
vi facs[N+5];
int pij[N+5];
int mu[N+5];
bool np[N+5];
int powm(ll a, int b) {
	ll res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
void solve() {
	fill(mu,mu+N,1);
	fr(i,1,N)
		facs[i].pb(1);
	fr(i,2,N) {
		facs[i].pb(i);
		for(int j=2*i; j<=N; j+=i) {
			np[j]=1;
			facs[j].pb(i);
		}
	}
	fr(i,2,N) {
		if(np[i]==0) {
			for(int j=i; j<=N; j+=i)
				mu[j]*=-1;
			if(i*(i+0LL)<=N) {
				int te=i*i;
				for(int j=te; j<=N; j+=te)
					mu[j]=0;
			}
		}
	}
	int n,k;
	cin>>n>>k;
	fr(i,1,k) {
		pij[i]=powm(i,n);
	}
	ll ans=0;
	ll curans=0;
	fr(i,1,k) {
		for(int j:facs[i]) {
			curans=curans-mu[j]*pij[(i-1)/j]+mu[j]*pij[i/j];
			trace(i,j,mu[j],(i-1)/j,i/j);
		}
		curans=(curans%mod+mod)%mod;
		trace(curans);
		ans=(ans+(curans^i))%mod;
	}
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
	cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}