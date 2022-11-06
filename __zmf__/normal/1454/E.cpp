#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int head[N],to[2*N],nxt[2*N],val[2*N],used[2*N],idx,taxi;
int dfn[N],id,num;
int fa[N];
int res[N],cnt,n,x,y,ans;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
inline void add(int x,int y)
{
	to[++cnt]=y,nxt[cnt]=head[x],head[x]=cnt;
}
void dfs(int u)
{
    dfn[u]=++id;
    for(int i=head[u];i!=-1;i=nxt[i])
    {
        int j=to[i];
        if(j==fa[u])continue;
        if(dfn[j])
        {
            if(dfn[j]<dfn[u])continue;
            res[++cnt]=j;
            for(;j!=u;j=fa[j])res[++cnt]=fa[j];
            return ;
        }
        else fa[j]=u,dfs(j);
    }
    return ;
}
inline void work(int u)
{
	for(int i=head[u];i!=-1;i=nxt[i])
	{
		if(!used[to[i]])
		{
			num++;used[to[i]]=1;
			work(to[i]);
		}
	}
	return ;
}
signed main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();
		for(int i=1;i<=n;i++)used[i]=0,head[i]=-1,dfn[i]=0;
		for(int i=1;i<=2*n;i++)nxt[i]=-1;
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			x=read(),y=read();
			add(x,y);add(y,x);
		}
		cnt=0;
		dfs(1);
		ans=n*(n-1)/2;
		ans=ans+cnt*(cnt-1)/2;
		ans=ans+(n-cnt)*(cnt-1);
		ans=ans+(n-cnt)*(n-cnt-1)/2;
		for(int p=1;p<=cnt;p++)used[res[p]]=1;
		for(int p=1;p<=cnt;p++)
		{
			num=0;
			work(res[p]);
			//cout<<p<<" "<<num<<endl;
			ans=ans-num*(num-1)/2;
		}
		cout<<ans<<endl;
	}
	return 0;
}