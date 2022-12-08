#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define GC getchar()
#define PC putchar
inline void read(long long&n)
{long long x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
long long outputarray[20];
inline void write(long long k)
{long long num=0;if(k<0)PC('-'),k=-k;do{outputarray[++num]=k%10,k/=10;}while(k);while(num)PC(outputarray[num--]+'0');puts("");}
/*-----------------------------------------------------header file----------------------------------------------------------------*/
const long long maxn=200005;
long long a[maxn];
struct T
{
	long long v;
	long long id;
}t[maxn<<2];
void build(long long u,long long l,long long r)
{
	if(l==r)
	{
		t[u].v=abs(a[l]);
		t[u].id=l;
		return;
	}
	long long mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	if(t[u<<1].v<t[u<<1|1].v)t[u].v=t[u<<1].v,t[u].id=t[u<<1].id;
	else t[u].v=t[u<<1|1].v,t[u].id=t[u<<1|1].id;
}
void modify(long long u,long long l,long long r,long long x)
{
	if(l==r)
	{
		t[u].v=abs(a[l]);
		t[u].id=l;
		return;
	}
	long long mid=(l+r)>>1;
	if(x<=mid)modify(u<<1,l,mid,x);
	else modify(u<<1|1,mid+1,r,x);
	if(t[u<<1].v<t[u<<1|1].v)t[u].v=t[u<<1].v,t[u].id=t[u<<1].id;
	else t[u].v=t[u<<1|1].v,t[u].id=t[u<<1|1].id;
}
int main()
{
	long long n,k,x,num=0;
	read(n),read(k),read(x);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(long long i=1;i<=n;i++)if(a[i]<0)num++;
	if(num%2==0)
	{
		long long tt=2e9;
		long long p;
		for(long long i=1;i<=n;i++)if(abs(a[i])<tt)tt=abs(a[i]),p=i;
		if(tt<=k*x)while(tt>=0&&k)tt-=x,k--;
		a[p]=a[p]>=0?tt:-tt;
	}
	num=0;
	for(long long i=1;i<=n;i++)if(a[i]<0)num++;
	for(long long i=1;i<=n*4;i++)t[i].v=2e9;
	build(1,1,n);
	if(num%2)
	{
		while(k--)
		{
			long long id=t[1].id;
			if(a[id]>=0)a[id]+=x;
			else a[id]-=x;
			modify(1,1,n,id);
		}
	}
	else
	{
		while(k--)
		{
			long long id=t[1].id;
			if(a[id]>=0)a[id]-=x;
			else a[id]+=x;
			modify(1,1,n,id);
		}
	}
	for(long long i=1;i<=n;i++)printf("%lld ",a[i]);
	return 0;
}