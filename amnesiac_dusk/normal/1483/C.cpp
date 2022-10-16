#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
//#define double long double
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const int infi=0x3f3f3f3f;
const ll infl=0x3f3f3f3f3f3f3f3fLL;
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

int h[300005];
int b[300005];
pii tr[600005];
int n;
pii query(int l, int r) {
	l--;
	pii res={infl,infl};
	for(l+=n,r+=n; l<r; l>>=1,r>>=1) {
		if(l&1) res=min(res,tr[l++]);
		if(r&1) res=min(res,tr[--r]);
	}
	return res;
}
int go(int l, int r,bool le, bool ri) {
	if(l>r)
		return 0;
	pii mini=query(l,r);
	int left=max(0LL,go(l,mini.se-1,le,ri|1));
	int right=max(0LL,go(mini.se+1,r,le|1,ri));
	int fans=b[mini.se]+left+right;
	if(le)
		fans=max(fans,right);
	if(ri)
		fans=max(fans,left);
	return fans;
}
void solve() {
	cin>>n;
	fr(i,1,n)
		cin>>h[i];
	fr(i,1,n) {
		cin>>b[i];
		tr[i+n-1]={h[i],i};
	}
	for(int i=n-1; i>0; i--)
		tr[i]=min(tr[i<<1],tr[i<<1|1]);
	cout<<go(1,n,0,0)<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
}