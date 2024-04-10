#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
int n,m;
#include<vector>
std::vector<int>v[1111111];
int x[1111111],y[1111111],l[1111111];
int fa[1111111];
int rt(int x)
{return(fa[x])?fa[x]=rt(fa[x]):x;}
int f[1111111][22],dep[1111111];
int lca(int x,int y)
{
	if(dep[x]<dep[y])x^=y^=x^=y;
	register int i;
	for(i=20;~i;i--)
		if(dep[f[x][i]]>=dep[y])x=f[x][i];
	if(x==y)return x;
	for(i=20;~i;i--)
		if(f[x][i]^f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
bool vis[1111111];
int sum[1111111];
void dfs(int p,int fff=0)
{
	f[p][0]=fff,vis[p]=1,dep[p]=dep[fff]+1;
	register int i;
	for(i=1;f[p][i-1];i++)
		f[p][i]=f[f[p][i-1]][i-1];
	for(auto tp:v[p])
		if(tp^fff)dfs(tp,p);
}
void prefix(int p,int fff=0)
{
	vis[p]=1;
	for(auto tp:v[p])
		if(tp^fff)prefix(tp,p),sum[p]+=sum[tp];
}
int dis(int x,int y){return dep[x]+dep[y]-2*dep[lca(x,y)];}
bool inc(int x,int y,int z)
{return dis(x,z)+dis(y,z)==dis(x,y);}
int s1[1111111],t1,s2[1111111],t2;
int inv[1111111];
int tmp[1111111],ts;
void record(int pid,int*stk,int&top)
{
	ts=top=0;
	int xx=x[pid],yy=y[pid],pl=lca(xx,yy);
	while(xx^pl)stk[++top]=xx,xx=f[xx][0];
	while(yy^f[pl][0])tmp[++ts]=yy,yy=f[yy][0];
	while(ts)stk[++top]=tmp[ts--];
}
void intersect(int x,int y)
{
	record(x,s1,t1),record(y,s2,t2);
	register int i;
	for(i=1;i<=t1;i++)inv[s1[i]]++;
	for(i=1;i<=t2;i++)inv[s2[i]]+=2;
	int p1=0,p2=0;
	int r1=0,r2,r3;
	for(i=1;i<=t1;i++)if(inv[s1[i]]==3)r1++;
	r2=t1-r1+2,r3=t2-r1+2;
	printf("%d ",r1);
	for(i=1;i<=t1;i++)if(inv[s1[i]]==3)printf("%d ",s1[i]),p1=i;puts("");
	for(i=1;i<=t2;i++)if(inv[s2[i]]==3)p2=i;
	if(s1[p1]^s2[p2])
	{
		for(i=1;i<=t2-i+1;i++)
		{int t=s2[i];s2[i]=s2[t2-i+1],s2[t2-i+1]=t;}
		p2=0;
		for(i=1;i<=t2;i++)if(inv[s2[i]]==3)p2=i;
	}printf("%d ",r2);for(i=p1-1;i;i--)if(inv[s1[i-1]]^3)printf("%d ",s1[i]);
	for(i=t1;i>=p1;i--)if(inv[s1[i+1]]^3)printf("%d ",s1[i]);puts("");
	printf("%d ",r3);for(i=p2-1;i;i--)if(inv[s2[i-1]]^3)printf("%d ",s2[i]);
	for(i=t2;i>=p2;i--)if(inv[s2[i+1]]^3)printf("%d ",s2[i]);puts("");
}
void solve(int ex)
{
	puts("YES");
	register int i;
	int a=0,b=0;
	for(i=1;i<=m;i++)
		if(!l[i])
			if(inc(x[i],y[i],ex))
				if(inc(x[i],y[i],f[ex][0]))
					(a?b:a)=i;
	intersect(a,b);
}
int main()
{
	scanf("%d%d",&n,&m);
	register int i;
	for(i=1;i<=m;i++)
		scanf("%d%d",x+i,y+i);
	for(i=1;i<=m;i++)
	{
		int xx=rt(x[i]),yy=rt(y[i]);
		if(xx==yy)continue;
		v[x[i]].push_back(y[i]),v[y[i]].push_back(x[i]),fa[xx]=yy,l[i]=1;
	}for(i=1;i<=n;i++)
		if(!vis[i])dfs(i);
	for(i=1;i<=m;i++)
		if(!l[i])
		{
			int p=x[i],q=y[i],r=lca(p,q);
			sum[p]++,sum[q]++,sum[r]-=2;
		}
	memset(vis,0,sizeof vis);
	for(i=1;i<=n;i++)
		if(!vis[i])prefix(i);
	for(i=1;i<=n;i++)if(sum[i]>=2)return solve(i),0;
	puts("NO");
}
/*
Just go for it.
*/