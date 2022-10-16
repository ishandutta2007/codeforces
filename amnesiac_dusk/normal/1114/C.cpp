/*
 * 	Meet me on the battlefield
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const int inf=1e18;
const int mod=1e9+7;
#define dpr(x) cout<<#x<<": "<<x<<endl
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
	int n,b;
	cin>>n>>b;
	vector<pll> facs;
	for(int i=2; i*i<=b; i++) {
		if(b%i==0) {
			int ct=0;
			while(b%i==0) {
				ct++;
				b/=i;
			}
			facs.pb({i,ct});
		}
	}
	if(b!=1) {
		facs.pb({b,1});
	}
	ll ans=inf;
	for(auto &f:facs) {
		int temo=0;
		int lul=f.fi;
		double lol=f.fi;
		while(lol<=2e18) {
			temo+=n/lul;
			lul*=f.fi;
			lol*=f.fi;
		}
		ans=min(ans,temo/f.se);
	}
	cout<<ans<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	int t=1;
	auto clk=clock();
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}
/**/