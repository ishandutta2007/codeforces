//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define zhoukangyangtxdy "qwq"
#define zhoukangyangakioi "true"
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=1e4+9,M=1e5+9;
int n,m,val[N];
int head[N],nxt[M],tot,to[M],tim,low[N],dfn[N],cnt,uu[M],vv[M],dp[N],bel[N],siz[N],s;
int in[N],sta[N],top,ans;
bool vis[N];
inline void addedge(int u,int v)
{
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}
inline void tarjan(int u)
{
	//cout<<u<<endl;
	sta[++top]=u,vis[u]=1;dfn[u]=low[u]=++tim;
	for(int i=head[u];i;i=nxt[i])
	{
		if(!dfn[to[i]])
		{
			tarjan(to[i]);low[u]=min(low[u],low[to[i]]);
		}
		else if(vis[to[i]])low[u]=min(low[u],dfn[to[i]]);
	}
	if(low[u]==dfn[u])
	{
	//	cout<<zhoukangyangakioi<<endl;
		tot++;
		while(u!=sta[top])	
		{
			vis[sta[top]]=0;bel[sta[top]]=tot;
			siz[tot]+=val[sta[top]];top--;
		}
		vis[u]=0,bel[u]=tot,top--;
	}
	return ;
}
signed main()
{
	n=read(),m=read();s=read();
	for(int i=1;i<=m;i++)
	{
		uu[i]=read(),vv[i]=read();addedge(uu[i],vv[i]);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i);
	for(int i=1;i<=m;i++)
		if(bel[uu[i]]!=bel[vv[i]])in[bel[vv[i]]]++;
	for(int i=1;i<=tot;i++)
		if(i!=bel[s]&&in[i]==0)ans++;
	cout<<ans<<endl;	
	return 0;
}