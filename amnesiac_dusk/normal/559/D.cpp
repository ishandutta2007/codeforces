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
//#define double long double
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

pii a[200005];
int ComputeSignedArea(const vector<pii> p) {
	int area = 0;
	rep(i, 0, sz(p)) {
		int j = (i + 1) % p.size();
		area += p[i].fi * p[j].se - p[j].fi * p[i].se;
	}
	return area;
}

int cornerine(pii a, pii b) {
	int gc=gcd(abs(a.fi-b.fi),abs(a.se-b.se));
	return gc;
}
double pows[200];
void solve() {
	int n;
	cin>>n;
	rep(i,0,200)
		pows[i]=powl(2,i);
	fr(i,1,n)
		cin>>a[i].fi>>a[i].se;
	fr(i,n+1,2*n)
		a[i]=a[i-n];
	vector<pii> b(a+1,a+n+1);
	int internal=abs(ComputeSignedArea(b))+2;
	fr(i,1,n)
		internal-=cornerine(a[i],a[i+1]);
	assert(internal%2==0);
	internal/=2;
	double ans=internal;
	trace(ans);
	for(int i=1; i<=n; i++) {
		int area=a[i].fi*a[i+1].se-a[i+1].fi*a[i].se;
		int cor=cornerine(a[i],a[i+1]);
		for(int j=i+2; j<=n+i-2&&j<=i+50; j++) {
			area+=a[j-1].fi*a[j].se-a[j].fi*a[j-1].se;
			area+=a[j].fi*a[i].se-a[i].fi*a[j].se;
			cor+=cornerine(a[j-1], a[j]);
			int pts=n-j+i-1;
			double mul;
			if(n>=200) {
				mul=(1/pows[n-pts]);
			} else {
				mul=(pows[pts]-1)/(pows[n]-(n*(n+1.0L))/2-1);
			}
			double points=(abs(area)-cor+cornerine(a[i],a[j]))/2.0L;
			if(i==5&&j==8) {
				trace(area,cor,cornerine(a[i],a[j]));
			}
			trace(area,i,j,points,mul);
			ans-=mul*points;
			area-=a[j].fi*a[i].se-a[i].fi*a[j].se;
		}
	}
	cout<<ans<<endl;
}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}