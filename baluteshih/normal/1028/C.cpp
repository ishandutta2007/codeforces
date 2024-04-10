#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct mode
{
	int p,l,r,v;
	bool operator<(const mode&a)const{
		return p<a.p;
	}
}datas[300000];

struct Segment_Tree{
	struct node{
		int datas,lazy;
		node *l,*r;
		node():datas(0),lazy(0),l(0),r(0){}
		void up(){if(l) datas=max(l->datas,r->datas);}
		void down(){
			if(l){
				l->datas+=lazy,l->lazy+=lazy;
				r->datas+=lazy,r->lazy+=lazy; 
			}lazy=0;
		}
	}*root;
	int l,r;
	node *build(int l,int r){
		node *p=new node();
		if(l==r) return p->datas=0,p;
		int m=(l+r)/2;
		p->l=build(l,m),p->r=build(m+1,r);
		return p->up(),p;
	}
	void s_modify(int L,int R,int l,int r,node *p,int x){
		if(r<L || l>R) return;
		p->down();
		if(L<=l && R>=r)
			return p->datas+=x,p->lazy+=x,void();
		int m=(l+r)/2;
		s_modify(L,R,l,m,p->l,x);
		s_modify(L,R,m+1,r,p->r,x);
		p->up();
	}
	int s_query(int L,int R,int l,int r,node *p){
		if(r<L || l>R) return 0;
		p->down();
		if(L<=l && R>=r) return p->datas;
		int m=(l+r)/2,re;
		re=s_query(L,R,l,m,p->l);
		return max(re,s_query(L,R,m+1,r,p->r));
	}
	int finds(int l,int r,node *p,int k){
		if(l==r) return l;
		p->down();
		int m=(l+r)/2;
		if(p->r->datas>=k) return finds(m+1,r,p->r,k);
		return finds(l,m,p->l,k);
	}
	void init(int L,int R){l=L,r=R;
		root=build(l,r);
	}
	void modify(int L,int R,int x){
		s_modify(L,R,l,r,root,x);
	}
	int query(int L,int R){
		return s_query(L,R,l,r,root);
	}
}seg;

vector<int> v;

int main()
{jizz
	int n,b,l,u,r,top=0;
	cin >> n;
	for(int i=0;i<n;++i)
		cin >> b >> l >> u >> r,datas[top++]=mode{b,l,r,1},datas[top++]=mode{u+1,l,r,-1},v.pb(l),v.pb(r);
	sort(ALL(v)),v.resize(unique(ALL(v))-v.begin());
	sort(datas,datas+top);
	seg.init(1,v.size());
	for(int i=0,j=0;i<top;i=j)
	{
		while(j<top && datas[i].p==datas[j].p)
		{
			l=upper_bound(ALL(v),datas[j].l)-v.begin();
			r=upper_bound(ALL(v),datas[j].r)-v.begin();
			seg.modify(l,r,datas[j].v);
			++j;
		}
		if(seg.query(1,v.size())>=n-1)
		{
			r=seg.finds(1,v.size(),seg.root,n-1);
			cout << datas[i].p << " " << v[r-1] << "\n";
			return 0;
		}
	}
}