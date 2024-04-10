#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=300005;
struct node
{
	int x,y;
}a[N];
int n,i,s1[N],top1,s2[N],top2,add[N*5],mn[N*5],mncnt[N*5];
long long ans;
bool cmp(node a,node b)
{
	return a.x<b.x;
}
void built(int o,int l,int r)
{
	mncnt[o]=1;
	if(l==r)
	{
		mn[o]=l;
		return;
	}
	int mid=l+r>>1;
	built(o<<1,l,mid);
	built(o<<1|1,mid+1,r);
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
}
void pushdown(int o,int l,int r)
{
	add[o<<1]+=add[o],add[o<<1|1]+=add[o];
	mn[o<<1]+=add[o],mn[o<<1|1]+=add[o];
	add[o]=0;
}
void update(int o,int l,int r,int x,int y,int z)
{
	if(l>=x&&r<=y)
	{
		add[o]+=z;
		mn[o]+=z;
		return;
	}
	pushdown(o,l,r);
	int mid=l+r>>1;
	if(x<=mid)
		update(o<<1,l,mid,x,y,z);
	if(y>mid)
		update(o<<1|1,mid+1,r,x,y,z);
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
	mncnt[o]=0;
	if(mn[o]==mn[o<<1])
		mncnt[o]+=mncnt[o<<1];
	if(mn[o]==mn[o<<1|1])
		mncnt[o]+=mncnt[o<<1|1];
}
int query(int o,int l,int r,int x,int y)
{
	if(l>=x&&r<=y)
		return mn[o]==i?mncnt[o]:0;
	int mid=l+r>>1,rtn=0;
	pushdown(o,l,r);
	if(x<=mid)
		rtn=query(o<<1,l,mid,x,y);
	if(y>mid)
		rtn+=query(o<<1|1,mid+1,r,x,y);
	return rtn;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+1+n,cmp);
	built(1,1,n);
	for(i=1;i<=n;++i)
	{
		while(top1&&a[i].y>a[s1[top1]].y)
		{
			update(1,1,n,s1[top1-1]+1,s1[top1],-a[s1[top1]].y);
			--top1;
		}
		s1[++top1]=i;
		update(1,1,n,s1[top1-1]+1,i,a[i].y);
		while(top2&&a[i].y<a[s2[top2]].y)
		{
			update(1,1,n,s2[top2-1]+1,s2[top2],a[s2[top2]].y);
			--top2;
		}
		s2[++top2]=i;
		update(1,1,n,s2[top2-1]+1,i,-a[i].y);
		ans+=query(1,1,n,1,i);
	}
	printf("%lld",ans);
	return 0;
}