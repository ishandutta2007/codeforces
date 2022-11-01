#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=150005;

int n,q,son[N],dep[N],fa[N],bel[N],ch[N][27],sum[N],mx[N][27],lef[N],rig[N],cnt;
bool flag;

void dfs1(int x)
{
	if (!lef[x]&&!rig[x]) {dep[x]=1;return;}
	if (!rig[x])
	{
		dfs1(lef[x]);
		dep[x]=dep[lef[x]]+1;
		son[x]=son[lef[x]];
		fa[son[x]]=x;
		lef[x]=son[x];
		for (int i=0;i<26;i++) ch[son[x]][i]+=ch[x][i];
	}
	else
	{
		dfs1(lef[x]);dfs1(rig[x]);
		if (dep[lef[x]]!=dep[rig[x]]) flag=1;
		dep[x]=dep[lef[x]]+1;
		fa[son[lef[x]]]=fa[son[rig[x]]]=x;
		lef[x]=son[lef[x]];rig[x]=son[rig[x]];
	}
}

void dfs2(int x)
{
	if (!lef[x]&&!rig[x]) return;
	if (!rig[x])
	{
		dfs2(lef[x]);
		for (int i=0;i<26;i++) mx[x][i]=mx[lef[x]][i]+ch[lef[x]][i],sum[x]+=mx[x][i];
		if (sum[x]>=dep[x]) cnt++;
		return;
	}
	dfs2(lef[x]);dfs2(rig[x]);
	for (int i=0;i<26;i++) mx[x][i]=std::max(mx[lef[x]][i]+ch[lef[x]][i],mx[rig[x]][i]+ch[rig[x]][i]),sum[x]+=mx[x][i];
	if (sum[x]>=dep[x]) cnt++;
}

void modify(int x,int c1,int c2)
{
	ch[x][c1]++;ch[x][c2]--;
	for (x=fa[x];x;x=fa[x])
	{
		if (sum[x]>=dep[x]) cnt--;
		if (c1<26)
		{
			sum[x]-=mx[x][c1];
			mx[x][c1]=std::max(mx[lef[x]][c1]+ch[lef[x]][c1],mx[rig[x]][c1]+ch[rig[x]][c1]);
			sum[x]+=mx[x][c1];
		}
		if (c2<26)
		{
			sum[x]-=mx[x][c2];
			mx[x][c2]=std::max(mx[lef[x]][c2]+ch[lef[x]][c2],mx[rig[x]][c2]+ch[rig[x]][c2]);
			sum[x]+=mx[x][c2];
		}
		if (sum[x]>=dep[x]) cnt++;
	}
}

int main()
{
	scanf("%d%d",&n,&q);
	for (int i=2;i<=n;i++)
	{
		int x;char str[2];scanf("%d%s",&x,str);
		bel[i]=str[0]=='?'?26:str[0]-'a';ch[i][bel[i]]++;
		fa[i]=x;
		if (!lef[x]) lef[x]=i;
		else rig[x]=i;
	}
	for (int i=1;i<=n;i++) son[i]=i;
	dfs1(1);
	if (flag)
	{
		for (int i=1;i<=q;i++) puts("Fou");
		return 0;
	}
	dfs2(1);
	while (q--)
	{
		int x;char str[2];scanf("%d%s",&x,str);
		modify(son[x],str[0]=='?'?26:str[0]-'a',bel[x]);
		bel[x]=str[0]=='?'?26:str[0]-'a';
		if (cnt) puts("Fou");
		else
		{
			LL ans=0;
			for (int i=0;i<26;i++) ans+=(LL)(i+1)*(mx[1][i]+dep[1]-1-sum[1]);
			printf("Shi %lld\n",ans);
		}
	}
	return 0;
}