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

map<string,int> lol;
string s[70005];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n) {
		cin>>s[i];
		set<string> here;
		for(int j=0; j<sz(s[i]); j++) {
			for(int k=1; k+j<=sz(s[i]); k++) {
				if(here.find(s[i].substr(j,k))==here.end()) {
					here.insert(s[i].substr(j,k));
				} else
					continue;
				if(lol.find(s[i].substr(j, k))==lol.end()) {
					lol[s[i].substr(j, k)]=0;
				} else
					lol[s[i].substr(j, k)]=1;
			}
		}
	}
	fr(i,1,n) {
		string ans="9999999999";
		for(int j=0; j<sz(s[i]); j++) {
			for(int k=1; k+j<=sz(s[i])&&k<sz(ans); k++) {
				if(lol[s[i].substr(j, k)]==0) {
					ans=s[i].substr(j,k);
				}
			}
		}
		cout<<ans<<endl;
	}
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