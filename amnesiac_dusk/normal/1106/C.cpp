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

string a[505];
int d[5][2]={{0,0},{-1,-1},{-1,1},{1,1},{1,-1}};
void solve()
{
	int n,te;
	cin>>n;
	vector<int> a;
	for(int i=0; i<n; i++)
		cin>>te,a.pb(te);
	sort(all(a));
	ll ans=0;
	for(int i=0; i*2<n; i++) {
		ans+=(a[i]+a[n-i-1])*(a[i]+a[n-i-1]);
	}
	cout<<ans<<endl;
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