#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
#define forn(i, x, y) for(int i = x; i <= y; i++)
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

void solve() {
	int n,k;
	string s;
	cin>>n>>k>>s;
	vector<pii> ops;
	for(int i=0; i<2*k-2; i++) {
		char tol='(';
		if((i&1))
			tol=')';
		if(s[i]==tol)
			continue;
		else {
			for(int j=i+1; j<n; j++) {
				if(s[j]==tol) {
					ops.pb({i+1,j+1});
					reverse(s.begin()+i,s.begin()+j+1);
					break;
				}
			}
		}
	}
	int rem=(n-2*k+2)/2;
	trace(rem);
	for(int i=2*k-2; i<n; i++,rem--) {
		char tol='(';
		if(rem<=0)
			tol=')';
		if(s[i]==tol)
			continue;
		else {
			for(int j=i+1; j<n; j++) {
				if(s[j]==tol) {
					ops.pb({i+1,j+1});
					reverse(s.begin()+i,s.begin()+j+1);
					break;
				}
			}
		}
	}
	trace(s);
	cout<<sz(ops)<<endl;
	for(auto i:ops) {
		cout<<i.fi<<" "<<i.se<<endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(7);
	int t=1;
	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}