#include<bits/stdc++.h>
std::vector<int>v[1111111];
int n,m,d[1111111],w[1111111];
bool reported;
void report()
{
	if(reported)return;
	reported=1;
	puts("YES");
	for(register int i=1;i<=n;i++)printf("%d ",w[i]);puts("");
}
bool vis[1111111];
int stk[1111111],top,dep[1111111],fa[1111111],fs[1111111],e[1111111];
bool dfs(int p=1,int f=0)
{
	fs[p]=0,vis[p]=1,stk[++top]=p,dep[p]=dep[f]+1,fa[p]=f;
	for(int t:v[p])
	{
		if(t==f)continue;
		if(vis[t])return 1;
		fs[p]=t;
		if(dfs(t,p))return 1;
	}return 0;
}
void filt(int a,int b)
{
	while(dep[a]>dep[b])a=fa[a],w[a]=2;
	while(dep[b]>dep[a])b=fa[b],w[b]=2;
	for(;a!=b;)a=fa[a],b=fa[b],w[a]=w[b]=2;
	w[a]=2;
}
void solve(int x)
{
	top=0;
	register int i,ii;
	if(dfs(x))
	{
		for(i=1;i<=top;i++)w[stk[i]]=1;
		report();
		return;
	}for(i=1;i<=top;i++)
		if(d[stk[i]]>=4)
		{
			for(ii=0;ii<4;ii++)w[v[stk[i]][ii]]=1;w[stk[i]]=2;
			report();
			return;
		}
	int tt=0;
	for(i=1;i<=top;i++)if(d[stk[i]]==3)e[++tt]=stk[i];
	if(tt==1)
	{
		for(i=1;i<=top;i++)vis[stk[i]]=0;
		dfs(e[1]);
		int a=e[1],r=v[a][0],s=v[a][1],t=v[a][2];
		int r1=fs[r],s1=fs[s],t1=fs[t];
		if(r1&&s1&&t1)
		{
			printf(" ");
			w[a]=3,w[r]=w[s]=w[t]=2,w[r1]=w[s1]=w[t1]=1;
			report();
			return;
		}
		int r2=fs[r1],s2=fs[s1],t2=fs[t1];
		if(r2&&s2)
		{
			printf("  ");
			w[a]=4,w[r]=w[s]=3,w[t]=w[r1]=w[s1]=2,w[r2]=w[s2]=1;
			report();
			return;
		}
		if(s2&&t2)
		{
			printf("   ");
			w[a]=4,w[t]=w[s]=3,w[r]=w[t1]=w[s1]=2,w[t2]=w[s2]=1;
			report();
			return;
		}
		if(r2&&t2)
		{
			printf("    ");
			w[a]=4,w[r]=w[t]=3,w[s]=w[r1]=w[t1]=2,w[r2]=w[t2]=1;
			report();
			return;
		}
		int r3=fs[r2],s3=fs[s2],t3=fs[t2];
		int r4=fs[r3],s4=fs[s3],t4=fs[t3];
		if(r4&&s1)
		{
			printf("     ");
			w[a]=6,w[r]=5,w[r1]=w[s]=4,w[r2]=w[t]=3,w[r3]=w[s1]=2,w[r4]=1;
			report();
			return;
		}if(r4&&t1)
		{
			printf("      ");
			w[a]=6,w[r]=5,w[r1]=w[t]=4,w[r2]=w[s]=3,w[r3]=w[t1]=2,w[r4]=1;
			report();
			return;
		}if(s4&&r1)
		{
			printf("       ");
			w[a]=6,w[s]=5,w[s1]=w[r]=4,w[s2]=w[t]=3,w[s3]=w[r1]=2,w[s4]=1;
			report();
			return;
		}if(s4&&t1)
		{
			printf("        ");
			w[a]=6,w[s]=5,w[s1]=w[t]=4,w[s2]=w[r]=3,w[s3]=w[t1]=2,w[s4]=1;
			report();
			return;
		}if(t4&&r1)
		{
			printf("         ");
			w[a]=6,w[t]=5,w[t1]=w[r]=4,w[t2]=w[s]=3,w[t3]=w[r1]=2,w[t4]=1;
			report();
			return;
		}if(t4&&s1)
		{
			printf("          ");
			w[a]=6,w[t]=5,w[t1]=w[s]=4,w[t2]=w[r]=3,w[t3]=w[s1]=2,w[t4]=1;
			report();
			return;
		}
	}else if(tt>1)
	{
		int a=e[1],b=e[2];
		for(int t:v[a])w[t]=1;
		for(int t:v[b])w[t]=1;
		w[a]=w[b]=2,filt(a,b);
		printf("           ");
		report();
	}
}
int x[1111111],y[1111111];
void exec()
{
	reported=0;
	scanf("%d%d",&n,&m);
	register int i;
	for(i=1;i<=n;i++)v[i].clear(),d[i]=w[i]=vis[i]=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",x+i,y+i),d[x[i]]++,d[y[i]]++;
		v[x[i]].push_back(y[i]),v[y[i]].push_back(x[i]);
	}for(i=1;i<=n;i++)if(!vis[i])solve(i);
	if(!reported)puts("NO");
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)exec();
}
/*
Please don't let me down.
*/