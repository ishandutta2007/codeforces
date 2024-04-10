/*
 * 	i could never find the right way to tell you
 * 		have you noticed i've been gone?
 * 			cause i left behind the home that you made me
 * 				but i will carry it along
 * 	mm it's a long way forward
 * 		so trust in me
 * 			i'll give them shelter like you've done for me
 * 				and i know i'm not alone
 * 					you'll be watching over us
 * 						until you're gone
 * 	when i'm older i'll be silent beside you
 * 		I know that words are not enough
 * 			and they won't need to know our names or our faces
 * 				but they will carry on for us
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
	cout << name << " : " << arg1 << endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
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
const ll infl = 1e18;
const int infi = 2e9;
const int mod = 1e9 + 7;
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk = clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0, lim - 1);
	return uid(rang);
}
const int N=1e5+5;
vi gra[N];
int anses[N];
int oud[N];
void solve() {
	int n,m,u,v;
	cin>>n>>m;
	for(int i=0; i<m; i++) {
		cin>>u>>v;
		gra[v].pb(u);
		oud[u]++;
	}
	priority_queue<int> hol;
	fr(i,1,n)
		if(oud[i]==0)
			hol.push(i);
	int tola=n;
	while(!hol.empty()) {
		int tem=hol.top();
		hol.pop();
		anses[tem]=tola;
		tola--;
		for(int i:gra[tem]) {
			oud[i]--;
			if(oud[i]==0)
				hol.push(i);
		}
	}
	for(int i=1; i<=n; i++)
		cout<<anses[i]<<" ";
}
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t = 1;
//	cin>>t;
	while (t--)
		solve();
#ifdef rd
//	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}