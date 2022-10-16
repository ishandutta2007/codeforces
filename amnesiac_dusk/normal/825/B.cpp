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
//#define int long long
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
string a[10];
bool win() {
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j < 10; j++) {
			bool v = 1;
			for (int k = 0; k < 5; k++) {
				if (a[i + k][j] != 'X')
					v = 0;
			}
			if (v)
				return 1;
		}
	}
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j < 10; j++) {
			bool v = 1;
			for (int k = 0; k < 5; k++) {
				if (a[j][i + k] != 'X')
					v = 0;
			}
			if (v)
				return 1;
		}
	}
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= 5; j++) {
			bool v = 1;
			for (int k = 0; k < 5; k++) {
				if (a[j+k][i+k]!='X')
					v = 0;
			}
			if (v)
				return 1;
		}
	}
	for (int i = 0; i <= 5; i++) {
		for (int j = 4; j <10; j++) {
			bool v = 1;
			for (int k = 0; k < 5; k++) {
				if (a[j-k][i+k]!='X')
					v = 0;
			}
			if (v)
				return 1;
		}
	}
	return 0;
}
void solve() {
	fr(i,0,9)
		cin >> a[i];
	for(int i=0; i<10; i++)
		for(int j=0; j<10; j++) {
			if(a[i][j]=='.') {
				a[i][j]='X';
				if(win()) {
					cout<<"YES"<<endl;
					return;
				}
				a[i][j]='.';
			}
		}
	cout<<"NO"<<endl;
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