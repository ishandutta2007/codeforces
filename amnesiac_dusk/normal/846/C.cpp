#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define double long double
//typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int pre[5005],a[5005],pre2[5005];
pii solve(int l, int r) {
	fill(pre,pre+5001,0);
	fill(pre2,pre2+5001,0);
	for(int i=l; i<r; i++) {
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=r-1; i>=l; i--)
		pre2[i]=pre2[i+1]-a[i];
	int an=pre2[l];
	int ind=l;
	for(int i=l; i<r; i++) {
		if(an<pre[i]+pre2[i+1])
			ind=i+1;
		an=max(an,pre[i]+pre2[i+1]);
	}
	return {an,ind};
}
void solve() {
	int n;
	cin>>n;
	fr(i,0,n-1)
		cin>>a[i];
	int ans=0;
	int tol[3];
	for(int i=0; i<n; i++) {
		pii lol1=solve(0,i);
		pii lol2=solve(i,n);
		if(lol1.fi+lol2.fi>=ans) {
			ans=lol1.fi+lol2.fi;
			tol[0]=lol1.se;
			tol[1]=i;
			tol[2]=lol2.se;
		}
	}
	cout<<tol[0]<<" "<<tol[1]<<" "<<tol[2]<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cerr<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}