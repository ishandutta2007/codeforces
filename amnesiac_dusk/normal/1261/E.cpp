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
bool yes[1005][1005];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n) {
		cin>>a[i];
	}
	vector<vector<vi>> lol;
	vi temp;
	fr(i,1,n+1)
		temp.pb(i);
	lol.pb({temp});
	fr(i,1,n) {
		lol.pb(vector<vi>());
		trace(i);
		int top=0;
		for(int j=0; j<sz(lol[i-1]); j++)
			if(sz(lol[i-1][j])>1)
				top=j;
		for(int j=0; j<sz(lol[i-1]); j++) {
			if(j!=top)
				lol[i].pb(lol[i-1][j]);
		}
		{
			vi tolol,holol;
			for(int j=0; j<sz(lol[i-1][top]); j++) {
				if(a[i]>0&&j) {
					yes[i][lol[i-1][top][j]]=1;
					tolol.pb(lol[i-1][top][j]);
					a[i]--;
				} else {
					holol.pb(lol[i-1][top][j]);
				}
			}
			lol[i].pb(tolol);
			lol[i].pb(holol);
		}
		for(int j=0; j+2<sz(lol[i])&&a[i]>0; j++) {
			for(int k=0; k<sz(lol[i][j])&&a[i]>0; k++) {
				yes[i][lol[i][j][k]]=1;
				a[i]--;
			}
		}
		lol[i-1].clear();
	}
	cout<<n+1<<endl;
	fr(i,1,n+1) {
		fr(j,1,n) {
			cout<<yes[j][i];
		}
		cout<<endl;
	}


}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(7);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}