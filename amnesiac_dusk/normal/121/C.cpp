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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(int a, int b, int mod) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

int fact[14];
vi anserous;
void go(vi allol, int hol, int ind) {
	if(ind<0)
		return;
	trace(allol,hol,ind);
	for(int i=ind; i>=0; i--) {
		if(i*fact[ind]<=hol) {
			anserous.pb(allol[i]);
			vi allo2;
			for(int j:allol)
				if(j!=anserous.back())
					allo2.pb(j);
			go(allo2,hol-i*fact[ind],ind-1);
			break;
		}
	}
}
void solve() {
	int n,k;
	cin>>n>>k;
	fact[0]=1;
	fr(i,1,13)
		fact[i]=(fact[i-1]*i);
	if(n<=13&&k>fact[n]) {
		cout<<-1<<endl;
		return;
	}
	vi a={4,7};
	for(int i=0; i<1000; i++) {
		a.pb(a[i]*10+4);
		a.pb(a[i]*10+7);
	}
	int tol=max(0LL,n-13);
	int ans=0;
	for(int i:a)
		if(i<=tol)
			ans++;
	vi pol;
	for(int i=tol+1; i<=n; i++)
		pol.pb(i);
	anserous.pb(0);
	go(pol,k-1,sz(pol)-1);
	trace(anserous,sz(pol));
	for(int i=tol+1; i<=n; i++) {
		int poo=anserous[i-tol],ind=i;
		bool luck1=0,luck2=0;
		for(int j:a) {
			if(j==poo)
				luck1=1;
			if(j==ind)
				luck2=1;
		}
		if(luck1&&luck2)
			ans++;
	}
	cout<<ans<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(20);
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