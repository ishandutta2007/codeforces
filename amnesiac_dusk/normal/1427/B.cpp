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


int a[55];
void solve() {
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int w=0;
	vi pols;
	int te=0,la=0;
	int ans=0;
	for(int i=0; i<sz(s); i++) {
		if(s[i]=='W') {
			ans+=la+1;
			w++;
			la=1;
			if(pols.empty()) {
				pols.pb(0);
			} else
				pols.pb(te);
			te=0;
		} else {
			la=0;
			te++;
		}
	}
	if(w==0) {
		cout<<max(2*k-1,0LL)<<endl;
		return;
	}
	if(k+w>=n) {
		cout<<2*n-1<<endl;
		return;
	}
	sort(all(pols));
	reverse(all(pols));
	while(pols.size()&&k>0) {
		if(pols.back()==0) {
		} else if(pols.back()<=k) {
			ans+=2*pols.back()+1;
			k-=pols.back();
		} else {
			break;
		}
		pols.pop_back();
	}
	ans+=2*k;
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}