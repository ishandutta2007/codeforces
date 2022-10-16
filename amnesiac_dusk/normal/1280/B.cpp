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

char a[61][61];
void solve() {
	int n,m;
	cin>>n>>m;
	bool poss=0,nol=0;
	fr(i,1,n)
		fr(j,1,m) {
			cin>>a[i][j];
			if(a[i][j]=='A')
				poss=1;
			else
				nol=1;
		}
	if(poss==0) {
		cout<<"MORTAL"<<endl;
		return;
	} else if(nol==0) {
		cout<<0<<endl;
		return;
	}
	int ans=4;
	if(a[1][1]=='A'||a[n][m]=='A'||a[1][m]=='A'||a[n][1]=='A')
		ans=min(ans,2LL);
	bool oo=1,poo=1,gool=0;
	fr(i,1,n) {
		if(a[i][1]=='P')
			oo=0;
		if(a[i][m]=='P')
			poo=0;
		if(a[i][1]=='A'||a[i][m]=='A')
			gool=1;
	}
	if(oo||poo)
		ans=min(ans,1LL);
	oo=1,poo=1;
	fr(i,1,m) {
		if(a[1][i]=='P')
			oo=0;
		if(a[n][i]=='P')
			poo=0;
		if(a[1][i]=='A'||a[n][i]=='A')
			gool=1;
	}
	if(gool)
		ans=min(ans,3LL);
	if(oo||poo)
		ans=min(ans,1LL);
	fr(i,1,n) {
		bool lool=1;
		fr(j,1,m) {
			if(a[i][j]=='P')
				lool=0;
		}
		if(lool)
			ans=min(ans,2LL);
	}
	fr(i,1,m) {
		bool lool=1;
		fr(j,1,n) {
			if(a[j][i]=='P')
				lool=0;
		}
		if(lool)
			ans=min(ans,2LL);
	}
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t;
	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}