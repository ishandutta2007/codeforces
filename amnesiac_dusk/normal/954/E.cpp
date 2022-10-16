/*
 * 	Meet me on the battlefield
 * 		Even on the darkest night
 * 			I will be your sword and shield,
 * 				Your camouflage and you will be mine
 * 	Echoes of the shots ring out
 * 		We may be the first to fall
 * 			Everything could stay the same
 * 				Or we could change it all
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
//#define int long long
typedef long long ll;
#define double long double
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const int inf=1e9;
const int mod=1e9+7;
#define dpr(x) cout<<#x<<": "<<x<<endl
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N=200005;
int a[N],t[N];
vector<pair<double,double>> hot,cold;
void solve() {
	int n,T;
	cin>>n>>T;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=n; i++)
		cin>>t[i];
	double ans=0;
	for(int i=1; i<=n; i++) {
		if(t[i]>T) {
			hot.pb({t[i]-T,a[i]});
		} else if(t[i]<T){
			cold.pb({T-t[i],a[i]});
		} else
			ans+=a[i];
	}
	sort(all(hot));
	sort(all(cold));
	for(int i=0,j=0; i<sz(hot)&&j<sz(cold); ) {
		if(hot[i].fi*hot[i].se>cold[j].fi*cold[j].se) {
			ans+=cold[j].se+(cold[j].fi*cold[j].se)/hot[i].fi;
			hot[i].se-=(cold[j].fi*cold[j].se)/hot[i].fi;
			j++;
		} else {
			ans+=hot[i].se+(hot[i].fi*hot[i].se)/cold[j].fi;
			cold[j].se-=(hot[i].fi*hot[i].se)/cold[j].fi;
			i++;
		}
	}
	cout<<ans<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cout<<fixed<<setprecision(10);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	auto clk=clock();
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}
/**/