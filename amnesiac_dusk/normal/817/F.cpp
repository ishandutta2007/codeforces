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
//#pragma GCC optimize("Ofast")
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
//#define int long long
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
class dynamic_segtree {
public:
	struct node {
		node *l,*r;
		char col,inv;
		char lzy;
		ll val;
		node() :
				l(NULL), r(NULL), val(0), col(0), inv(0),lzy(-1) {
		}
	}*tr=NULL;
	int query() {
		if(tr->col==1)
			return tr->val;
		else
			return 1;
	}
	void pushdown(node* &cur, ll s,ll m,ll e) {
		if(cur->lzy!=-1) {
			cur->inv=0;
			if(!cur->l) {
				cur->l=new node();
			}
			cur->l->val=m+1;
			cur->l->col=cur->lzy;
			cur->l->lzy=cur->lzy;
			if(!cur->r) {
				cur->r=new node();
			}
			cur->r->val=e+1;
			cur->r->col=cur->lzy;
			cur->r->lzy=cur->lzy;
			cur->l->inv=0;
			cur->r->inv=0;
			cur->lzy=-1;
			return;
		}
		if(cur->inv) {
			if(!cur->l) {
				cur->l=new node();
				cur->l->val=m+1;
			}
			cur->l->col^=1;
			if(cur->l->lzy==-1)
				cur->l->inv^=1;
			else
				cur->l->lzy^=1;
			if(!cur->r) {
				cur->r=new node();
				cur->r->val=e+1;
			}
			cur->r->col^=1;
			if(cur->r->lzy!=-1)
				cur->r->lzy^=1;
			else
				cur->r->inv^=1;
			cur->inv=0;
		}
	}
	void onoff(node* &cur, ll s,ll e, ll l, ll r, int val) {
		if(s>r||l>e)
			return;
		if(cur==NULL) {
			cur=new node();
			cur->col=0;
			cur->val=e+1;
		}
		if(l<=s&&e<=r) {
			cur->lzy=val;
			cur->col=val;
			cur->val=e+1;
			cur->inv=0;
			return;
		}
		ll m=(s+e)>>1;
		pushdown(cur,s,m,e);
		onoff(cur->l, s, m , l, r, val);
		onoff(cur->r,m+1,e, l, r, val);
		if(cur->l!=NULL&&cur->r!=NULL) {
			cur->col=cur->l->col;
			if(cur->l->val!=m+1) {
				cur->val=cur->l->val;
			} else if(cur->l->col!=cur->r->col) {
				cur->val=m+1;
			} else
				cur->val=cur->r->val;

		} else if(cur->l!=NULL) {
			cur->col=cur->l->col;
			if(cur->l->val!=m+1)
				cur->val=cur->l->val;
			else if(cur->l->col!=0)
				cur->val=m+1;
			else
				cur->val=e+1;
		}
		else if(cur->r!=NULL){
			cur->col=0;
			if(cur->r->col!=0)
				cur->val=m+1;
			else
				cur->val=cur->r->val;
		} else {
			cur->col=0;
			cur->val=e+1;
		}
	}
	void invert(node* &cur, ll s, ll e, ll l, ll r) {
		if(s>r||l>e)
			return;
		if(cur==NULL) {
			cur=new node();
			cur->col=0;
			cur->val=e+1;
		}
		if(l<=s&&e<=r) {
			if(cur->lzy!=-1) {
				cur->lzy^=1;
			} else
				cur->inv^=1;
			cur->col^=1;
			return;
		}
		ll m=(s+e)>>1;
		pushdown(cur,s,m,e);
		invert(cur->l, s, m, l, r);
		invert(cur->r,m+1,e, l, r);
		if(cur->l!=NULL&&cur->r!=NULL) {
			cur->col=cur->l->col;
			if(cur->l->val!=m+1) {
				cur->val=cur->l->val;
			} else if(cur->l->col!=cur->r->col) {
				cur->val=m+1;
			} else
				cur->val=cur->r->val;

		} else if(cur->l!=NULL) {
			cur->col=cur->l->col;
			if(cur->l->val!=m+1)
				cur->val=cur->l->val;
			else if(cur->l->col!=0)
				cur->val=m+1;
			else
				cur->val=e+1;
		}
		else if(cur->r!=NULL){
			cur->col=0;
			if(cur->r->col!=0)
				cur->val=m+1;
			else
				cur->val=cur->r->val;
		} else {
			cur->col=0;
			cur->val=e+1;
		}
	}
	void invert(ll l, ll r) {
		invert(tr,1,4e5+5,l,r);
	}
	void onoff(ll l, ll r, int val) {
		onoff(tr, 1, 4e5+5, l, r, val);
	}
};
dynamic_segtree lolol;
vector<pair<int,pll>> queries;
vector<ll> vals;
map<ll,int> comp;
void solve() {
	int n;
	cin>>n;
	while(n--) {
		ll t,l,r;
		cin>>t>>l>>r;
		vals.pb(l);
		vals.pb(l+1);
		vals.pb(r);
		vals.pb(r+1);
		queries.pb({t,{l,r}});
	}
	vals.pb(0);
	vals.pb(1);
	sort(all(vals));
	vals.resize(unique(all(vals))-vals.begin());
	for(int i=0; i<sz(vals); i++)
		comp[vals[i]]=i;
	for(auto qu:queries) {
		ll t,l,r;
		t=qu.fi;
		l=comp[qu.se.fi];
		r=comp[qu.se.se];
		if(t==1) {
			lolol.onoff(l,r,1);
		} else if(t==2) {
			lolol.onoff(l,r,0);
		} else
			lolol.invert(l,r);
		cout<<vals[lolol.query()]<<endl;
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