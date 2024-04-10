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
//#define int long long
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

const int mod=998244353;
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

int a[100005];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n)
		cin>>a[i];
	set<int> ins;
	set<int> lol;
	int last=1;
	vector<pii> anser;
	fr(i,1,n) {
		if(a[i]<0) {
			if(ins.find(-a[i])!=ins.end()) {
				ins.erase(-a[i]);
			} else {
				cout<<-1<<endl;
				return;
			}
		} else if(lol.find(a[i])!=lol.end()) {
			cout<<-1<<endl;
			return;
		} else {
			ins.insert(a[i]);
			lol.insert(a[i]);
		}
		if(ins.empty()) {
			anser.pb({last,i});
			last=i+1;
			lol.clear();
		}
	}
	if(last!=n+1) {
		cout<<-1<<endl;
	} else {
		cout<<sz(anser)<<endl;
		for(auto i:anser) {
			cout<<i.se-i.fi+1<<endl;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
	{
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}