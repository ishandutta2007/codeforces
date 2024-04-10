#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
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
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(int a, int b, int mod) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}



int pref[500005];
int holve(string s, int a, int b, int t) {
	trace(s);
	for(int i=2; i<=sz(s); i++) {
		pref[i]=pref[i-1]+a+1;
		if(s[i-1]=='w')
			pref[i]+=b;
	}
	if(s[0]=='w') {
		t-=b;
	}
	t--;
	if(t<0) {
		cout<<0<<endl;
		exit(0);
	}
	int ans=1;
	int cost=0;
	for(int i=1; i<sz(s); i++) {
		if(s[sz(s)-i]=='w')
			cost+=b;
		cost+=a+1;
		if(cost<=t)
			ans++;
		else
			break;
	}
	trace(ans);
	cost=0;
	for(int i=1; i<sz(s); i++) {
		if(s[sz(s)-i]=='w')
			cost+=b;
		cost+=2*a+1;
		trace(cost,t,ans);
		if(cost<=t) {
			auto it=upper_bound(pref+1,pref+sz(s)+1,t-cost)-pref-2;
			trace(it);
			ans=max(ans,it+i+1);
		}
		else
			break;
	}
	return ans;
}
void solve() {
	int n,a,b,t;
	cin>>n>>a>>b>>t;
	string s;
	cin>>s;
	int ans=holve(s,a,b,t);
	reverse(s.begin()+1,s.end());
	ans=max(ans,holve(s,a,b,t));
	cout<<min(n,ans)<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(20);
	int t=1;
//	cin>>t;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}