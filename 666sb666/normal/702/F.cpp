#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string> 
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define GC getchar()
#define PC putchar
inline void read(int&n)
{int x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
int outputarray[20];
inline void write(int k)
{int num=0;if(k<0)PC('-'),k=-k;do{outputarray[++num]=k%10,k/=10;}while(k);while(num)PC(outputarray[num--]+'0');}
/*-----------------------------------------------------header file----------------------------------------------------------------*/
const int maxn=200001;
int n,m,ans[maxn];
struct T
{
	int p,q;
	bool operator <(const T&b)const
	{
		return q!=b.q?q>b.q:p<b.p;
	}
}s[maxn];
struct node
{
	int key,id,l1,l2,s1,s2;
	node *l,*r;
	node(int w,int id):s1(w),id(id)
	{
		key=rand();
		l1=l2=s2=0;
		l=r=NULL;
	}
	void pushdown()
	{
		if(l1)
		{
			if(l!=NULL)l->l1+=l1,l->s1+=l1;
			if(r!=NULL)r->l1+=l1,r->s1+=l1;
			l1=0;
		}
		if(l2)
		{
			if(l!=NULL)l->l2+=l2,l->s2+=l2;
			if(r!=NULL)r->l2+=l2,r->s2+=l2;
			l2=0;
		}
	}
};
void split(node*root,node*&a,node*&b,int v)
{
	if(root==NULL)
	{
		a=b=NULL;
		return;
	}
	root->pushdown();
	if(root->s1>=v)b=root,split(root->l,a,b->l,v);
	else a=root,split(root->r,a->r,b,v);
}
node*merge(node*a,node*b)
{
	if(a==NULL)return b;
	if(b==NULL)return a;
	if(a->key<b->key)
	{
		a->pushdown(),a->r=merge(a->r,b);
		return a;
	}
	b->pushdown(),b->l=merge(a,b->l);
	return b;
}
node*insert(node*a,node*b)
{
	if(a==NULL)return b;
	node *l,*r;
	split(a,l,r,b->s1);
	return merge(l,merge(b,r));
}
node*left(node*root)
{
	while(root->l!=NULL)
	{
		root->pushdown();
		root=root->l;
	}
	return root;
}
node*right(node*root)
{
	while(root->r!=NULL)
	{
		root->pushdown();
		root=root->r;
	}
	return root;
}
void updata(node*root,int v,int w)
{
	root->l1+=v,root->l2+=w,root->s1+=v,root->s2+=w;
}
void query(node*root)
{
	if(root==NULL)return;
	ans[root->id]=root->s2;
	root->pushdown();
	if(root->l!=NULL)query(root->l);
	if(root->r!=NULL)query(root->r);
}
int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(s[i].p),read(s[i].q);
	sort(s+1,s+n+1);
	read(m);
	node*root=NULL;
	int k;
	for(int i=1;i<=m;i++)
	{
		read(k);
		root=insert(root,new node(k,i));
	}
	node *l,*r,*x,*y,*L,*R;
	for(int i=1;i<=n;i++)
	{
		split(root,l,r,s[i].p);
		if(r==NULL)
		{
			root=l;
			continue;
		}
		updata(r,-s[i].p,1);
		if(l==NULL)
		{
			root=r;
			continue;
		}
		x=left(r),y=right(l);
		while(x->s1<y->s1)
		{
			split(r,L,R,x->s1+1);
			l=insert(l,L),r=R;
			if(l==NULL||r==NULL)break;
			x=left(r),y=right(l);
		}
		root=merge(l,r);
	}
	query(root);
	for(int i=1;i<=m;i++)write(ans[i]),putchar(' ');
	return 0;
}