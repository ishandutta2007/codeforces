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
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}


unsigned int ha1[200005],ha2[200005];
unsigned int lols[200005];
int acti1[200005];
int acti2[200005];
pii soa[100005],sob[100005];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n)
		lols[i]=rang();
	vi coa,cob;
	fr(i,1,n) {
		int sa,ea,sb,eb;
		cin>>sa>>ea>>sb>>eb;
		sa=2*sa;
		ea=2*ea+1;
		sb=2*sb;
		eb=2*eb+1;
		soa[i]={sa,ea};
		sob[i]={sb,eb};
		coa.pb(sa);
		coa.pb(ea);
		cob.pb(sb);
		cob.pb(eb);
	}
	sort(all(coa));
	sort(all(cob));
	coa.resize(unique(all(coa))-coa.begin());
	cob.resize(unique(all(cob))-cob.begin());
	vi one,two;
	fr(i,1,n) {
		soa[i].fi=upper_bound(all(coa),soa[i].fi)-coa.begin();
		soa[i].se=upper_bound(all(coa),soa[i].se)-coa.begin();
		sob[i].fi=upper_bound(all(cob),sob[i].fi)-cob.begin();
		sob[i].se=upper_bound(all(cob),sob[i].se)-cob.begin();
		ha1[soa[i].fi]^=lols[i];
		acti1[soa[i].fi]=1;
		ha1[soa[i].se+1]^=lols[i];
		ha2[sob[i].fi]^=lols[i];
		acti2[sob[i].fi]=1;
		ha2[sob[i].se+1]^=lols[i];
	}
	fr(i,1,sz(coa)) {
		ha1[i]^=ha1[i-1];
	}
	fr(i,1,sz(cob)) {
		ha2[i]^=ha2[i-1];
	}
	bool ac=0;
	fr(i,1,sz(coa)) {
		if(acti1[i]) {
			ac=1;
		} else if(ac) {
			ac=0;
			one.pb(ha1[i]);
		}
	}
	ac=0;
	fr(i,1,sz(cob)) {
		if(acti2[i]) {
			ac=1;
		} else if(ac) {
			ac=0;
			two.pb(ha2[i]);
		}
	}
	sort(all(one));
	sort(all(two));
	if(one==two) {
		cout<<"YES"<<endl;
	} else
		cout<<"NO"<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
}