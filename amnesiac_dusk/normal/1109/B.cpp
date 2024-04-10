#pragma GCC optimze("Ofast")
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
const int mod=998244353;
//const int mod=1000000007;
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

bool ispal(const string &s) {
	for(int i=0; i<sz(s)/2; i++)
		if(s[i]!=s[sz(s)-i-1])
			return 0;
	return 1;
}
void solve() {
	string s;
	cin>>s;
	set<char> a;
	for(int i=0; i<sz(s)/2; i++)
		a.insert(s[i]);
	if(sz(a)<=1) {
		cout<<"Impossible"<<endl;
		return;
	}
	string t=s;
	for(int i=0; i<sz(s); i++) {
		rotate(t.begin(),t.begin()+1,t.end());
		if(ispal(t)&&s!=t) {
			cout<<1<<endl;
			return;
		}
	}
//	for(int i=1; i<sz(s); i++) {
//		for(int j=1; i+j<sz(s); j++) {
//			vector<string> lol={s.substr(0, i),s.substr(i, j),s.substr(i+j)};
//			sort(all(lol));
//			do {
//				string temp=lol[0]+lol[1]+lol[2];
//				if(s!=temp&&ispal(temp)) {
//					trace(temp);
//					return;
//				}
//			} while(next_permutation(all(lol)));
//		}
//	}
	cout<<2<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}