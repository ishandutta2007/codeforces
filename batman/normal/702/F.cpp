#include <bits/stdc++.h>
using namespace std;
#define N ((int)201*1000)

struct Node
{
	int b,h;
	int l,r,ans,lazy,lazy_ans;
	Node(){l=r=-1;ans=lazy=lazy_ans=0;}
};

int n,m,h[N],root=-1,ans[N];
pair <int,int> a[N],c[N];
Node t[N];

void change(int x,int val,int res){t[x].b+=val;t[x].lazy+=val;t[x].ans+=res;t[x].lazy_ans+=res;}

void shift(int x)
{
	if(t[x].l!=-1)change(t[x].l,t[x].lazy,t[x].lazy_ans);
	if(t[x].r!=-1)change(t[x].r,t[x].lazy,t[x].lazy_ans);
	t[x].lazy=t[x].lazy_ans=0;
}

int merge(int x,int y)
{
	if(x==-1)return y;
	if(y==-1)return x;
	shift(x);shift(y);
	if(t[x].h<t[y].h)
	{
		t[x].r=merge(t[x].r,y);
		return x;
	}
	t[y].l=merge(x,t[y].l);
	return y;
}

pair <int,int> split(int x,int val)
{
	if(x==-1)return {-1,-1};
	shift(x);
	if(t[x].b<val)
	{
		pair <int,int> ex;ex=split(t[x].r,val);
		t[x].r=ex.first;
		ex.first=x;
		return ex;
	}
	pair <int,int> ex;ex=split(t[x].l,val);
	t[x].l=ex.second;
	ex.second=x;
	return ex;
}

int insert(int x,int y)
{
	if(x==-1)return y;
	shift(x);
	if(t[x].h<t[y].h)
	{
		if(t[y].b<=t[x].b)t[x].l=insert(t[x].l,y);
		else t[x].r=insert(t[x].r,y);
		return x;
	}
	pair <int,int> ex;ex=split(x,t[y].b);
	t[y].l=ex.first;t[y].r=ex.second;
	return y;
}

int main()
{
   	srand(time(NULL));
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",&a[i].second,&a[i].first),a[i].first*=-1;
	sort(a,a+n);
	scanf("%d",&m);
	for(int i=0;i<m;i++)scanf("%d",&t[i].b),t[i].h=rand(),root=insert(root,i);
	for(int i=0;i<n;i++)
	{
		int x=a[i].second;
		int r1,r2,r3;
		pair <int,int> ex;ex=split(root,x);
		r1=ex.first;r2=ex.second;
		change(r2,-x,1);
		ex=split(r2,x);
		r2=ex.first;r3=ex.second;
		queue <int> q;
		if(r2!=-1)q.push(r2);
		while(q.size())
		{
			int v=q.front();q.pop();
			shift(v);
			if(t[v].l!=-1)q.push(t[v].l);
			if(t[v].r!=-1)q.push(t[v].r);
			t[v].l=t[v].r=-1;
			r1=insert(r1,v);
		}
		root=merge(r1,r3);
	}
	queue <int> q;
	q.push(root);
	while(q.size())
	{
		int x=q.front();q.pop();
		shift(x);
		if(t[x].l!=-1)q.push(t[x].l);
		if(t[x].r!=-1)q.push(t[x].r);
	}
	for(int i=0;i<m;i++)printf("%d ",t[i].ans);
    return 0;
}