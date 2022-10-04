#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=300005,INF=1<<30;

int n,Q,p[MAXN*12+1],L[MAXN],R[MAXN],Op[MAXN],psize;

//int ln=1;
struct Node
{
	int sum,lazy;
}st[MAXN*24+1];

inline int SUM(int id,int l,int r)
{
	return st[id].lazy>=0?st[id].lazy*(p[r]-p[l-1]):st[id].sum;
}

void build(int id,int l,int r)
{
	st[id].lazy=-1;
	if(l==r)
	{
		st[id].sum=p[l]-p[l-1];
		st[id].lazy=-1;
		return;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	st[id].sum=st[id<<1].sum+st[id<<1|1].sum;
}

void modify(int id,int l,int r,int ql,int qr,int c)
{
	if(ql==l && qr==r)
	{
		st[id].lazy=c;
		return;
	}
	if(st[id].lazy>=0)
	{
		st[id<<1].lazy=st[id<<1|1].lazy=st[id].lazy;
		st[id].sum=st[id].lazy*(p[r]-p[l-1]);
		st[id].lazy=-1;
	}
	int mid=(l+r)>>1;
	if(qr<=mid)modify(id<<1,l,mid,ql,qr,c);
	else if(ql>mid)modify(id<<1|1,mid+1,r,ql,qr,c);
	else
	{
		modify(id<<1,l,mid,ql,mid,c);
		modify(id<<1|1,mid+1,r,mid+1,qr,c);
	}
	st[id].sum=SUM(id<<1,l,mid)+SUM(id<<1|1,mid+1,r);
}

int query(int id,int l,int r,int ql,int qr)
{
	if(ql==l && qr==r)
		return SUM(id,l,r);
	if(st[id].lazy>=0)
	{
		st[id<<1].lazy=st[id<<1|1].lazy=st[id].lazy;
		st[id].sum=st[id].lazy*(p[r]-p[l-1]);
		st[id].lazy=-1;
	}
	int mid=(l+r)>>1;
	if(qr<=mid)return query(id<<1,l,mid,ql,qr);
	if(ql>mid)return query(id<<1|1,mid+1,r,ql,qr);
	return query(id<<1,l,mid,ql,mid)+
		query(id<<1|1,mid+1,r,mid+1,qr);
}

int main()
{
    #ifdef OnCode
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%d",&n,&Q);
    psize=0;
    for(int i=1;i<=Q;i++)
    {
    	scanf("%d%d%d",&L[i],&R[i],&Op[i]);
    	if(L[i]>1)p[++psize]=L[i]-1;
     	p[++psize]=L[i];
    	if(L[i]<n)p[++psize]=L[i]+1;
    	if(R[i]>1)p[++psize]=R[i]-1;
    	p[++psize]=R[i];
    	if(R[i]<n)p[++psize]=R[i]+1;
    	Op[i]--;
    }
    p[++psize]=n;
    sort(p+1,p+psize+1);
    psize=unique(p+1,p+psize+1)-p-1;
    /*for(int i=1;i<=psize;i++)
    	printf("%d ",p[i]);
    printf("\n");*/
    //int ln=1;
    //while(ln<n)ln<<=1;
    build(1,1,psize);
    int l,r;
    for(int i=1;i<=Q;i++)
    {
    	l=lower_bound(p+1,p+psize+1,L[i])-p;
    	r=lower_bound(p+1,p+psize+1,R[i])-p;
    	//printf("%d %d %d ",l,r,Op[i]);
    	modify(1,1,psize,l,r,Op[i]);
    	printf("%d\n",query(1,1,psize,1,psize));
    }
    return 0;
}