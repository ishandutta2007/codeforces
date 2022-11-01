#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=1000005;

int n,lef[N],rig[N],ty[N],f[N];
bool arr[N],lea[N];

void dfs1(int x)
{
	if (lea[x]) return;
	if (ty[x]==4) dfs1(lef[x]),f[x]=f[lef[x]]^1;
	else
	{
		dfs1(lef[x]);dfs1(rig[x]);
		if (ty[x]==1) f[x]=f[lef[x]]&f[rig[x]];
		else if (ty[x]==2) f[x]=f[lef[x]]|f[rig[x]];
		else f[x]=f[lef[x]]^f[rig[x]];
	}
}

void dfs2(int x)
{
	arr[x]=1;
	if (lea[x]) return;
	if (ty[x]==4) dfs2(lef[x]);
	else if (ty[x]==1)
	{
		if (f[rig[x]]) dfs2(lef[x]);
		if (f[lef[x]]) dfs2(rig[x]);
	}
	else if (ty[x]==2)
	{
		if (!f[rig[x]]) dfs2(lef[x]);
		if (!f[lef[x]]) dfs2(rig[x]);
	}
	else dfs2(lef[x]),dfs2(rig[x]);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		char ch[5];scanf("%s",ch);
		if (ch[0]=='I') lea[i]=1,scanf("%d",&f[i]);
		else if (ch[0]=='N')
		{
			int x;scanf("%d",&x);
			lef[i]=x;
			ty[i]=4;
		}
		else
		{
			int x,y;scanf("%d%d",&x,&y);
			lef[i]=x;rig[i]=y;
			if (ch[0]=='A') ty[i]=1;
			else if (ch[0]=='O') ty[i]=2;
			else if (ch[0]=='X') ty[i]=3;
		}
	}
	dfs1(1);
	dfs2(1);
	for (int i=1;i<=n;i++)
		if (lea[i]) putchar((arr[i]?(f[1]^1):f[1])+'0');
	return 0;
}