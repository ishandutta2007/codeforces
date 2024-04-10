#include<bits/stdc++.h>
using namespace std;
const int N=300005,M=10,K=105,inf=1e7;
int n,m,tt,S,T,cc=1,hd[K],dis[K],U[K],V[K],num[M],cur[M],cnt[M],s[M][M],stk[M],c[M],d[M],mrk[M][M];char s1[M],s2[M];
struct E{int v,nxt,w,f;}e[1005];
inline void add(int u,int v,int w){e[++cc]=(E){v,hd[u],w,w};hd[u]=cc;e[++cc]=(E){u,hd[v],0,0};hd[v]=cc;}
inline bool bfs()
{
	memset(dis,0,sizeof(dis));
	queue<int>q;q.push(S);dis[S]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=hd[x],y;i;i=e[i].nxt)if(e[i].w&&!dis[y=e[i].v]){dis[y]=dis[x]+1;q.push(y);}
	}
	return dis[T];
}
int dfs(int x,int T,int f)
{
	if(x==T||!f)return f;int sf=0;
	for(int i=hd[x];i;i=e[i].nxt)if(e[i].w&&dis[e[i].v]==dis[x]+1)
	{
		int w=dfs(e[i].v,T,min(f,e[i].w));
		if(w){e[i].w-=w;e[i^1].w+=w;f-=w;sf+=w;if(!f)break;}
	}
	return sf;
}
int dinic(){int ans=0;while(bfs())ans+=dfs(S,T,inf);return ans;}
void prt(int x)
{
	for(int i=hd[x];i;i=e[i].nxt)if(e[i^1].w)
	{
		int y=e[i].v,w=e[i^1].w;
		if(x==S)prt(y);
		else if(x>m&&x<=m+tt&&y>=1&&y<=m)
		{
			for(int j=1;j<=e[i^1].w;j++)
			{
				int u=U[x-m]+V[x-m]-y,v=y;
				printf("%d %d\n",num[u],cur[v]++);
			}
		}
	}
}
void sol(int nw)
{
	if(nw<=m-2)
	{
		for(int i=1;i<=m;i++)c[i]++,stk[nw]=i,sol(nw+1),c[i]--;
		return;
	}
	priority_queue<int,vector<int>,greater<int> >q;
	while(!q.empty())q.pop();
	for(int i=1;i<=m;i++)d[i]=c[i];
	for(int i=1;i<=m;i++)if(!d[i])q.push(i);
	memset(mrk,0,sizeof(mrk));int t=1;
	while(!q.empty()&&t<=m-2)
	{
		int x=q.top(),u=x,v=stk[t];q.pop();
		if(u>v)swap(u,v);mrk[u][v]=1;d[stk[t]]--;
		if(!d[stk[t]])q.push(stk[t]);t++;
	}
	if(q.size()>=2){int u=q.top();q.pop();int v=q.top();q.pop();mrk[u][v]=1;}
	for(int i=2;i<=cc;i++)e[i].w=e[i].f;
	for(int i=hd[S];i;i=e[i].nxt)if(e[i].v)
	{
		int y=e[i].v-m,u=U[y],v=V[y];
		e[i].w-=mrk[u][v];if(e[i].w<0)return;
	} 
	if(dinic()==n-m) 
	{
		for(int i=1;i<=m;i++)for(int j=i+1;j<=m;j++)if(mrk[i][j])printf("%d %d\n",num[i],num[j]);
		prt(S);exit(0);
	}
}
inline int gtw(int n){int t=n,w=0;while(t)t/=10,w++;return w;}
int main()
{
	scanf("%d",&n);m=gtw(n);
	for(int i=1,p=1;i<=m;i++,p*=10)num[i]=p,cur[i]=p+1,cnt[i]=p*9;
	cnt[m]=n-num[m]+1;S=0;T=m*m+m+3;
	for(int i=1,l1,l2;i<n;i++)
	{
		scanf("%s%s",s1,s2);l1=strlen(s1);l2=strlen(s2);
		if(l1>l2)swap(l1,l2);s[l1][l2]++;
	}
	for(int i=1;i<=m;i++)for(int j=i;j<=m;j++){U[++tt]=i;V[tt]=j;add(S,m+tt,s[i][j]);add(m+tt,i,inf);add(m+tt,j,inf);}
	for(int i=1;i<=m;i++)add(i,T,cnt[i]-1);
	sol(1);puts("-1");return 0;
}