#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
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

int a[400005],edor[400005];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n) {
		cin>>a[i];
		a[n+i]=a[i];
		a[2*n+i]=a[i];
		a[3*n+i]=a[i];
	}
	int mi=*min_element(a+1, a+n+1),ma=*max_element(a+1, a+n+1);
	if(ma<=2*mi) {
		fr(i,1,n)
			cout<<-1<<" ";
		return;
	}
	vi lol;
	for(int i=4*n; i>2*n; i--) {
		while((!lol.empty())&&a[lol.back()]>=a[i])
			lol.pop_back();
		lol.pb(i);
	}
	edor[3*n+1]=4*n;
	for(int i=3*n; i>0; i--) {
		int lo=0,hi=sz(lol)-1,mid=(lo+hi+1)/2;
		int req=(a[i]-1)/2;
		if(a[lol[0]]<=req) {
			while(lo<hi) {
				if(a[lol[mid]]<=req)
					lo=mid;
				else
					hi=mid-1;
				mid=(lo+hi+1)/2;
			}
			edor[i]=min(edor[i+1],lol[mid]);
		} else
			edor[i]=edor[i+1];
		while((!lol.empty())&&a[lol.back()]>=a[i])
			lol.pop_back();
		lol.pb(i);
	}
	fr(i,1,n) {
		cout<<edor[i]-i<<" ";
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	fr(i, 1, t)
	{
//		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}