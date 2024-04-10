#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005;
struct node
{
	int a,b,c,d;
}p[N];
int n,q,num,md,a[N],mt[N*5],sum[N*5],tag[N*5],i,j,k,x,y,ans[N],prm,pw[N],lmt;
int exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	int rtn=exgcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-a/b*y;
	return rtn;
}
int Inv(int n,int md)
{
	exgcd(n,md,x,y);
	return (x%md+md)%md;
}
void pushdown(int o,int l,int r)
{
	mt[o<<1]=1ll*mt[o<<1]*mt[o]%md,mt[o<<1|1]=1ll*mt[o<<1|1]*mt[o]%md;
	sum[o<<1]=1ll*sum[o<<1]*mt[o]%md,sum[o<<1|1]=1ll*sum[o<<1|1]*mt[o]%md;
	tag[o<<1]+=tag[o],tag[o<<1|1]+=tag[o];
	mt[o]=1;
	tag[o]=0;
}
void built(int o,int l,int r)
{
	tag[o]=0,mt[o]=1;
	if(l==r)
	{
		int i=a[l],j=0;
		while(i%prm==0)
			i/=prm,++j;
		sum[o]=i%md;
		tag[o]=j;
		return;
	}
	int mid=l+r>>1;
	built(o<<1,l,mid);
	built(o<<1|1,mid+1,r);
	sum[o]=(1ll*sum[o<<1]*(tag[o<<1]>lmt?0:pw[tag[o<<1]])+1ll*sum[o<<1|1]*(tag[o<<1|1]>lmt?0:pw[tag[o<<1|1]]))%md;
}
void update(int o,int l,int r,int x,int y,int z1,int z2)
{
	if(l>=x&&r<=y)
	{
		sum[o]=1ll*sum[o]*z1%md;
		mt[o]=1ll*mt[o]*z1%md;
		tag[o]+=z2;
		return;
	}
	int mid=l+r>>1;
	pushdown(o,l,r);
	if(x<=mid)
		update(o<<1,l,mid,x,y,z1,z2);
	if(y>mid)
		update(o<<1|1,mid+1,r,x,y,z1,z2);
	sum[o]=(1ll*sum[o<<1]*(tag[o<<1]>lmt?0:pw[tag[o<<1]])+1ll*sum[o<<1|1]*(tag[o<<1|1]>lmt?0:pw[tag[o<<1|1]]))%md;
}
void update2(int o,int l,int r,int x,int y,int z)
{
	if(l==r)
	{
		sum[o]=1ll*sum[o]*Inv(y,md)%md;
		tag[o]-=z;
		return;
	}
	int mid=l+r>>1;
	pushdown(o,l,r);
	if(x<=mid)
		update2(o<<1,l,mid,x,y,z);
	else
		update2(o<<1|1,mid+1,r,x,y,z);
	sum[o]=(1ll*sum[o<<1]*(tag[o<<1]>lmt?0:pw[tag[o<<1]])+1ll*sum[o<<1|1]*(tag[o<<1|1]>lmt?0:pw[tag[o<<1|1]]))%md;
}
int query(int o,int l,int r,int x,int y)
{
	if(l>=x&&r<=y)
	{
		return 1ll*sum[o]*(tag[o]>lmt?0:pw[tag[o]])%md;
	}
	int mid=l+r>>1,rtn=0;
	pushdown(o,l,r);
	if(x<=mid)
		rtn=query(o<<1,l,mid,x,y);
	if(y>mid)
		rtn=(rtn+query(o<<1|1,mid+1,r,x,y))%md;
	sum[o]=(1ll*sum[o<<1]*(tag[o<<1]>lmt?0:pw[tag[o<<1]])+1ll*sum[o<<1|1]*(tag[o<<1|1]>lmt?0:pw[tag[o<<1|1]]))%md;
	return rtn;
}
void work()
{
	int i,j,k;
	pw[0]=1;
	for(i=1;;++i)
	{
		pw[i]=1ll*pw[i-1]*prm%md;
		lmt=i;
		if(!pw[i])
			break;
	}
	built(1,1,n);
	for(i=1;i<=q;++i)
	{
		if(p[i].a==1)
		{
			j=p[i].d,k=0;
			while(j%prm==0)
			{
				++k;
				j/=prm;
			}
			update(1,1,n,p[i].b,p[i].c,j,k);
		}
		else if(p[i].a==2)
		{
			j=p[i].c,k=0;
			while(j%prm==0)
			{
				++k;
				j/=prm;
			}
			update2(1,1,n,p[i].b,j,k);
		}
		else
		{
			exgcd(num/md,md,x,y);
			ans[i]=(ans[i]+1ll*(num/md)*(x%num+num)%num*query(1,1,n,p[i].b,p[i].c)%num)%num;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&num);
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
	scanf("%d",&q);
	for(i=1;i<=q;++i)
	{
		scanf("%d",&p[i].a);
		if(p[i].a==1)
			scanf("%d%d%d",&p[i].b,&p[i].c,&p[i].d);
		else if(p[i].a==2)
			scanf("%d%d",&p[i].b,&p[i].c);
		else
			scanf("%d%d",&p[i].b,&p[i].c);
	}
	for(i=2,j=num;i*i<=j;++i)
		if(j%i==0)
		{
			md=1;
			while(j%i==0)
				j/=i,md*=i;
			prm=i;
			work();
		}
	if(j>1)
	{
		prm=md=j;
		work();
	}
	for(i=1;i<=q;++i)
		if(p[i].a==3)
			printf("%d\n",ans[i]);
	return 0;
}