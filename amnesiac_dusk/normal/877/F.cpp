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
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef gp_hash_table<long long, long long> umap;
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

ll a[100005],p[100005];
ll anses[100005];
const int bs=300;
int co[100005][3];
ll f[300005];
void solve()
{
	int n,k;
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		cin>>p[i];
	vector<ll> indi;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(p[i]==2) a[i]*=-1;
		p[i]=p[i-1]+a[i];
		indi.pb(p[i]);
		indi.pb(p[i]-k);
		indi.pb(p[i]+k);
	}
	indi.pb(0);
	indi.pb(-k);
	indi.pb(k);
	sort(all(indi));
	unique(all(indi));
	umap vals;
	for(int i=0; i<indi.size(); i++) {
		vals[indi[i]]=i+1;
	}
	for(int i=0; i<=n; i++) {
		co[i][0]=vals[p[i]];
		co[i][1]=vals[p[i]-k];
		co[i][2]=vals[p[i]+k];
	}
	int q,l,r;
	cin>>q;
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
		while(l+1<qu.se.fi) {
			f[co[l][0]]--;
			curans-=f[co[l][2]];
			l++;
		}
		while(l>=qu.se.fi) {
			l--;
			curans+=f[co[l][2]];
			f[co[l][0]]++;
		}
		while(r>qu.se.se) {
			f[co[r][0]]--;
			curans-=f[co[r][1]];
			r--;
		}
		while(r<qu.se.se) {
			r++;
			curans+=f[co[r][1]];
			f[co[r][0]]++;
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