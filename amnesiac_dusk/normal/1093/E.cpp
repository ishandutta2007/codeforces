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
oset S[N];
int n;
inline void add(int pos, int val) {
	while(pos<N) {
		S[pos].insert(val);
		pos+=(pos&-pos);
	}
}
inline void remove(int pos, int val) {
	while(pos<N) {
		S[pos].erase(val);
		pos+=(pos&-pos);
	}
}
inline int query(int l,int r,int v,int v2) {
	int res=0;
	l--;
	int ro=r,lo=l;
	while(r>0) res-=S[r].order_of_key(v),r-=(r&-r);
	while(l>0) res+=S[l].order_of_key(v),l-=(l&-l);
	while(ro>0) res+=S[ro].order_of_key(v2+1),ro-=(ro&-ro);
	while(lo>0) res-=S[lo].order_of_key(v2+1),lo-=(lo&-lo);
	return res;
}
pii anti[N];
int b[N];
void solve() {
	int m,te;
	cin>>n>>m;
	fr(i,1,n) {
		cin>>te;
		anti[te].fi=i;
	}
	fr(i,1,n) {
		cin>>te;
		b[i]=te;
		anti[te].se=i;
	}
	fr(i,1,n) {
		add(anti[i].fi,anti[i].se);
	}
	while(m--) {
		int type;
		cin>>type;
		if(type==1) {
			int la,ra,lb,rb;
			cin>>la>>ra>>lb>>rb;
			cout<<query(la, ra, lb, rb)<<endl;
		} else {
			int x,y;
			cin>>x>>y;
			swap(b[x],b[y]);
			x=b[x];
			y=b[y];
			remove(anti[x].fi, anti[x].se);
			remove(anti[y].fi, anti[y].se);
			swap(anti[x].se,anti[y].se);
			add(anti[x].fi, anti[x].se);
			add(anti[y].fi, anti[y].se);
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