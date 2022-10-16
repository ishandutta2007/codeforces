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
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
//#define double long double
#define pll pair<ll,ll>
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
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}


int a[100005];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n)
		cin>>a[i];
	set<pii> fat;
	fr(i,1,n)
		if(gcd(a[i],a[i%n+1])==1)
			fat.insert({i,i%n+1});
	set<int> avl;
	fr(i,1,n)
		avl.insert(i);
	int at=1;
	vi ans;
	while(sz(fat)) {
		auto it=fat.lower_bound({at,0});
		if(it==fat.end())
			it=fat.begin();
		pii mota=*it;
		ans.pb(mota.se);
		fat.erase(it);
		avl.erase(mota.se);
		if(avl.empty())
			break;
		auto it2=fat.lower_bound({mota.se,0});
		if(it2!=fat.end()&&(*it2).fi==mota.se)
			fat.erase(it2);
		auto it3=avl.lower_bound(mota.se);
		if(it3==avl.end())
			it3=avl.begin();
		if(gcd(a[mota.fi],a[*it3])==1)
			fat.insert({mota.fi,*it3});
		at=mota.se;
	}
	cout<<sz(ans);
	for(int i:ans)
		cout<<" "<<i;
	cout<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
	cin>>t;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
}