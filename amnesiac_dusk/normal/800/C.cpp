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
int gcdExtended(int a, int b, int *x, int *y) {
	if(a==0) {
		*x=0,*y=1;
		return b;
	}
	int x1,y1;
	int gcd=gcdExtended(b%a,a,&x1,&y1);
	*x=y1-(b/a)*x1;
	*y=x1;
	return gcd;
}

int modInverse(int a, int m) {
	int x,y;
	int g=gcdExtended(a,m,&x,&y);
	return (x%m+m)%m;
}

bool b[200005];
int dp[1<<17];
int from[1<<17];
int boo[1<<17];
vi pol[200005];
void solve() {
	int n,m;
	cin>>n>>m;
	rep(i,0,n) {
		int te;
		cin>>te;
		b[te]=1;
	}
	rep(i,0,m)
		if(b[i]==0)
			pol[gcd(i,m)].pb(i);
	vi facs;
	int mm=m;
	for(int i=2; i*i<=m; i++)
		while(m%i==0) {
			m/=i;
			facs.pb(i);
		}
	if(m!=1)
		facs.pb(m);
	m=mm;
	for(int i=0; i<(1<<sz(facs)); i++) {
		int poo=1;
		for(int j=0; j<sz(facs); j++)
			if((i>>j)&1)
				poo*=facs[j];
		boo[i]=poo;
		dp[i]+=sz(pol[poo]);
		for(int j=0; j<sz(facs); j++)
			if(!((i>>j)&1))
				if(dp[i^(1<<j)]<dp[i]) {
					dp[i^(1<<j)]=dp[i];
					from[i^(1<<j)]=i;
				}
	}
	vi seq;
	int at=(1<<sz(facs))-1;
	while(1) {
		for(int i:pol[boo[at]])
			seq.pb(i);
		if(at==0)
			break;
		at=from[at];
	}
	vi lol={1};
	seq.pb(1);
	reverse(all(seq));
	cout<<sz(seq)-1<<endl;
	for(int i=1; i<sz(seq); i++) {
		int po=gcd(seq[i-1],m);
		int gon=(modInverse(seq[i-1]/po,m/po)*(seq[i]/po))%m;
		cout<<gon<<" ";
		lol.pb((lol.back()*gon)%m);
	}
	trace(lol);
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}