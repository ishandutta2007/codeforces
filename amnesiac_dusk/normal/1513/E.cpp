#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef double f80;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll,ll> pll;
#define double long double
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const int infi=0x3f3f3f3f;
const ll infl=0x3f3f3f3f3f3f3f3fLL;
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
	while(b>0) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

int a[100005],fact[100005],ifact[100005];
void solve() {
	fact[0]=1;
	fr(i,1,100000)
		fact[i]=(fact[i-1]*i)%mod;
	fr(i,0,100000)
		ifact[i]=powm(fact[i],mod-2);
	int n;
	cin>>n;
	fr(i,1,n)
		cin>>a[i];
	int su=accumulate(a+1,a+n+1,0LL);
	if(su%n) {
		cout<<0<<endl;
		return;
	}
	int to=su/n;
	int small=0,large=0;
	fr(i,1,n)
		if(a[i]>to)
			large++;
		else if(a[i]<to)
			small++;
	map<int,int> sheamus;
	fr(i,1,n)
		sheamus[a[i]]++;
	int ans=1;
	if(small<=1||large<=1) {
		ans=fact[n];
	} else {
		int med=n-small-large;
		ans=(fact[n]*ifact[n-med])%mod;
		ans=(ans*fact[small])%mod;
		ans=(ans*fact[large])%mod;
		ans=(ans*2)%mod;
	}
	for(auto i:sheamus) {
		ans=(ans*ifact[i.se])%mod;
	}
	cout<<ans%mod<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
}