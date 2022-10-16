/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=1e18;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(ll a, ll b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

const int N=1e5+5;
int tr[2*N];
void update(int p, int val) {
	for(tr[p+=N]+=val; p>1; p>>=1) {
		tr[p>>1]=tr[p]+tr[p^1];
	}
}
int query(int l, int r) {
	int res=0;
	for(l+=N,r+=N; l<r; l>>=1,r>>=1) {
		if(l&1) res+=tr[l++];
		if(r&1) res+=tr[--r];
	}
	return res;
}
void solve() {
	int n;
	cin>>n;
	int start=1,end=n;
	fr(i,1,n)
		update(i,1);
	int q;
	cin>>q;
	int rev=0;
	while(q--) {
		int ty;
		cin>>ty;
//		cout<<endl;
		if(ty==1) {
			int p;
			cin>>p;
//			trace(p);
			if(rev)
				p=end-start+1-p;
//			trace(p);
			if(end-start<2*p) {
				for(int i=start+p; i<=end; i++) {
					update(2*(start+p)-1-i,query(i,i+1));
				}
				end=start+p-1;
				if(rev==0)
					rev^=1;
			} else {
				for(int i=start+p-1; i>=start; i--) {
					update(2*(start+p)-1-i,query(i,i+1));
				}
				start=start+p;
				if(rev==1)
					rev^=1;
			}
		} else {
			int l,r;
			cin>>l>>r;
			if(rev) {
				l=end-start+1-l;
				r=end-start+1-r;
				swap(l,r);
			}
//			trace(l,r,rev);
			cout<<query(start+l,start+r)<<endl;
		}
//		trace(start,end);
//		fr(i,start,end) {
//			cout<<query(i,i+1)<<" ";
//		}
//		cout<<endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}