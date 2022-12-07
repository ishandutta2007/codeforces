#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=1000005;
int fa[N],f[N];
int m1[N],m2[N];
int main()
{
	int n;
	scanf("%d",&n);
	for (int u=2;u<=n+1;u++)
	{
		int x;
		scanf("%d",&x);
		fa[u]=x;f[u]=1;
		int now=u;
		while (now!=1)
		{
			if (f[now]>m1[fa[now]])	{m2[fa[now]]=m1[fa[now]];m1[fa[now]]=f[now];}
			else if (f[now]>m2[fa[now]])	m2[fa[now]]=f[now];
			if (f[fa[now]]==max(m1[fa[now]],m2[fa[now]]+1)) break;
			f[fa[now]]=max(m1[fa[now]],m2[fa[now]]+1);
			now=fa[now];
		}
		printf("%d ",m1[1]);
	}
	return 0;
}