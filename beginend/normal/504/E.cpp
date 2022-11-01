#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=300005;

int n,s[N*2],dep[N],fa[N],size[N],p1[N],p2[N],cnt,last[N],b[N*2],c[N*2],d[N*2],rank[N*4],sa[N*2],rmq[N*2][22],bin[22],top[N],tim,lg[N*2];
char str[N];
struct edge{int to,next;}e[N*2];
struct data{int l,r,len;}inv1[N],inv2[N];

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
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void dfs1(int x)
{
	dep[x]=dep[fa[x]]+1;size[x]=1;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa[x]) continue;
		fa[e[i].to]=x;
		dfs1(e[i].to);
		size[x]+=size[e[i].to];
	}
}

void dfs2(int x,int chain)
{
	p1[x]=++tim;top[x]=chain;int k=0;
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&size[e[i].to]>size[k]) k=e[i].to;
	if (!k) return;
	dfs2(k,chain);
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=k) dfs2(e[i].to,e[i].to);
}

void get_sa(int n,int m)
{
	for (int i=1;i<=n;i++) b[s[i]]++;
	for (int i=1;i<=m;i++) b[i]+=b[i-1];
	for (int i=n;i>=1;i--) c[b[s[i]]--]=i;
	int t=0,j=1;
	for (int i=1;i<=n;i++)
	{
		if (s[c[i]]!=s[c[i-1]]) t++;
		rank[c[i]]=t;
	}
	while (j<=n)
	{
		for (int i=1;i<=n;i++) b[i]=0;
		for (int i=1;i<=n;i++) b[rank[i+j]]++;
		for (int i=1;i<=n;i++) b[i]+=b[i-1];
		for (int i=n;i>=1;i--) c[b[rank[i+j]]--]=i;
		for (int i=1;i<=n;i++) b[i]=0;
		for (int i=1;i<=n;i++) b[rank[i]]++;
		for (int i=1;i<=n;i++) b[i]+=b[i-1];
		for (int i=n;i>=1;i--) d[b[rank[c[i]]]--]=c[i];
		t=0;
		for(int i=1;i<=n;i++)
		{
			if (rank[d[i]]!=rank[d[i-1]]||rank[d[i]]==rank[d[i-1]]&&rank[d[i]+j]!=rank[d[i-1]+j]) t++;
			c[d[i]]=t;
		}
		for (int i=1;i<=n;i++) rank[i]=c[i];
		if (t==n) break;
		j<<=1;
	}
	for (int i=1;i<=n;i++) sa[rank[i]]=i;
}

void get_height(int n)
{
	int k=0;
	for (int i=1;i<=n;i++)
	{
		if (k) k--;
		int j=sa[rank[i]-1];
		while (i+k<=n&&j+k<=n&&s[i+k]==s[j+k]) k++;
		rmq[rank[i]][0]=k;
	}
}

void get_rmq(int n)
{
	for (int i=1;i<=n;i++) lg[i]=log(i)/log(2);
	bin[0]=1;
	for (int i=1;i<=lg[n];i++) bin[i]=bin[i-1]*2;
	for (int j=1;j<=lg[n];j++)
		for (int i=1;i+bin[j]-1<=n;i++)
			rmq[i][j]=min(rmq[i][j-1],rmq[i+bin[j-1]][j-1]);
}

int get_mn(int l,int r)
{
	if (l==r) return n*2-l+1;
	l=rank[l];r=rank[r];
	if (l>r) swap(l,r);
	l++;int w=lg[r-l+1];
	return min(rmq[l][w],rmq[r-bin[w]+1][w]);
}

int get_lca(int x,int y)
{
	while (top[x]!=top[y])
	{
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}

void get(data *a,int &tot,int x,int y)
{
	int lca=get_lca(x,y);
	while (dep[top[x]]>=dep[lca]) a[++tot]=(data){p2[x],p2[top[x]],0},x=fa[top[x]];
	if (dep[x]>=dep[lca]) a[++tot]=(data){p2[x],p2[lca],0};
	int tmp=tot;
	while (dep[top[y]]>dep[lca]) a[++tot]=(data){p1[top[y]],p1[y],0},y=fa[top[y]];
	if (dep[y]>dep[lca]) a[++tot]=(data){p1[lca]+1,p1[y],0};
	reverse(a+tmp+1,a+tot+1);
}

int main()
{
	n=read();scanf("%s",str+1);
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		addedge(x,y);
	}
	dfs1(1);dfs2(1,1);
	for (int i=1;i<=n;i++) p2[i]=n*2-p1[i]+1,s[p1[i]]=s[p2[i]]=str[i]-'a'+1;
	get_sa(n*2,30);get_height(n*2);get_rmq(n*2);
	int q=read();
	while (q--)
	{
		int a=read(),b=read(),c=read(),d=read(),tot1=0,tot2=0;
		get(inv1,tot1,a,b);get(inv2,tot2,c,d);
		for (int i=1;i<=tot1;i++) inv1[i].len=inv1[i].r-inv1[i].l+1;
		for (int i=1;i<=tot2;i++) inv2[i].len=inv2[i].r-inv2[i].l+1;
		int ans=0,p1=1,p2=1,l1=1,l2=1;
		while (p1<=tot1&&p2<=tot2)
		{
			int len=min(get_mn(inv1[p1].l+l1-1,inv2[p2].l+l2-1),min(inv1[p1].len-l1+1,inv2[p2].len-l2+1));
			ans+=len;
			if (len<min(inv1[p1].len-l1+1,inv2[p2].len-l2+1)) break;
			l1+=len;l2+=len;
			if (l1>inv1[p1].len) p1++,l1=1;
			if (l2>inv2[p2].len) p2++,l2=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}