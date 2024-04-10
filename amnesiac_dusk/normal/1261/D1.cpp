#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
#define forn(i, x, y) for(int i = x; i <= y; i++)
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
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
const int mod=998244353;
//const int mod=1000000007;
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

int h[200005];
int fact[200005],ifact[200005],pk[200005],pkm[200005];
inline int ncr(int n, int r) {
	return (((fact[n]*ifact[r])%mod)*ifact[n-r])%mod;
}
void solve() {
	fact[0]=1;
	fr(i,1,200000)
		fact[i]=(fact[i-1]*i)%mod;
	ifact[200000]=powm(fact[200000],mod-2);
	for(int i=199999; i>=0; i--)
		ifact[i]=(ifact[i+1]*(i+1))%mod;
	int n,k;
	cin>>n>>k;
	pk[0]=1;
	pkm[0]=1;
	fr(i,1,200000) {
		pk[i]=(pk[i-1]*(k))%mod;
		pkm[i]=(pkm[i-1]*(k-2))%mod;
	}
	if(k==1) {
		cout<<0<<endl;
		return;
	}
	fr(i,1,n)
		cin>>h[i];
	h[n+1]=h[1];
	//ith elem=h[i]
	//ith elem=h[i+1]
	//h[i]==h[i+1]
	int un=0;
	fr(i,1,n)
		if(h[i]!=h[i+1])
			un++;
	int ans=0;
	for(int i=0; 2*i<un; i++) {
		for(int j=i+1; i+j<=un; j++) {
			int te=(ncr(un,i)*ncr(un-i,j))%mod;
			te=(te*pkm[un-i-j])%mod;
			ans=(ans+te)%mod;
		}
	}
	cout<<(ans*pk[n-un])%mod<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(7);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}