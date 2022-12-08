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
inline void read(int&n)
{int x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
int outputarray[20];
inline void write(int k)
{int num=0;if(k<0)PC('-'),k=-k;do{outputarray[++num]=k%10,k/=10;}while(k);while(num)PC(outputarray[num--]+'0');puts("");}
const int maxn=200005;
int a[maxn],n,m,k,l[maxn],r[maxn],fa[maxn],ct[maxn];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
struct S
{
	int x,id;
}s[maxn];
inline bool cmp(S a,S b)
{
	return a.id<b.id;
}
int main()
{
	read(n),read(m),read(k);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		read(l[i]),read(r[i]);
		int u=find(l[i]),v=find(r[i]);
		fa[u]=v;
	}
	for(int i=1;i<=n;i++)fa[i]=find(i);
	for(int i=1;i<=n;i++)s[i]=(S){i,fa[i]};
	sort(s+1,s+n+1,cmp);
	int p=1,ans=0;
	while(p<=n)
	{
		int q=p;
		while(s[q+1].id==s[q].id&&q<n)q++;
		for(int i=p;i<=q;i++)ct[a[s[i].x]]++;
		int mx=0;
		for(int i=p;i<=q;i++)if(ct[a[s[i].x]]>mx)mx=ct[a[s[i].x]];
		for(int i=p;i<=q;i++)ct[a[s[i].x]]--;
		ans+=mx;
		p=q+1;
	}
	write(n-ans);
	return 0;
}