/*
 * 	In an empty-like sky
 * 		What were you looking at?
 * 			I did not even understand
 * 				The reason I woke up
 * 	I was terribly scared
 * 		Of believing
 * 			Because of that
 * 				I've thrown everything away
 * 	It would have been better
 * 		If this world that I hate so much
 * 			Could just disappear
 * 				If I continue to believe
 * 					Won't it hurt me?
 *
 * 	It was your voice
 * 		That has saved me
 * 			And keeps me going
 * 				The feeling that you taught me
 * 					That's true.
 * 	I will scream your name
 * 		Strongly hold your hand
 * 			I will not let go of it anymore
 * 				No matter what the future holds
 * 					If you're with me, I won't run away
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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

int a[1000005];
int pea[1000005],poa[1000005];
void solve() {
	int n;
	cin>>n;
	stack<pii> lol;
	lol.push({1e6+5,0});
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		while(lol.top().fi<=a[i]) {
			lol.pop();
		}
		pea[i]=i-lol.top().se;
		lol.push({a[i],i});
	}
	while(!lol.empty())
		lol.pop();
	lol.push({1e6+5,n+1});
	for(int i=n; i>0; i--) {
		while(lol.top().fi<a[i]) {
			lol.pop();
		}
		pea[i]*=(lol.top().se-i);
		lol.push({a[i],i});
	}
	while(!lol.empty())
		lol.pop();
	lol.push({0,0});
	for(int i=1; i<=n; i++) {
		while(lol.top().fi>=a[i]) {
			lol.pop();
		}
		poa[i]=i-lol.top().se;
		lol.push({a[i],i});
	}
	while(!lol.empty())
		lol.pop();
	lol.push({0,n+1});
	for(int i=n; i>0; i--) {
		while(lol.top().fi>a[i]) {
			lol.pop();
		}
		poa[i]*=(lol.top().se-i);
		lol.push({a[i],i});
	}
	for(int i=1; i<=n; i++)
		ans+=(pea[i]-poa[i])*a[i];
	cout<<ans<<endl;
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