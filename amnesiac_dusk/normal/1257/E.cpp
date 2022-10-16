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

int who[200005];
int win[200005];
void solve() {
	int k1,k2,k3;
	cin>>k1>>k2>>k3;
	fr(i,1,k1) {
		int te;
		cin>>te;
		who[te]=1;
	}
	fr(i,1,k2) {
		int te;
		cin>>te;
		who[te]=2;
	}
	fr(i,1,k3) {
		int te;
		cin>>te;
		who[te]=3;
	}
	int n=k1+k2+k3;
	int t3=0,t2=0;
	win[n+1]=k3;
	for(int i=n; i>0; i--) {
		if(who[i]==2)
			t2++;
		else if(who[i]==3)
			t3++;
		win[i]=min(win[i+1],k3-t3+t2);
	}
	int ans=n;
	t2=0;
	t3=0;
	fr(i,0,n) {
		if(who[i]==2)
			t2++;
		else if(who[i]==1)
			t3++;
		ans=min(ans,win[i+1]+k1-t3+t2);
	}
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}