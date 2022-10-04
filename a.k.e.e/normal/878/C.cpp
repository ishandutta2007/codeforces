#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=50005,INF=0x3f3f3f3f;

int n,k,a[MAXN][13],p[MAXN],Min[13],Max[13],size;
struct Node
{
	int size;bool lazy;
	int Min[13],Max[13];
	Node(){lazy=1;}
	inline int rsz(){return lazy?0:size;}
	inline int rmin(int x){return lazy?INF:Min[x];}
	inline int rmax(int x){return lazy?0:Max[x];}
}st[MAXN<<2|1];
void pushdown(int id)
{
	if(!st[id].lazy)return;
	memset(st[id].Min,0x3f,sizeof(st[id].Min));
	memset(st[id].Max,0,sizeof(st[id].Max));
	st[id].size=0;
	st[id<<1].lazy=st[id<<1|1].lazy=1;
	st[id].lazy=0;
}
void update(int id)
{
	st[id].lazy=0;
	st[id].size=st[id<<1].rsz()+st[id<<1|1].rsz();
	for(int i=1;i<=k;i++)
		st[id].Min[i]=min(st[id<<1].rmin(i),st[id<<1|1].rmin(i)),
		st[id].Max[i]=max(st[id<<1].rmax(i),st[id<<1|1].rmax(i));
}
int binal(int id,int l,int r,int *a)
{
	if(l==r)
	{
		for(int i=1;i<=k;i++)
			if(a[i]<st[id].rmax(i))return l;
		return n+1;
	}
	pushdown(id);
	int mid=(l+r)>>1;
	for(int i=1;i<=k;i++)
		if(a[i]<st[id<<1].rmax(i))return binal(id<<1,l,mid,a);
	return binal(id<<1|1,mid+1,r,a);
}
int binar(int id,int l,int r,int *a)
{
	if(l==r)
	{
		for(int i=1;i<=k;i++)
			if(a[i]>st[id].rmin(i))return l;
		return 0;
	}
	pushdown(id);
	int mid=(l+r)>>1;
	for(int i=1;i<=k;i++)
		if(a[i]>st[id<<1|1].rmin(i))return binar(id<<1|1,mid+1,r,a);
	return binar(id<<1,l,mid,a);
}
void clear(int id,int l,int r,int ql,int qr)
{
	if(l==ql && r==qr)
	{
		size+=st[id].rsz();
		for(int i=1;i<=k;i++)
			Min[i]=min(Min[i],st[id].rmin(i)),
			Max[i]=max(Max[i],st[id].rmax(i));
		st[id].lazy=1;
		return;
	}
	pushdown(id);
	int mid=(l+r)>>1;
	if(qr<=mid)clear(id<<1,l,mid,ql,qr);
	else if(ql>mid)clear(id<<1|1,mid+1,r,ql,qr);
	else {clear(id<<1,l,mid,ql,mid);clear(id<<1|1,mid+1,r,mid+1,qr);}
	update(id);
}
void modify(int id,int l,int r,int x)
{
	if(l==r)
	{
		st[id].lazy=0;
		st[id].size=size;
		for(int i=1;i<=k;i++)
			st[id].Min[i]=Min[i],st[id].Max[i]=Max[i];
		return;
	}
	pushdown(id);
	int mid=(l+r)>>1;
	if(x<=mid)modify(id<<1,l,mid,x);
	else modify(id<<1|1,mid+1,r,x);
	update(id);
}
int query(int id,int l,int r)
{
	if(l==r)return st[id].rsz();
	int mid=(l+r)>>1;
	if(st[id<<1|1].rsz())return query(id<<1|1,mid+1,r);
	return query(id<<1,l,mid);
}
/*void debug(int id,int l,int r)
{
	printf("%d [%d,%d] size:%d Min:(",id,l,r,st[id].rsz());
	for(int i=1;i<k;i++)printf("%d,",st[id].rmin(i));
	printf("%d) Max:(",st[id].rmin(k));
	for(int i=1;i<k;i++)printf("%d,",st[id].rmax(i));
	printf("%d)\n",st[id].rmax(k));
	if(l==r)return;
	int mid=(l+r)>>1;
	pushdown(id);
	debug(id<<1,l,mid);
	debug(id<<1|1,mid+1,r);
}*/
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=k;j++)scanf("%d",&a[i][j]);
    	p[i]=a[i][1];
    }
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)
    	a[i][1]=lower_bound(p+1,p+n+1,a[i][1])-p;
    for(int i=1;i<=n;i++)
    {
    	size=1;
    	memcpy(Min,a[i],sizeof(Min));
    	memcpy(Max,a[i],sizeof(Max));
    	if(i>1)
    	{
    		int l=binal(1,1,n,a[i]),r=binar(1,1,n,a[i]);
    		if(l<=r)clear(1,1,n,l,r);
//cout<<l<<" "<<r<<endl;
    	}
    	modify(1,1,n,a[i][1]);
    	printf("%d\n",query(1,1,n));
//debug(1,1,n);
    }
    return 0;
}