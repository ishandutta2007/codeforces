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
typedef float f80;
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

int p[200005];
void solve() {
	int n,x,a,y,b,k;
	cin>>n;
	fr(i,1,n)
		cin>>p[i];
	p[n+1]=0;
	sort(p+1,p+n+1);
	reverse(p+1,p+n+1);
	cin>>x>>a>>y>>b>>k;
	if(x<y) {
		swap(x,y);
		swap(a,b);
	}
	int lo=1,hi=n+1,mid=(lo+hi)/2;
	while(lo<hi) {
		int com=mid/lcm(a,b);
		int as=mid/a-com,bs=mid/b-com;
		int i=1,val=0;
		for(; i<=com; i++)
			val+=p[i]*(x+y);
		for(int j=0; j<as; j++,i++)
			val+=p[i]*x;
		for(int j=0; j<bs; j++,i++)
			val+=p[i]*y;
		if(val>=k*100) {
			hi=mid;
		} else
			lo=mid+1;
		mid=(lo+hi)/2;
	}
	if(mid>n) {
		cout<<-1<<endl;
	} else
		cout<<mid<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
	cin>>t;
	fr(i,1,t) {
//		cout<<"Case "<<i<<": ";
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}