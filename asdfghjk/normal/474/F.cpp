#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005;
int n,q,i,j,a[N],g[N*5],c[N*5],pg,dg;
int gcd(int a,int b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
void built(int o,int l,int r)
{
	if(l==r)
	{
		g[o]=a[l];
		c[o]=1;
		return;
	}
	int mid=l+r>>1;
	built(o<<1,l,mid);
	built(o<<1|1,mid+1,r);
	g[o]=gcd(g[o<<1],g[o<<1|1]);
	if(g[o<<1]==g[o])
		c[o]+=c[o<<1];
	if(g[o<<1|1]==g[o])
		c[o]+=c[o<<1|1];
}
void query(int o,int l,int r,int x,int y)
{
	if(l>=x&&r<=y)
	{
		int lst=pg;
		if(pg==-1)
			pg=g[o];
		else
			pg=gcd(pg,g[o]);
		if(pg!=lst)
			dg=0;
		if(pg==g[o])
			dg+=c[o];
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)
		query(o<<1,l,mid,x,y);
	if(y>mid)
		query(o<<1|1,mid+1,r,x,y);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
	built(1,1,n);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&i,&j);
		pg=dg=-1;
		query(1,1,n,i,j);
		printf("%d\n",j-i+1-dg);
	}
	return 0;
}