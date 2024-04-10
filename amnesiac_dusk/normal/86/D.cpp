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

ll a[200005];
ll anses[200005];
const int bs=450;
int f[1000005];
void solve()
{
	int n,q;
	cin>>n>>q;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	int l,r;
	vector<pair<int,pii>> hol;
	for(int i=1; i<=q; i++) {
		cin>>l>>r;
		hol.pb({i,{l,r}});
	}
	sort(all(hol),[](auto &a,auto &b) -> bool{
		if(a.se.fi/bs!=b.se.fi/bs)
			return a.se.fi<b.se.fi;
		return ((a.se.fi/bs)&1) ? a.se.se<b.se.se :a.se.se>b.se.se;
	});
	l=1;
	r=0;
	ll curans=0;
	for(auto &qu: hol) {
		while(l<qu.se.fi) {
			curans-=a[l]*f[a[l]]*f[a[l]];
			f[a[l]]--;
			curans+=a[l]*f[a[l]]*f[a[l]];
			l++;
		}
		while(l>qu.se.fi) {
			l--;
			curans-=a[l]*f[a[l]]*f[a[l]];
			f[a[l]]++;
			curans+=a[l]*f[a[l]]*f[a[l]];
		}
		while(r>qu.se.se) {
			curans-=a[r]*f[a[r]]*f[a[r]];
			f[a[r]]--;
			curans+=a[r]*f[a[r]]*f[a[r]];
			r--;
		}
		while(r<qu.se.se) {
			r++;
			curans-=a[r]*f[a[r]]*f[a[r]];
			f[a[r]]++;
			curans+=a[r]*f[a[r]]*f[a[r]];
		}
		anses[qu.fi]=curans;
	}
	for(int i=1; i<=q; i++)
		cout<<anses[i]<<endl;
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