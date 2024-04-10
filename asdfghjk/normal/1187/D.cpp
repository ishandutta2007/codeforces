#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=300005;
struct node
{
	int id,num;
}c[N],d[N];
int t,n,i,a[N],b[N],pt[N],mn[N*5];
bool cmp(node a,node b)
{
	if(a.num!=b.num)
		return a.num<b.num;
	return a.id<b.id;
}
void built(int o,int l,int r)
{
	if(l==r)
	{
		mn[o]=a[l];
		return;
	}
	int mid=l+r>>1;
	built(o<<1,l,mid);
	built(o<<1|1,mid+1,r);
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
}
void update(int o,int l,int r,int x,int y)
{
	if(l==r)
	{
		mn[o]=y;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)
		update(o<<1,l,mid,x,y);
	else
		update(o<<1|1,mid+1,r,x,y);
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
}
int query(int o,int l,int r,int x,int y)
{
	if(l>=x&&r<=y)
		return mn[o];
	int mid=l+r>>1,rtn=1<<30;
	if(x<=mid)
		rtn=min(rtn,query(o<<1,l,mid,x,y));
	if(y>mid)
		rtn=min(rtn,query(o<<1|1,mid+1,r,x,y));
	return rtn;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			c[i]=(node){i,a[i]};
		}
		for(i=1;i<=n;++i)
		{
			scanf("%d",b+i);
			d[i]=(node){i,b[i]};
		}
		sort(c+1,c+1+n,cmp);
		sort(d+1,d+1+n,cmp);
		for(i=1;i<=n;++i)
			if(c[i].num!=d[i].num)
				break;
		if(i<=n)
		{
			puts("NO");
			continue;
		}
		for(i=1;i<=n;++i)
			pt[d[i].id]=c[i].id;
		built(1,1,n);
		for(i=1;i<=n;++i)
		{
			if(a[pt[i]]>query(1,1,n,1,pt[i]))
				break;
			update(1,1,n,pt[i],1<<30);
		}
		if(i<=n)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}