#pragma GCC optimze("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef rd
#define trace(...)
//#define endl '\n'
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

int a[150005];
int n;
bool check(int i) {
	if(i&1) {
		if((i+1<=n&&a[i]>=a[i+1])||(i>1&&a[i]>=a[i-1]))
			return 1;
	} else
		if((i+1<=n&&a[i]<=a[i+1])||(i>1&&a[i]<=a[i-1]))
			return 1;
	return 0;
}
void solve() {
	cin>>n;
	fr(i,1,n)
		cin>>a[i];
	vi susc;
	fr(i,1,n)
		if(check(i))
			susc.pb(i);
	if(sz(susc)>6) {
		cout<<0<<endl;
		return;
	}
	set<pii> ans;
	for(int ii=0; ii<sz(susc); ii++) {
		int i=susc[ii];
		fr(j,1,n) {
			susc.pb(j);
			swap(a[i],a[j]);
			bool no=0;
			for(int k:susc)
				if(check(k)) {
					no=1;
					break;
				}
			swap(a[i],a[j]);
			if(no==0)
				ans.insert({min(i,j),max(i,j)});
			susc.pop_back();
		}
	}
	trace(ans);
	cout<<sz(ans)<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}