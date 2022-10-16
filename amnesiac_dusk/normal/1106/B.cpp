/*
 * 	Yet I'm feeling like
 * 		There is no better place than right by your side
 * 			I had a little taste
 * 				And I'll only spoil the party anyway
 * 					'Cause all the girls are looking fine
 * 						But you're the only one on my mind
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
typedef long long ll;
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll inf=1e18;
const int mod=1e9+7;
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll a[100005][2];
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<pii> aa;
	int ptr=0;
	ll sum=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i][0];
	}
	for(int i=1; i<=n; i++) {
		cin>>a[i][1];
	}
	for(int i=1; i<=n; i++) {
		sum+=a[i][0];
		aa.pb({a[i][1],i});
	}
	sort(all(aa));
	int tj,dj;
	for(int i=1; i<=m; i++) {
//		deb<<"ho"<<endl;
		cin>>tj>>dj;
		if(sum<dj) {
			cout<<0<<endl;
			sum=0;
		}
		else if(a[tj][0]>=dj) {
			cout<<a[tj][1]*dj<<endl;
			a[tj][0]-=dj;
			sum-=dj;
		} else {
//			deb<<endl;
			sum-=dj;
			ll cost=0;
			dj-=a[tj][0];
			cost+=a[tj][1]*a[tj][0];
			a[tj][0]=0;
			while(dj>0) {
				if(dj<=a[aa[ptr].se][0]) {
					cost+=dj*a[aa[ptr].se][1];
					a[aa[ptr].se][0]-=dj;
					dj=0;
				} else {
					dj-=a[aa[ptr].se][0];
					cost+=a[aa[ptr].se][0]*a[aa[ptr].se][1];
					a[aa[ptr].se][0]=0;
					ptr++;
				}
			}
			cout<<cost<<endl;
		}
	}

}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
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