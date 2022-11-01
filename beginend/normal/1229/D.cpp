#include<bits/stdc++.h>

typedef long long LL;

int n,k,tot,jc[6],p[725][725],tmp[7],vis[725],a[200005],ls[725],pos[725],to[725][725],use[725],top;
std::queue<int> que;

void dfs(int x)
{
	if (x>k)
	{
		tot++;
		for (int i=1;i<=k;i++) p[tot][i]=tmp[i];
		return;
	}
	for (int i=1;i<=k;i++)
		if (!vis[i]) vis[i]=1,tmp[x]=i,dfs(x+1),vis[i]=0;
}

int get_id(int *a)
{
	int s=1;
	for (int i=1;i<=k;i++)
	{
		int t=0;
		for (int j=i+1;j<=k;j++) t+=a[j]<a[i];
		s+=jc[k-i]*t;
	}
	return s;
}

void pre()
{
	jc[0]=1;
	for (int i=1;i<=k;i++) jc[i]=jc[i-1]*i;
	dfs(1);
	for (int i=1;i<=tot;i++)
		for (int j=1;j<=tot;j++)
		{
			for (int l=1;l<=k;l++) tmp[p[j][l]]=p[i][l];
			to[i][j]=get_id(tmp);
		}
}

void add(int x)
{
	vis[x]=1;tot++;use[++top]=x;
	for (int i=1;i<=jc[k];i++)
		if (vis[i]&&!vis[to[i][x]]) vis[to[i][x]]=1,que.push(to[i][x]),tot++;
	while (!que.empty())
	{
		int y=que.front();que.pop();
		for (int i=1;i<=top;i++)
			if (!vis[to[y][use[i]]]) vis[to[y][use[i]]]=1,tot++,que.push(to[y][use[i]]);
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	pre();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=k;j++) scanf("%d",&tmp[j]);
		a[i]=get_id(tmp);
	}
	LL ans=0;
	for (int i=1;i<=n;i++)
	{
		pos[a[i]]=i;
		for (int j=1;j<=jc[k];j++) ls[j]=pos[j];
		std::sort(ls+1,ls+jc[k]+1);
		memset(vis,0,sizeof(vis));
		tot=top=0;int now=i;
		for (int j=jc[k];j>=1;j--)
		{
			if (!ls[j]) {ans+=now*tot;now=0;break;}
			int y=ls[j],x=a[y];
			ans+=(now-y)*tot;now=y;
			if (!vis[x]) add(x);
		}
		if (now) ans+=now*tot;
	}
	printf("%lld\n",ans);
	return 0;
}