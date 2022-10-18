#pragma GCC optimize ("O3")
#include <stdio.h>
#include <algorithm>
using namespace std;

int seg[2000004],n,place[500001],counts;

void build(int l,int r,int rt)
{
	if(l==r)
	{
		scanf("%d",&seg[rt]),place[l]=rt;
		return ;
	}
	int m=(l+r)>>1;
	build(l,m,rt<<1),build(m+1,r,rt<<1|1);
	seg[rt]=__gcd(seg[rt<<1],seg[rt<<1|1]);
}

void query(int L,int R,int l,int r,int rt,int x)
{
	if(counts>1 || seg[rt]%x==0) return;
	int m=(l+r)>>1;
	if(L<=l && R>=r)
	{
		if(l==r) ++counts;
		else
		{
			if(L<=m) query(L,R,l,m,rt<<1,x);
			if(R>m) query(L,R,m+1,r,rt<<1|1,x);
		}
	}
	else
	{
		if(L<=m) query(L,R,l,m,rt<<1,x);
		if(R>m) query(L,R,m+1,r,rt<<1|1,x);
	}
}
 
int main()
{
	int q,k,l,r,x,a,b,m;
	bool tmp;
	scanf("%d",&n);
	build(1,n,1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&k,&l);
		if(k==1)
		{
			scanf("%d%d",&r,&x);
			counts=0,query(l,r,1,n,1,x);
			if(counts>1) puts("NO");
			else puts("YES");
		}
		else 
		{
			scanf("%d",&x);
			for(seg[a=place[l]]=x;a>1;)
				a>>=1,seg[a]=__gcd(seg[a<<1],seg[a<<1|1]);
		}
	 }
}