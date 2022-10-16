/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
//#define endl '\n'
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
const ll infl=2e18;
const int infi=1e9;
const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

int up[200005],lef[200005];
void solve() {
	int x1,y1,x2,y2,n;
	string s;
	cin>>x1>>y1>>x2>>y2>>n>>s;
	n=sz(s);
	x2-=x1;
	y2-=y1;
	for(int i=0; i<n; i++) {
		if(s[i]=='R')
			lef[i+1]++;
		else if(s[i]=='L')
			lef[i+1]--;
		if(s[i]=='U')
			up[i+1]++;
		else if(s[i]=='D')
			up[i+1]--;
		lef[i+1]+=lef[i];
		up[i+1]+=up[i];
	}
	int lo=0,hi=1e15,mid=(lo+hi)/2;
	while(lo<hi) {
		int cost=abs(x2-lef[n]*(mid/n)-lef[mid%n])+abs(y2-up[n]*(mid/n)-up[mid%n]);
		trace(cost,mid,up[n],lef[n],lo,hi);
		if(cost<=mid)
			hi=mid;
		else
			lo=mid+1;
		mid=(lo+hi)/2;
	}
	if(mid==1e15) {
		cout<<-1<<endl;
	} else
		cout<<mid<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}