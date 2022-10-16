#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
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

int fact[1000005],ifact[1000005];
vector<int> lol;
vi go(int n) {
	vi pol(sz(lol),0);
	for(int i=0; i<sz(lol); i++)
		while(n%lol[i]==0) {
			pol[i]++;
			n/=lol[i];
		}
	return pol;
}
inline int go(vi &u, vi &com) {
	int su=0,ans=1;
	rep(i,0,sz(u))
		su+=u[i]-com[i];
	ans=fact[su];
	rep(i,0,sz(u))
		ans=(ans*ifact[u[i]-com[i]])%mod;
	return ans;
}
void solve() {
	fact[0]=1;
	fr(i,1,1000000)
		fact[i]=(fact[i-1]*i)%mod;
	ifact[1000000]=powm(fact[1000000],mod-2);
	for(int i=999999; i>=0; i--)
		ifact[i]=(ifact[i+1]*(i+1))%mod;
	int n;
	cin>>n;
	int nn=n;
	for(int i=2; i*i<=n; i++) {
		if(n%i==0) {
			lol.pb(i);
			n/=i;
			while(n%i==0)
				n/=i;
		}
	}
	if(n!=1)
		lol.pb(n);
	 int q;
	 cin>>q;
	 while(q--) {
		 int uu,vv;
		 cin>>uu>>vv;
		 vi u=go(uu),v=go(vv);
		 vi com(sz(lol));
		 rep(i,0,sz(lol))
		 	 com[i]=min(u[i],v[i]);
		 trace(u,v,com);
		 cout<<(go(u,com)*go(v,com))%mod<<endl;
	 }
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(20);
	int t=1;
//	cin>>t;
	fr(i,1,t)
	{
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}