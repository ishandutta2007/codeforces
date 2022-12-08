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
#include<unordered_map>
using namespace std;
#define GC getchar()
#define PC putchar
inline void read(int&n)
{int x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
int outputarray[20];
inline void write(long long k)
{long long num=0;if(k<0)PC('-'),k=-k;do{outputarray[++num]=k%10,k/=10;}while(k);while(num)PC(outputarray[num--]+'0');puts("");}
#define next _next
const int maxn=1e5+5;
int n;
struct A
{
	int v,c,l,r,tot,id;
}a[maxn];
inline bool cmp(A a,A b)
{
	return a.tot<b.tot||a.tot==b.tot&&a.id<b.id;
}
struct S
{
	int v,id;
};
unordered_map<int,S>mp[maxn];
int dp[maxn],next[maxn];
int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(a[i].v),read(a[i].c),read(a[i].l),read(a[i].r),a[i].tot=a[i].c+a[i].l+a[i].r,a[i].id=i;
	sort(a+1,a+n+1,cmp);
	int p=1,ans=0,pos,tot=0;
	while(p<=n)
	{
		int q=p;
		while(q<n&&a[q+1].tot==a[q].tot)q++;
		tot++;
		for(int i=q;i>=p;i--)
		{
			if(!mp[tot].count(a[i].l+a[i].c))
			{
				if(!a[i].r)
				{
					dp[i]=a[i].v,next[i]=n+1;
					if(dp[i]>mp[tot][a[i].l].v)mp[tot][a[i].l].v=dp[i],mp[tot][a[i].l].id=i;
				}
				continue;
			}
			dp[i]=mp[tot][a[i].l+a[i].c].v+a[i].v,next[i]=mp[tot][a[i].l+a[i].c].id;
			if(dp[i]>mp[tot][a[i].l].v)mp[tot][a[i].l].v=dp[i],mp[tot][a[i].l].id=i;
		}
		for(int i=p;i<=q;i++)if(!a[i].l&&dp[i]>ans)ans=dp[i],pos=i;
		p=q+1;
	}
	int num=0;
	for(int i=pos;i<=n;i=next[i])num++;
	write(num);
	for(int i=pos;i<=n;i=next[i])printf("%d ",a[i].id);
	return 0;
}