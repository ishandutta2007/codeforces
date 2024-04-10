#pragma GCC optimze("Ofast")
#include <bits/stdc++.h>
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
// const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;


typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
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


int num[100005];
int dp[256];
void solve() {
	int n,m,k;
	cin>>n>>m>>k;
	vector<pii> star;
	vector<pii> endr;
	fr(i,1,n) {
		int l,r;
		cin>>l>>r;
		star.pb({l,i});
		endr.pb({r+1,i});
	}
	sort(all(star));
	sort(all(endr));
	vi avl(8);
	iota(all(avl),0);
	reverse(all(avl));
	int last=1;
	for(int i=0,j=0; i<sz(star)||j<sz(endr); ) {
		if(i!=sz(star)&&star[i].fi<endr[j].fi) {
			num[star[i].se]=avl.back();
			avl.pop_back();
			for(int k=0; k<256; k++)
				if(__builtin_popcount(k)&1)
					dp[k]+=star[i].fi-last;
			for(int k=0; k<256; k++)
				if((k>>num[star[i].se])&1)
					dp[k]=dp[k^(1<<num[star[i].se])];
			last=star[i].fi;
			i++;
		} else {
			avl.pb(num[endr[j].se]);
			for(int k=0; k<256; k++)
				if(__builtin_popcount(k)&1)
					dp[k]+=endr[j].fi-last;
//			if(i==sz(star)) {
//				trace(j,last);
//				rep(i,0,8) {
//					cout<<dp[i]<<" ";
//				}
//				cout<<endl;
//			}
			for(int k=0; k<256; k++)
				if(((k>>avl.back())&1)==0)
					dp[k]=max(dp[k],dp[k^(1<<avl.back())]);
				else
					dp[k]=0;
			last=endr[j].fi;
			j++;
		}
//		if(i==sz(star)) {
//			trace(j,last);
//			rep(i,0,8) {
//				cout<<dp[i]<<" ";
//			}
//			cout<<endl;
//		}
	}
//	trace(last);
	cout<<dp[0]<<endl;
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