#include<bits/stdc++.h>
#define ll long long
const int N=10005,M=20005;
int n,m,k,s1,s2,t,cc,hd[N],nxt[M],fr[M],to[M],q[N*64],vis[N];ll da[N],db[N],el[M],er[M];
inline void add(int u,int v,int l,int r){nxt[++cc]=hd[u];fr[cc]=u;to[cc]=v;el[cc]=l;er[cc]=r;hd[u]=cc;}
inline void spfa(ll*d,int s)
{
	memset(d,0x7f,sizeof(d));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)d[i]=10000000000000000ll,vis[i]=0;
	int ql=0,qr=0;q[++qr]=s;d[s]=0;vis[s]=1;
	while(ql<qr)
	{
		int x=q[++ql];
		for(int i=hd[x];i;i=nxt[i])if(d[to[i]]>d[x]+er[i])
		{
			d[to[i]]=d[x]+er[i];
			if(!vis[to[i]]){q[++qr]=to[i];vis[to[i]]=1;}
		}
		vis[x]=0;
	}
}
inline bool chk(int f)
{
	int ff=1;
	while(ff)
	{
		ff=0;spfa(da,s1);spfa(db,s2);
		for(int i=m+1;i<=m+k;i++)if(da[fr[i]]<db[fr[i]]+f&&el[i]!=er[i]){er[i]=el[i];ff=1;}
		if(da[t]<db[t]+f)
		{
			puts(f?"DRAW":"WIN");
			for(int i=m+1;i<=m+k;i++)printf("%d ",er[i]);
			return 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%d%d%d%d%d%d",&n,&m,&k,&s1,&s2,&t);
	for(int i=1,u,v,w;i<=m;i++){scanf("%d%d%d",&u,&v,&w);add(u,v,w,w);}
	for(int i=1,u,v,l,r;i<=k;i++){scanf("%d%d%d%d",&u,&v,&l,&r);add(u,v,l,r);}
	if(!chk(0)&&!chk(1))puts("LOSE");return 0;
}