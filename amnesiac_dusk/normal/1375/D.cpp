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


int a[1005];
int n;
int mex() {
	vi lol;
	fr(i,1,n)
		lol.pb(a[i]);
	sort(all(lol));
	lol.resize(unique(all(lol))-lol.begin());
	rep(i,0,sz(lol))
		if(lol[i]!=i)
			return i;
	return sz(lol);
}
void solve() {
	cin>>n;
	fr(i,1,n)
		cin>>a[i];
	vi ans;
	fr(i,1,2*n) {
		bool brok=1;
		rep(i,1,n)
			if(a[i]>a[i+1])
				brok=0;
		if(brok)
			break;
		int mix=mex();
		if(mix==n) {
			int thisone=0;
			fr(j,1,n)
				if(a[j]!=j-1) {
					thisone=j;
					break;
				}
			ans.pb(thisone);
			a[thisone]=mix;
		} else {
			a[mix+1]=mix;
			ans.pb(mix+1);
		}
	}
	cout<<sz(ans)<<endl;
	for(int i:ans)
		cout<<i<<" ";
	cout<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}