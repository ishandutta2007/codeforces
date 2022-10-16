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

#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
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
const ll infl=1e18;
const int infi=2e9;
const int mod=1e9+7;
#define dpr(x) cout<<#x<<": "<<x<<endl
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim)
{
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

int ho[256];
int lol[4];
int lul[4];
void solve() {
	string s;
	cin>>s;
	lol[1]=lol[2]=lol[3]=0;
	lul[1]=lul[2]=lul[3]=0;
	int n=s.length();
	for(int i=0; i<n; i++) {
		lol[ho[s[i]]]++;
		lul[ho[s[i]]]=1;
	}
	int sum=lul[1]+lul[2]+lul[3];
	if(sum==3) {
		cout<<s<<endl;
	} else if(sum==2) {
		char needed;
		if(!lul[1]) {
			for(int i=0; i<n; i++) {
				if(lol[ho[s[i]]]>1) {
					s[i]='a';
					cout<<s<<endl;
					return;
				}
			}
		} else if(!lul[2]) {
			for(int i=0; i<n; i++) {
				if(lol[ho[s[i]]]>1) {
					s[i]='A';
					cout<<s<<endl;
					return;
				}
			}
		} else {
			for(int i=0; i<n; i++) {
				if(lol[ho[s[i]]]>1) {
					s[i]='1';
					cout<<s<<endl;
					return;
				}
			}
		}
	} else {
		if(lul[1]) {
			cout<<"A1"<<s.substr(2, n-2)<<endl;
		} else if(lul[2]) {
			cout<<"a1"<<s.substr(2, n-2)<<endl;
		} else {
			cout<<"Aa"<<s.substr(2, n-2)<<endl;
		}
	}

}
signed main() {
	for(int i='a'; i<='z'; i++)
		ho[i]=1;
	for(int i='A'; i<='Z'; i++)
		ho[i]=2;
	for(int i='0'; i<='9'; i++)
		ho[i]=3;
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}
/**/