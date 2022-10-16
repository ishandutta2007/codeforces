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

vi pool1,pool2;
vector<pii> anser;
void merge(vi a) {
	for(int j=1; j<a.size(); j<<=1)
		for(int i=0; i<a.size(); i+=2*j)
			for(int k=0; k<j; k++)
				anser.pb({a[i+k],a[i+j+k]});
}
vi merge(vi a, vi b) {
	vi result=a;
	for(int i=0; i<a.size(); i++) {
		anser.pb({a[i],b[i]});
		result.pb(b[i]);
	}
	return result;
}
vi bits[20];
void solve() {
	int n;
	cin>>n;
	int sbse=0;
	while((1LL<<(sbse+1))<=n)
		sbse++;
	vi ini(n);
	iota(all(ini),1LL);
	trace(ini);
	for(int i=0; i<=sbse; i++)
		if((n>>i)&1)
			for(int j=0; j<(1<<i); j++) {
				bits[i].pb(ini.back());
				ini.pop_back();
			}
	trace(1);
	for(int i=0; i<=sbse; i++) {
		if(bits[i].size())
			merge(bits[i]);
	}
	trace(bits[sbse]);
	vi spare=bits[sbse];
	vi cur={bits[sbse].back()};
	bits[sbse].pop_back();
	for(int i=0; i<sbse; i++) {
		if(bits[i].empty()) {
			for(int j=0; j<(1<<i); j++) {
				bits[i].pb(bits[sbse].back());
				bits[sbse].pop_back();
			}
		}
		cur=merge(cur,bits[i]);
	}
	trace(1);
	cout<<sz(anser)<<endl;
	for(auto i:anser) {
		cout<<i.fi<<" "<<i.se<<endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}