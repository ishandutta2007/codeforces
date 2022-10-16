/*
 * 	In an empty-like sky
 * 		What were you looking at?
 * 			I did not even understand
 * 				The reason I woke up
 * 	I was terribly scared
 * 		Of believing
 * 			Because of that
 * 				I've thrown everything away
 * 	It would have been better
 * 		If this world that I hate so much
 * 			Could just disappear
 * 				If I continue to believe
 * 					Won't it hurt me?
 *
 * 	It was your voice
 * 		That has saved me
 * 			And keeps me going
 * 				The feeling that you taught me
 * 					That's true.
 * 	I will scream your name
 * 		Strongly hold your hand
 * 			I will not let go of it anymore
 * 				No matter what the future holds
 * 					If you're with me, I won't run away
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
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define double long double
//typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

int sparse[100005][17];
int supermin;
int n;
static inline uint32_t log2(const uint32_t x) {
	return (31-__builtin_clz(x));
}
int querya(int l, int r) {
	trace(l,r);
	if(r-l+1>=n)
		return supermin;
	if(l>n||r>n) {
		l=(l-1)%n+1;
		r=(r-1)%n+1;
	}
	if(l>r) {
		return min(querya(l,n),querya(1,r));
	}
	int loga2=log2(r-l+1);
	trace(loga2);
	trace(l,sparse[l][loga2],r,sparse[r+1-(1<<loga2)][loga2]);
	return min(sparse[l][loga2],sparse[r+1-(1<<loga2)][loga2]);
}
class dynamic_segtree {
public:
	struct node {
		node *l,*r;int val,lz;
		node() :
				l(NULL), r(NULL), val(0), lz(0) {
		}
	}*tr;int n;
	void init(int nn) { // for initializing the tree
		n=nn;
		tr= NULL;
	}
	void pushdown(node * &cur, int s, int e) {
		if(!cur) {
			cur=new node();
			cur->val=querya(s,e);
			trace(s,e,cur->val);
			return;
		}
		if(!cur->lz)
			return;
		int mid=(s+e)/2;
		cur->val=cur->lz;
		if(s!=e) {
			if(!cur->l) {
				cur->l=new node();
//				cur->l->val=query(s,mid);
			}
			cur->l->lz=cur->lz;
			if(!cur->r) {
				cur->r=new node();
//				cur->r->val=query(mid+1,e);
			}
			cur->r->lz=cur->lz;
		}
		cur->lz=0;
	}
	int getval(node * &cur, int ll, int rr) {
		if(!cur)
			return querya(ll,rr);
		return cur->val;
	}
	int query(node * &cur, int s, int e, int l, int r) {
		pushdown(cur,s,e);
		if(s>r||e<l||!cur)
			return infi;
		if(l<=s&&e<=r)
			return cur->val;
		int m=(s+e)>>1;
		return min(query(cur->l,s,m,l,r),query(cur->r,m+1,e,l,r));
	}
	void update(node * &cur, int s, int e, int l, int r, int val) {
		pushdown(cur,s,e);
		if(s>r||e<l)
			return;
		if(l<=s&&e<=r) {
			cur->lz=val;
			pushdown(cur,s,e);
			return;
		}
		int m=(s+e)>>1;
		update(cur->l,s,m,l,r,val);
		update(cur->r,m+1,e,l,r,val);
		cur->val=min(getval(cur->l,s,m),getval(cur->r,m+1,e));
	}
	void update(int l, int r, int val) { // for adding val to all indexes from l to r
		update(tr,1,n,l,r,val);
	}
	int query(int l, int r) { // sum of all values from l to r
		return query(tr,1,n,l,r);
	}
};
void solve() {
	int k;
	cin>>n>>k;
	supermin=1e9+5;
	for(int i=1; i<=n; i++) {
		cin>>sparse[i][0];
		supermin=min(supermin,sparse[i][0]);
	}
	for(int i=1; i<17; i++)
		for(int j=1; j+(1<<i)<=1+n; j++)
			sparse[j][i]=min(sparse[j][i-1],sparse[j+(1<<(i-1))][i-1]);
	dynamic_segtree hola;
	hola.init(n*k+5);
	int q;
	cin>>q;
	while(q--) {
		int ty;
		cin>>ty;
		if(ty==1) {
			int l,r,x;
			cin>>l>>r>>x;
			hola.update(l,r,x);
		} else {
			int l,r;
			cin>>l>>r;
			cout<<hola.query(l,r)<<endl;
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cerr<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}