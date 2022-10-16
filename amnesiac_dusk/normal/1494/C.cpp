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

int holve(vi a, vi b) {
	sort(all(a));
	sort(all(b));
	vi big;
	for(int i:b) {
		if(lower_bound(all(a),i)!=a.end()&&(*lower_bound(all(a),i))==i)
			big.pb(1);
		else
			big.pb(0);
	}
	for(int i=sz(big)-2; i>=0; i--)
		big[i]+=big[i+1];
	big.pb(0);
	int an=0;
	for(int i=0; i<sz(b); i++) {
		int num=upper_bound(all(a),b[i])-a.begin();
		int numa=upper_bound(all(b),b[i])-upper_bound(all(b),b[i]-num);
		an=max(an,numa+big[i+1]);
	}
	return an;
}
void solve() {
	int n,m;
	cin>>n>>m;
	vi pa,pb;
	vi na,nb;
	fr(i,1,n) {
		int a;
		cin>>a;
		if(a>0) {
			pa.pb(a);
		} else
			na.pb(-a);
	}
	fr(i,1,m) {
		int b;
		cin>>b;
		if(b>0) {
			pb.pb(b);
		} else
			nb.pb(-b);
	}
	cout<<holve(na,nb)+holve(pa,pb)<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
}