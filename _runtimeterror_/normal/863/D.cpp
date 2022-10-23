#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node{
    node *l,*r;
    ll val,sum,prior,lazy;
    int key;
    int size;
    bool rev;
    node ():l(nullptr) , r(nullptr) , rev(false){}
};
node* newnode(int k,ll val_)
{
    node *ret;
    ret = new node();
    ret-> key= k;
    ret-> val= val_;
    ret-> lazy=0;
    ret-> size=1;
    ret->prior= uniform_int_distribution<int>(0,1e9)(rng);
    return ret;
}

struct Treap {

	node *tree;
	Treap(): tree (nullptr) { }
	int size(node *a)
	{
	    return a?a->size:0;
	}
	void upd_sz(node *x)
	{
	    if(x)
	        x->size=size(x->l)+size(x->r)+1;
	}

	inline void combine(node* &root,node* l,node* r)
	{
	    root->sum = 0;
	    if(l)
	        root->sum += l->sum;
	    if(r)
	        root->sum += r->sum;
	}

	inline void pushdown(node *t)
	{
	    if(!t || t->lazy==0)
	        return ;
	    t->val+=t->lazy;
	    t->sum+=(t->lazy)*size(t);
	    if(t->l)
	        t->l->lazy+=t->lazy;
	    if(t->r)
	        t->r->lazy+=t->lazy;
	    t->lazy=0;
	}
	inline void rev(node* t)
	{
		if(!t || t->rev==0)
			return ;
		if(t->l) t->l->rev^=1;
		if(t->r) t->r->rev^=1;
		swap(t->l,t->r);
		t->rev=0;
	}
	inline void operate(node* t)
	{
	    if(!t)
	        return ;
	    rev(t->l);rev(t->r);
	    pushdown(t->l);pushdown(t->r);
	    combine(t,t->l,t->r);
	    t->sum+=t->val;
	}
	inline void reset(node* t)
	{
		if(t)
			t->sum=t->val;
	}
	void split(node* t,node* &l,node* &r,int pos,int add=0)
	{
	    if(!t) 
	    {
	        l = r = NULL;
	        return ;
	    }
	    rev(t);
	    pushdown(t);
	    int cur_pos=add+size(t->l);
	    if(cur_pos<=pos)
	        split(t->r,t->r,r,pos,cur_pos+1),l=t;
	    else
	        split(t->l,l,t->l,pos,add),r=t;
	    upd_sz(t);
	    operate(t);
	}

	void merge(node* &t,node *l,node *r)
	{
	    if(!l || !r)
	    {
	        t = l?l:r;
	        return ;
	    }
	    rev(l);rev(r);
	    pushdown(l);pushdown(r);
	    if(l->prior > r->prior)
	        merge(l->r,l->r,r),t=l;
	    else 
	        merge(r->l,l,r->l),t=r;
	    upd_sz(t);operate(t);
	}
	void insert(int pos,ll val)
	{
	    node *r=newnode(pos,val);
	    node *a,*b,*c;
	    split(tree,a,b,pos-1);
	    merge(c,a,r);
	    merge(tree,c,b);	
	}
	void reverse(node *t,int l,int r)
	{
		node *a,*b,*c;
		split(t,b,c,r);
		split(b,a,b,l-1);
		b->rev^=1;
		merge(b,a,b);
		merge(t,b,c);
	}
	void print(node* t)
	{
		rev(t);
		pushdown(t);
		if(!t)
			return ;
		print(t->l);
		cout << t->val <<"\n";
		print(t->r);
	}
	void del(int pos)
	{
		node *a,*b,*c;
		split(tree,a,c,pos);
		split(a,a,b,pos-1);
		merge(tree,a,c);
	}
	long long get(int pos)
	{
		node *a,*b,*c;
		split(tree,a,c,pos);
		split(a,a,b,pos-1);
		merge(a,a,b);
		merge(tree,a,c);
		return (b->val);
	}
	void rupdate(node* t,int l,int r,ll val)
	{
		node *a,*b,*c;
    	split(t,b,c,r);
    	split(b,a,b,l-1);
    	b->lazy+=val;
    	merge(b,a,b);
    	merge(t,b,c);
	}
	void update(node* t,int pos,ll val)
	{	
		node *a,*b,*c;
		split(t,a,c,pos);
		split(a,a,b,pos-1);
		b->val=val;
		reset(b);
		merge(a,a,b);
		merge(t,a,c);
	}

}tr;

int _runtimeTerror_()
{
	int n,m,q;
	cin>>n>>q>>m;
	for(int i=0;i<n;++i)
	{
		ll x;
		cin>>x;
		tr.insert(i,x);
	}
	for(int i=0;i<q;++i)
	{
		int t,l,r;
		cin>>t>>l>>r;
		--l,--r;
		if(t==1)
		{
			ll val=tr.get(r);
			tr.del(r);
			tr.insert(l,val);
		}
		else
			tr.reverse(tr.tree,l,r);
	}
	for(int i=0;i<m;++i)
	{
		int id;
		cin>>id;
		cout<<(tr.get(--id))<< ' ';
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef runSieve
		sieve();
	#endif
	#ifdef NCR
		initialize();
	#endif
	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}