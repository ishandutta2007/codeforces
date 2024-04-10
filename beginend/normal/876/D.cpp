#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=300005;

int n,a[N],size[N],f[N];
bool vis[N];

int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

int merge(int x,int y)
{
	int p=find(x),q=find(y);
	f[p]=q;size[q]+=size[p];
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),f[i]=i;
	printf("%d ",1);
	for (int i=1;i<=n;i++)
	{
		int x=a[i];
		vis[x]=1;size[x]=1;
		if (vis[x+1]) merge(x,x+1);
		if (vis[x-1]) merge(x,x-1);
		printf("%d ",i-size[find(n)]+1);
	}
	return 0;
}