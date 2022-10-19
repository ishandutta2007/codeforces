#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int> e[N];
int dfn[N],low[N],scc[N],in[N],ans[N],st[N];
int a[N],b[N],f[N];
int top,tot,cnt,t,n;
inline bool cmpa(int x,int y)
{
	return a[x]<a[y];
}
inline bool cmpb(int x,int y)
{
	return b[x]<b[y];
}
inline void tarjan(int x)
{
	low[x]=dfn[x]=++cnt;
	st[++top]=x;
	in[x]=1;
	for (int y:e[x])
		if (!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else
		{
			if (in[y])
				low[x]=min(low[x],dfn[y]);
		}
	if (dfn[x]==low[x])
	{
		++tot;
		while (st[top]!=x)
		{
			scc[st[top]]=tot;
			in[st[top]]=0;
			--top;
		}
		scc[x]=tot;
		in[x]=0;
		--top;
	}
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for (int i=1;i<=n;++i)
			scanf("%d",&b[i]);
		for (int i=1;i<=n;++i)
			f[i]=i;
		sort(f+1,f+1+n,cmpa);
		for (int i=1;i<n;++i)
			e[f[i+1]].push_back(f[i]);
		sort(f+1,f+1+n,cmpb);
		for (int i=1;i<n;++i)
			e[f[i+1]].push_back(f[i]);
		for (int i=1;i<=n;++i)
			low[i]=dfn[i]=0;
		tot=cnt=top=0;
		for (int i=1;i<=n;++i)
			if (!dfn[i])
				tarjan(i);
		for (int i=1;i<=n;++i)
			ans[i]=1;
		for (int i=1;i<=n;++i)
			for (int x:e[i])
				if (scc[i]!=scc[x])
					ans[scc[x]]=0;
		for (int i=1;i<=n;++i)
			printf("%d",ans[scc[i]]);
		puts("");
		for (int i=1;i<=n;++i)
			e[i].clear();
	}
	return 0;
}