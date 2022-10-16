#pragma GCC optimze("Ofast")
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
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}


int a[300005];
int cnt[300005];
bool pr[300005];
int fact[300005],ifact[300005];
int ncr(int n, int r) {
	return (((fact[n]*ifact[r])%mod)*ifact[n-r])%mod;
}
void solve() {
	fact[0]=1;
	fr(i,1,300000)
		fact[i]=(fact[i-1]*i)%mod;
	ifact[300000]=powm(fact[300000],mod-2);
	for(int i=299999; i>=0; i--)
		ifact[i]=(ifact[i+1]*(i+1))%mod;
	int n;
	cin>>n;
	fr(i,1,n) {
		cin>>a[i];
		cnt[a[i]]++;
	}
	memset(pr,1,sizeof(pr));
	pr[1]=0;
	fr(i,1,300000)
		if(pr[i])
			for(int j=i*i; j<=300000; j+=i)
				pr[j]=0;
	fr(i,2,300000)
		if(pr[i])
			for(int j=i*i; j<=300000; j*=i)
				pr[j]=1;
	int ans=0;
	fr(i,2,300000)
		if(pr[i]) {
			int tes=0;
			for(int j=i; j<=300000; j+=i)
				tes+=cnt[j];
			int tes2=n-tes;
			if(tes>tes2)
				swap(tes,tes2);
			int lol=powm(2,tes2);
			fr(j,0,tes) {
				ans=(ans+((ncr(tes,j)*j)%mod)*lol)%mod;
				lol=(lol-ncr(tes2,j)+mod)%mod;
			}
			lol=powm(2,tes);
			fr(j,0,tes) {
				lol=(lol-ncr(tes,j)+mod)%mod;
				ans=(ans+((ncr(tes2,j)*j)%mod)*lol)%mod;
			}
		}
	if(ans<0)
		ans+=mod;
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}