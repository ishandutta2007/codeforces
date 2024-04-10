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


map<int,int> hol;
void solve() {
	int n;
	cin>>n;
	fr(i,1,n) {
		int te;
		cin>>te;
		hol[te]++;
	}
	vector<pii> lol,next;
	for(auto i:hol)
		lol.pb(i);
	pii anser={0,0};
	int cntr=0;
	fr(i,1,n) {
		while(lol.size()) {
			cntr++;
			if(lol.back().se>1)
				next.pb({lol.back().fi,lol.back().se-1});
			lol.pop_back();
		}
		swap(next,lol);
		if(cntr/i<i)
			break;
		if(anser.fi*anser.se<(cntr/i)*i) {
			anser.fi=cntr/i;
			anser.se=i;
		}
	}
	cout<<anser.fi*anser.se<<endl;
	cout<<anser.fi<<" "<<anser.se<<endl;
	vi fin;
	vector<pii> tolol;
	for(auto i:hol) {
		tolol.pb(i);
	}
	sort(all(tolol),[](auto i,auto j){
		return i.se<j.se;
	});
	for(auto i:tolol)
		for(int j=0; j<anser.se&&j<i.se; j++)
			fin.pb(i.fi);
	vector<pair<pii,int>> order;
	for(int i=1; i<=anser.fi; i++)
		for(int j=1; j<=anser.se; j++) {
			order.pb({{(i+j-2)%anser.fi+1,j},fin.back()});
			fin.pop_back();
		}
	sort(all(order));
	int looll=0;
	for(int i=0; i<anser.fi; i++) {
		for(int j=0; j<anser.se; j++) {
			cout<<order[looll++].se<<" ";
			order.pop_back();
		}
		cout<<endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}