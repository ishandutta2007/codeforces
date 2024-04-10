#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=150005;
int n,p,m,i,j,k,a[N],st[N*5],g[N*5][10],c[N*5][10],cnt[N*5];
void merge(int x,int y,int z)
{
	int i,j,k;
	cnt[x]=cnt[y];
	for(i=1;i<=cnt[x];++i)
		c[x][i]=c[y][i],g[x][i]=g[y][i];
	for(i=1;i<=cnt[z];++i)
	{
		for(j=1;j<=cnt[x];++j)
			if(g[x][j]==g[z][i])
				break;
		if(j<=cnt[x])
			c[x][j]+=c[z][i];
		else
		{
			++cnt[x];
			g[x][cnt[x]]=g[z][i],c[x][cnt[x]]=c[z][i];
		}
	}
	for(i=cnt[x];i>=1;--i)
		for(j=1;j<i;++j)
			if(c[x][j]<c[x][i])
			{
				swap(c[x][j],c[x][i]);
				swap(g[x][j],g[x][i]);
			}
	for(i=cnt[x];i>100/p;--i)
	{
		k=c[x][i];
		for(j=0;j<=100/p;++j)
			c[x][i-j]-=k;
	}
	while(i>=1&&c[x][i]==0)
		--i;
	cnt[x]=i;
}
void pushdown(int o,int l,int r)
{
	if(st[o])
	{
		int mid=l+r>>1;
		st[o<<1]=st[o<<1|1]=st[o];
		cnt[o<<1]=cnt[o<<1|1]=1;
		c[o<<1][1]=mid-l+1,c[o<<1|1][1]=r-mid;
		g[o<<1][1]=g[o<<1|1][1]=st[o];
		st[o]=0;
	}
}
void built(int o,int l,int r)
{
	if(l==r)
	{
		cnt[o]=1;
		c[o][1]=1;
		g[o][1]=a[l];
		return;
	}
	int mid=l+r>>1;
	built(o<<1,l,mid);
	built(o<<1|1,mid+1,r);
	merge(o,o<<1,o<<1|1);
}
void update(int o,int l,int r,int x,int y,int z)
{
	if(l>=x&&r<=y)
	{
		st[o]=z;
		cnt[o]=1;
		c[o][1]=r-l+1;
		g[o][1]=z;
		return;
	}
	int mid=l+r>>1;
	pushdown(o,l,r);
	if(x<=mid)
		update(o<<1,l,mid,x,y,z);
	if(y>mid)
		update(o<<1|1,mid+1,r,x,y,z);
	merge(o,o<<1,o<<1|1);
}
void query(int o,int l,int r,int x,int y)
{
	if(l>=x&&r<=y)
	{
		merge(0,0,o);
		return;
	}
	pushdown(o,l,r);
	int mid=l+r>>1;
	if(x<=mid)
		query(o<<1,l,mid,x,y);
	if(y>mid)
		query(o<<1|1,mid+1,r,x,y);
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
	built(1,1,n);
	while(m--)
	{
		scanf("%d",&i);
		if(i==1)
		{
			scanf("%d%d%d",&i,&j,&k);
			update(1,1,n,i,j,k);
		}
		else
		{
			scanf("%d%d",&i,&j);
			cnt[0]=0;
			query(1,1,n,i,j);
			printf("%d ",cnt[0]);
			for(i=1;i<=cnt[0];++i)
				printf("%d ",g[0][i]);
			puts("");
		}
	}
	return 0;
}