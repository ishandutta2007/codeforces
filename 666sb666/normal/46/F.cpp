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
const int N=1005;
struct MAN
{
	char name[15];
	int pos,num;
	vector<int>key;
}a[N],b[N];
struct E
{
	int x,y;
}edge[N];
int n,m,k,fa[N],where[N],father[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int getfather(int x)
{
	return father[x]==x?x:father[x]=getfather(father[x]);
}
bool same(char*s,char*t)
{
	if(strlen(s)!=strlen(t))return false;
	int len=strlen(s);
	for(int i=0;i<len;i++)if(s[i]!=t[i])return false;
	return true;
}
int main()
{
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++)read(edge[i].x),read(edge[i].y);
	for(int i=1;i<=k;i++)
	{
		scanf("%s%d%d",a[i].name,&a[i].pos,&a[i].num);
		for(int j=1;j<=a[i].num;j++)
		{
			int x;
			read(x);
			a[i].key.push_back(x);
			where[x]=a[i].pos;
		}
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%s%d%d",b[i].name,&b[i].pos,&b[i].num);
		for(int j=1;j<=b[i].num;j++)
		{
			int x;
			read(x);
			b[i].key.push_back(x);
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i,father[i]=i;
	bool flag=false;
	while(!flag)
	{
		flag=true;
		for(int i=1;i<=k;i++)
			for(int j=0;j<a[i].key.size();j++)
			{
				int p=find(a[i].pos),q=find(edge[a[i].key[j]].x),r=find(edge[a[i].key[j]].y);
				if((p==q||p==r)&&q!=r)fa[q]=r,flag=false;
			}
	}
	flag=false;
	while(!flag)
	{
		flag=true;
		for(int i=1;i<=k;i++)
			for(int j=0;j<b[i].key.size();j++)
			{
				int p=getfather(b[i].pos),q=getfather(edge[b[i].key[j]].x),r=getfather(edge[b[i].key[j]].y);
				if((p==q||p==r)&&q!=r)father[q]=r,flag=false;
			}
	}
	flag=true;
	for(int i=1;i<=m;i++)if((find(edge[i].x)==find(edge[i].y))^(getfather(edge[i].x)==getfather(edge[i].y)))flag=false;
	for(int i=1;i<=k;i++)
	{
		int id;
		for(int j=1;j<=k;j++)if(same(a[i].name,b[j].name))id=j;
		if(find(a[i].pos)!=find(b[id].pos))flag=false;
		for(int j=0;j<b[id].key.size();j++)if(find(a[i].pos)!=find(where[b[id].key[j]]))flag=false;
	}
	if(flag)puts("YES");
	else puts("NO");
	return 0;
}