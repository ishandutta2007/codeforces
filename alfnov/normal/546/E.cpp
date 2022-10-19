#include<bits/stdc++.h>
using namespace std;
int fa1[100005],fa2[100005],ans=0,tot=1,S,T,n;
int l[1000005],f[1000005],c[1000005],zhi[1000005],mw[1000005],id[1000005];
int cur[1000005],nxt[1000005],q[1000005],a[1000005],b[1000005],cc[1000005];
void addedge(int u,int v,int w)
{
	tot++;
	if(id[u])nxt[mw[u]]=tot;
	else id[u]=tot;
	mw[u]=tot,zhi[tot]=v,f[tot]=0,c[tot]=w;
}
bool getc()
{
	int head=0,tail=-1;
	q[++tail]=S;
	for(int i=1;i<=n;i++)l[i]=0,cur[i]=id[i];
	l[S]=1;
	while(head<=tail)
	{
		int x=q[head++];
		for(int i=id[x];i;i=nxt[i])
		{
			if(l[zhi[i]]||f[i]==c[i])continue;
			l[zhi[i]]=l[x]+1;
			q[++tail]=zhi[i];
		}
	}
	return l[T]!=0;
}
int dinic(int x,int rl)
{
	if(x==T)
	{
		ans+=rl;
		return rl;
	}
	int tl=rl;
	for(int &i=cur[x];i;i=nxt[i])
	{
		if(l[zhi[i]]!=l[x]+1||f[i]==c[i])continue;
		int gg=dinic(zhi[i],min(c[i]-f[i],rl));
		f[i]+=gg,f[i^1]-=gg,rl-=gg;
		if(!rl)return tl;
	}
	return tl-rl;
}
int main()
{
	int N,M,d1=0,d2=0;
	cin>>N>>M;
	for(int i=1;i<=N;i++)scanf("%d",&a[i]),d1+=a[i];
	for(int i=1;i<=N;i++)scanf("%d",&b[i]),d2+=b[i];
	if(d1!=d2)
	{
		puts("NO");
		return 0;
	}
	S=1,n=T=2*N+2;
	for(int i=1;i<=N;i++)
	{
		addedge(S,i+1,a[i]),addedge(i+1,S,0);
		addedge(i+N+1,T,b[i]),addedge(T,i+N+1,0);
		addedge(i+1,i+N+1,INT_MAX),addedge(i+N+1,i+1,0);
	}
	for(int i=1;i<=M;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u+1,v+N+1,INT_MAX),addedge(v+N+1,u+1,0);
		addedge(v+1,u+N+1,INT_MAX),addedge(u+N+1,v+1,0);
	}
	while(getc())dinic(S,INT_MAX);
	if(ans!=d1)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)cc[j]=0;
		for(int j=id[i+1];j;j=nxt[j])if(c[j]!=0)
			cc[zhi[j]-N-1]=f[j];
		for(int j=1;j<=N;j++)printf("%d ",cc[j]);
		puts("");
	}
	return 0;
}