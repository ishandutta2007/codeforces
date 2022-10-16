/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 */
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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
const ll infl=4e18;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000003;
typedef vector<int> vi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
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

const int N=1e6+5;
const int N2=1e6;
int tr[4*N],lazy[4*N];
int a[N],b[N];
void pushdown(int seg) {
	if(lazy[seg]) {
		tr[seg<<1]+=lazy[seg];
		tr[seg<<1|1]+=lazy[seg];
		lazy[seg<<1]+=lazy[seg];
		lazy[seg<<1|1]+=lazy[seg];
		lazy[seg]=0;
	}
}
void update(int seg, int ll, int rr, int l, int r, int val) {
	if(rr<l||ll>r) {
		return;
	}
	if(rr<=r&&l<=ll) {
		lazy[seg]+=val;
		tr[seg]+=val;
		return;
	}
	pushdown(seg);
	update(seg<<1,ll,(ll+rr)/2,l,r,val);
	update(seg<<1|1,1+(ll+rr)/2,rr,l,r,val);
	tr[seg]=min(tr[seg<<1],tr[seg<<1|1]);
}
int query(int seg, int ll, int rr) {
	if(tr[seg]>=0)
		return -1;
	if(ll==rr)
		return ll;
	pushdown(seg);
	int qu=query(seg<<1|1,(ll+rr)/2+1,rr);
	if(qu==-1) {
		return query(seg<<1,ll,(ll+rr)/2);
	}
	return qu;
}
void solve() {
	int n,m;
	cin>>n>>m;
	fr(i,1,n) {
		cin>>a[i];
		update(1,1,N2,1,a[i],-1);
	}
	fr(i,1,m) {
		cin>>b[i];
		update(1,1,N2,1,b[i],1);
	}
	int q;
	cin>>q;
	while(q--) {
		int ty;
		cin>>ty;
		if(ty==1) {
			int i,x;
			cin>>i>>x;
			update(1,1,N2,1,a[i],1);
			a[i]=x;
			update(1,1,N2,1,a[i],-1);
		} else {
			int i,x;
			cin>>i>>x;
			update(1,1,N2,1,b[i],-1);
			b[i]=x;
			update(1,1,N2,1,b[i],1);
		}
//		cout<<tr[1]<<endl;
		cout<<query(1,1,N2)<<endl;
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
	fflush(stdout);
	cerr<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}