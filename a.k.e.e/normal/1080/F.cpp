#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
const int MAXN=300005,MAXD=8000005;

int n,p[MAXN],m,pn;
struct Data
{
	int l,r,x;
	bool operator <(const Data &b)const
		{return r<b.r;}
}a[MAXN];
int vs[MAXN];
int lch[MAXD],rch[MAXD],sum[MAXD],stot=0;

int modify(int id,int l,int r,int x,int c)
{
	int rt=++stot;
	if(l==r){sum[rt]=max(sum[id],c);return rt;}
	int mid=(l+r)>>1;
	lch[rt]=lch[id];rch[rt]=rch[id];
	if(x<=mid)lch[rt]=modify(lch[id],l,mid,x,c);
	else rch[rt]=modify(rch[id],mid+1,r,x,c);
	sum[rt]=min(sum[lch[rt]],sum[rch[rt]]);
	return rt;
}
int query(int id,int l,int r,int ql,int qr)
{
	if(l==ql && r==qr)return sum[id];
	int mid=(l+r)>>1;
	if(qr<=mid)return query(lch[id],l,mid,ql,qr);
	if(ql>mid)return query(rch[id],mid+1,r,ql,qr);
	return min(query(lch[id],l,mid,ql,mid),query(rch[id],mid+1,r,mid+1,qr));
}

int main()
{
    int T,l,r,x,y;
    scanf("%d%d%d",&n,&T,&m);
    for(int i=1;i<=m;i++)
    	scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].x);
    sort(a+1,a+m+1);
    /*for(int i=1;i<=m;i++)
    	printf("version:%d [%d] val:%d\n",a[i].r,a[i].x,a[i].l);*/
    a[0].r=0;
    for(int i=1;i<=m;i++)
    {
    	l=a[i].l;r=a[i].r;x=a[i].x;
    	if(r>a[i-1].r)
		{
			p[++pn]=r;
			vs[pn]=modify(vs[pn-1],1,n,x,l);
	    }
	    else vs[pn]=modify(vs[pn],1,n,x,l);
    }
    while(T--)
    {
    	scanf("%d%d%d%d",&l,&r,&x,&y);
    	y=upper_bound(p+1,p+pn+1,y)-p-1;
    	int t=query(vs[y],1,n,l,r);
    	//printf("ver:%d [%d,%d] %d\n",y,l,r,t);
    	printf(t>=x?"yes\n":"no\n");
    	fflush(stdout);
    }
    return 0;
}