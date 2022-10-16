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


void solve() {
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	vi ans;
	int acl=0,acr=n-1;
	bool rev=0;
	for(int i=n-1; i>0; i--) {
		trace(acl,acr,rev,a[acr]);
		if((rev==0&&a[acr]==b[i])||(rev&&a[acl]!=b[i])) {
			trace(1);
			if(rev)
				acl++;
			else
				acr--;
		} else if((rev==0&&a[acl]!=b[i])||(rev&&a[acr]==b[i])) {
			trace(2);
			rev^=1;
			if(rev)
				acl++;
			else
				acr--;
			ans.pb(i+1);
		} else {
			rev^=1;
			if(rev)
				acl++;
			else
				acr--;
			ans.pb(1);
			ans.pb(i+1);
		}
	}
	if((a[acl]==b[0]&&rev)||(a[acl]!=b[0]&&rev==0))
		ans.pb(1);
	cout<<sz(ans);
	for(auto i:ans)
		cout<<" "<<i;
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