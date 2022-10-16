/*
 * 	motto! motto! motto! tsuyoi! ;_;
 */
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
const ll infl=2e18;
const int infi=1e9;
const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}


const int N=2e5+5;
int lol[2]={1,-1};
int tr[32][2*N];
int n,k;
int pts[5][N];
void modify(int pos) {
	for(int i=0; i<(1<<k); i++) {
		int lols=0;
		for(int j=0; j<k; j++)
			lols+=lol[(i>>j)&1]*pts[j][pos];
		int po=pos+n;
		for(tr[i][po]=lols; po>1; po>>=1)
			tr[i][po>>1]=max(tr[i][po],tr[i][po^1]);
	}
}
int query(int ii,int l, int r) {
	int res=-infi;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
		if(l&1) res=max(res,tr[ii][l++]);
		if(r&1) res=max(res,tr[ii][--r]);
	}
	return res;
}
int query(int l, int r) {
	int ans=0;
	for(int i=0; i<(1<<(k-1)); i++) {
		int j=i^((1<<k)-1);
		ans=max(ans,query(i,l,r)+query(j,l,r));
	}
	return ans;
}
void solve() {
	cin>>n>>k;
	fr(i,0,n-1) {
		fr(j,0,k-1)
			cin>>pts[j][i];
		modify(i);
	}
	int q;
	cin>>q;
	while(q--) {
		int type;
		cin>>type;
		if(type==1) {
			int po;
			cin>>po;
			po--;
			for(int i=0; i<k; i++)
				cin>>pts[i][po];
			modify(po);
		}
		else {
			int l,r;
			cin>>l>>r;
			l--;
			cout<<query(l,r)<<endl;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}