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
//#define int long long
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


int lazy[205];
int freq[205][10005];
int blk[100005];
int a[100005];
const int bls=500;
bool good[10005];
void solve() {
	vi aa={4,7};
	for(int i=0; aa.back()<=10000; i++) {
		aa.pb(aa[i]*10+4);
		aa.pb(aa[i]*10+7);
	}
	aa.pop_back();
	aa.pop_back();
	for(int i:aa)
		good[i]=1;
	int n,q;
	cin>>n>>q;
	fr(i,1,n) {
		cin>>a[i];
		blk[i]=(i-1)/bls+1;
		freq[blk[i]][a[i]]++;
	}
	while(q--) {
		string ty;
		cin>>ty;
		if(ty=="add") {
			int l,r,d;
			cin>>l>>r>>d;
			if(blk[l]==blk[r]) {
				for(int i=l; i<=r; i++) {
					freq[blk[l]][a[i]]--;
					a[i]+=d;
					freq[blk[l]][a[i]]++;
				}
			} else {
				for(int i=l; blk[i]==blk[l]; i++) {
					freq[blk[l]][a[i]]--;
					a[i]+=d;
					freq[blk[l]][a[i]]++;
				}
				for(int i=r; blk[i]==blk[r]; i--) {
					freq[blk[r]][a[i]]--;
					a[i]+=d;
					freq[blk[r]][a[i]]++;
				}
				for(int i=blk[l]+1; i<blk[r]; i++)
					lazy[i]+=d;
			}
		} else {
			int l,r;
			cin>>l>>r;
			int ans=0;
			if(blk[l]==blk[r]) {
				for(int i=l; i<=r; i++)
					if(good[a[i]+lazy[blk[i]]])
						ans++;
			} else {
				for(int i=l; blk[i]==blk[l]; i++)
					if(good[a[i]+lazy[blk[i]]])
						ans++;
				for(int i=r; blk[i]==blk[r]; i--)
					if(good[a[i]+lazy[blk[i]]])
						ans++;
				for(int j=blk[l]+1; j<blk[r]; j++)
					for(int i:aa)
						if(i>lazy[j])
							ans+=freq[j][i-lazy[j]];
			}
			cout<<ans<<endl;
		}
	}
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