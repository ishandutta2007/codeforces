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

pii a[200005],b[200005];
//50 > 100
//5 < 1
//95+49
//50+4
int solve(vector<pii> pp1, vector<pii> pp2) {
	int mi1=infi,mi2=infi,dif=0;
	for(int i=sz(pp1)-1,j=sz(pp2)-1; i>=0; i--) {
		mi1=min(mi1,pp1[i].se);
		while(j>=0&&pp2[j].fi>=pp1[i].fi) {
			mi2=min(mi2,pp2[j].se);
			j--;
		}
		trace(mi1,mi2);
		dif=max(dif,pp1[i].fi-max(mi1,mi2));
	}
	trace(dif,pp1,pp2);
	return 2*dif;
}
void solve() {
	int n;
	cin>>n;
	fr(i,1,n)
		cin>>a[i].fi;
	fr(i,1,n)
		cin>>a[i].se;
	vector<pii> pp1,pp2;
	fr(i,1,n)
		if(a[i].fi>a[i].se)
			pp1.pb(a[i]);
		else if(a[i].fi<a[i].se)
			pp2.pb({a[i].se,a[i].fi});
	int ans=0;
	fr(i,1,n)
		ans+=abs(a[i].fi-a[i].se);
	sort(all(pp1));
	sort(all(pp2));
	trace(ans);
	ans-=max(solve(pp1,pp2),solve(pp2,pp1));
	cout<<ans<<endl;
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