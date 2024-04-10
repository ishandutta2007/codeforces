#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>

const int N=100005;

int n,m,cnt,last[N],ls[N],tot,a[N],b[N*2],c[N],p1[N],p2[N],size[N],top[N],dep[N],fa[N],q[N],tim,dfn[N],mx[N],t[N],stack[N],bel[N],ans[N];
bool ins[N],vis[N];
std::vector<int> rub,vec[N];
struct edge{int to,next;}e[N*2];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}

void add1(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=ls[u];ls[u]=cnt;
}

void pre1(int x)
{
	dep[x]=dep[fa[x]]+1;dfn[x]=++tim;size[x]=1;
	for (int i=last[x];i;i=e[i].next)
		pre1(e[i].to),size[x]+=size[e[i].to];
	mx[x]=tim;
}

void pre2(int x,int chain)
{
	top[x]=chain;int k=0;
	for (int i=last[x];i;i=e[i].next)
		if (size[e[i].to]>size[k]) k=e[i].to;
	if (k) pre2(k,chain);
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=k) pre2(e[i].to,e[i].to);
}

int get_lca(int x,int y)
{
	while (top[x]!=top[y])
	{
		if (dep[top[x]]<dep[top[y]]) std::swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}

bool cmp(int x,int y)
{
	return dfn[x]<dfn[y];
}

void build()
{
	std::sort(a+1,a+tot+1,cmp);
	int top=0;stack[++top]=1;rub.push_back(1);
	for (int i=1;i<=tot;i++)
	{
		if (a[i]==stack[top]) continue;
		int lca=get_lca(a[i],stack[top]);
		if (lca==stack[top]) {stack[++top]=a[i];rub.push_back(a[i]);continue;}
		while (dep[stack[top-1]]>=dep[lca]) add1(stack[top-1],stack[top]),top--;
		if (dep[stack[top]]>dep[lca]) add1(lca,stack[top]),top--;
		if (stack[top]!=lca) stack[++top]=lca,rub.push_back(lca);
		stack[++top]=a[i];rub.push_back(a[i]);
	}
	while (top>1) add1(stack[top-1],stack[top]),top--;
}

void work(int l,int r)
{
	for (int i=1;i<=n*2;i++) b[i]=0;
	for (int i=1;i<=n;i++) b[t[i]+n]++,bel[i]=0;
	for (int i=1;i<=n*2;i++) b[i]+=b[i-1];
	for (int i=1;i<=n;i++) c[b[t[i]+n]--]=i;
	ins[0]=1;
	for (int i=0;i<rub.size();i++) ins[rub[i]]=1;
	for (int i=0;i<rub.size();i++)
		for (int j=fa[rub[i]];!ins[j];j=fa[j])
			bel[j]=rub[i];
	int w=0;
	for (int i=1;i<=n;i++)
		if (bel[c[i]]) vec[bel[c[i]]].push_back(c[i]);
		else w+=(!vis[c[i]]&&t[c[i]]<0&&!ins[c[i]]&&!bel[c[i]]);
	for (int i=l;i<=r;i++) ans[i]=w;
	for (int i=0;i<rub.size();i++)
	{
		int sz=0,x=rub[i];
		for (int j=0;j<vec[x].size();j++)
			if (sz&&p1[sz]==t[vec[x][j]]) p2[sz]+=(!vis[vec[x][j]]);
			else p1[++sz]=t[vec[x][j]],p2[sz]=(!vis[vec[x][j]]);
		int pts=0,now=0,tag=0;
		while (pts<sz&&p1[pts+1]<0) pts++,now+=p2[pts];
		for (int j=l;j<=r;j++)
		{
			vis[q[j]]^=1;
			if (dfn[q[j]]>dfn[x]&&dfn[q[j]]<=mx[x]) t[x]+=(!vis[q[j]])?1:-1;
			if (dfn[q[j]]>=dfn[x]&&dfn[q[j]]<=mx[x])
			{
				if (!vis[q[j]]) tag++;
				else tag--;
			}
			while (pts<sz&&p1[pts+1]+tag<0) pts++,now+=p2[pts];
			while (pts&&p1[pts]+tag>=0) now-=p2[pts],pts--;
			ans[j]+=now;
			if (t[x]<0&&!vis[x]) ans[j]++;
		}
		for (int j=l;j<=r;j++) vis[q[j]]^=1;
		for (int j=0;j<vec[x].size();j++) t[vec[x][j]]+=tag;
	}
	for (int i=l;i<=r;i++) vis[q[i]]^=1;
}

void clear()
{
	for (int i=0;i<rub.size();i++)
	{
		int x=rub[i];
		vec[x].clear();
		ls[x]=0;ins[x]=0;
	}
	rub.clear();
}

int main()
{
	n=read();m=read();
	for (int i=2;i<=n;i++) fa[i]=read(),addedge(fa[i],i);
	for (int i=1;i<=n;i++) t[i]=read();
	for (int i=1;i<=m;i++) q[i]=abs(read());
	pre1(1);pre2(1,1);
	int B=sqrt(m);
	for (int i=1;i<=m;i+=B)
	{
		int tmp=cnt;
		tot=0;
		for (int j=0;j<B&&i+j<=m;j++) a[++tot]=q[i+j];
		build();
		work(i,std::min(m,i+B-1));
		cnt=tmp;
		clear();
	}
	for (int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}