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



vi a[16];
int sus[16];
bool dp[1<<15];
vector<pair<int,pii>> dper[1<<15];
map<int,int> anti;
set<int> done;
void solve() {
	int n;
	cin>>n;
	int sum=0;
	rep(i,0,n) {
		int te,tel;
		cin>>te;
		rep(j,0,te) {
			cin>>tel;
			a[i].pb(tel);
			anti[tel]=i;
			sum+=tel;
			sus[i]+=tel;
		}
	}
	if(sum%n) {
		cout<<"No"<<endl;
		return;
	}
	sum/=n;
	rep(i,0,n) {
		for(int j:a[i]) {
			int usedh=1<<i;
			int remo=sum-sus[i]+j;
			bool vald=1;
			vector<pair<int,pii>> holol={{0,{remo,i}}};
			while(remo!=j&&vald) {
				if(anti.find(remo)!=anti.end()) {
					int lol=anti[remo];
					if((usedh&(1<<lol))==0) {
						usedh|=(1<<lol);
						remo=sum-sus[lol]+remo;
						holol.back().fi=lol;
						holol.pb({0,{remo,lol}});
					} else
						vald=0;
				} else
					vald=0;
			}
			holol.back().fi=i;
			if(vald) {
				if(dp[usedh]==0) {
					dp[usedh]=1;
					dper[usedh]=holol;
				}
			}
		}
	}
	dp[0]=1;
	for(int i=0; i<(1<<n); i++) {
		for(int j=i; j&&dp[i]==0; j=(j-1)&i) {
			if((dp[j]&dp[i-j])) {
				dp[i]|=(dp[j]&dp[i-j]);
				for(auto k:dper[j])
					dper[i].pb(k);
				for(auto k:dper[i-j])
					dper[i].pb(k);
			}
		}
	}
	if(dp[(1<<n)-1]) {
		sort(all(dper[(1<<n)-1]));
		cout<<"Yes"<<endl;
		for(auto i:dper[(1<<n)-1]) {
			cout<<i.se.fi<<" "<<i.se.se+1<<endl;
		}
	} else {
		cout<<"No"<<endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(5);
	int t=1;
//	cin>>t;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}