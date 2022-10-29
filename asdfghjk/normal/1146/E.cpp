#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=200005;
struct node
{
	int id,num;
}a[N];
int n,q,t,b[N],st[N*5],ans[N],i,j;
char s[10];
int Abs(int a)
{
	return a>0?a:-a;
}
bool cmp(node a,node b)
{
	return Abs(a.num)<Abs(b.num);
}
void built(int o,int l,int r)
{
	if(l==r)
	{
		if(a[l].num>0)
			st[o]=1;
		else
			st[o]=-1;
		return;
	}
	int mid=l+r>>1;
	built(o<<1,l,mid);
	built(o<<1|1,mid+1,r);
}
void pushdown(int o,int l,int r)
{
	if(st[o]!=0)
	{
		st[o<<1]=st[o<<1|1]=st[o];
		st[o]=0;
	}
}
void update(int o,int l,int r,int x,int y,int z)
{
	if(l>=x&&r<=y)
	{
		st[o]=z;
		return;
	}
	pushdown(o,l,r);
	int mid=l+r>>1;
	if(x<=mid)
		update(o<<1,l,mid,x,y,z);
	if(y>mid)
		update(o<<1|1,mid+1,r,x,y,z);
}
void work(int o,int l,int r)
{
	if(l==r)
	{
		ans[a[l].id]=b[l]*st[o];
		return;
	}
	int mid=l+r>>1;
	pushdown(o,l,r);
	work(o<<1,l,mid);
	work(o<<1|1,mid+1,r);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i].num);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;++i)
		b[i]=Abs(a[i].num);
	built(1,1,n);
	while(q--)
	{
		scanf("%s%d",s,&i);
		if(s[0]=='<')
			j=1;
		else
			j=0;
		if(t)
			j=!j,i=-i;
		if(j&&i>0||!j&&i<0)
		{
			t=!t;
			j=!j;
			if(j)
				++i;
			else
				--i;
		}
		if(!j)
		{
			i=upper_bound(b+1,b+1+n,i)-b;
			if(i<=n)
				update(1,1,n,i,n,-1);
		}
		else
		{
			i=upper_bound(b+1,b+1+n,-i)-b;
			if(i<=n)
				update(1,1,n,i,n,1);
		}
	}
	work(1,1,n);
	for(i=1;i<=n;++i)
		printf("%d ",ans[i]*(t?-1:1));
	return 0;
}