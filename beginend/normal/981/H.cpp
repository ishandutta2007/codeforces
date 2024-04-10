#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;
const int MOD=998244353;

int n,k,cnt,last[N],jc[N],ny[N],a[20][N*2],b[N],tot,rev[N*2],size[N],f[N],s[N],L,ans;
struct edge{int to,next;}e[N*2];
struct data{int x,y;}t[N];

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

bool cmp(data a,data b)
{
	return a.x<b.x;
}

int calc(int *a,int n) 
{
	int ans=0;
	for (int i=0;i<=std::min(n,k-1);i++)
		(ans+=(LL)a[i]*jc[k]%MOD*ny[k-i]%MOD)%=MOD;
	return ans;
}

int ksm(int x,int y)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%MOD;
		x=(LL)x*x%MOD;y>>=1;
	}
	return ans;
}

void NTT(int *a,int f)
{
	for (int i=0;i<L;i++) if (i<rev[i]) std::swap(a[i],a[rev[i]]);
	for (int i=1;i<L;i<<=1)
	{
		int wn=ksm(3,f==1?(MOD-1)/i/2:MOD-1-(MOD-1)/i/2);
		for (int j=0;j<L;j+=(i<<1))
		{
			int w=1;
			for (int k=0;k<i;k++)
			{
				int u=a[j+k],v=(LL)w*a[j+k+i]%MOD;
				a[j+k]=(u+v)%MOD;a[j+k+i]=(u+MOD-v)%MOD;
				w=(LL)w*wn%MOD;
			}
		}
	}
	int ny=ksm(L,MOD-2);
	if (f==-1) for (int i=0;i<L;i++) a[i]=(LL)a[i]*ny%MOD;
}

void solve(int l,int r,int d)
{
	if (l==r) {a[d][0]=1;a[d][1]=t[l].x;return;}
	int mid=(l+r)/2;
	solve(l,mid,d+1);
	for (int i=0;i<=mid-l+1;i++) a[d][i]=a[d+1][i];
	solve(mid+1,r,d+1);
	int lg=0;
	for (L=1;L<=r-l+1;L<<=1,lg++);
	for (int i=0;i<L;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for (int i=mid-l+2;i<L;i++) a[d][i]=0;
	for (int i=r-mid+1;i<L;i++) a[d+1][i]=0;
	NTT(a[d],1);NTT(a[d+1],1);
	for (int i=0;i<L;i++) a[d][i]=(LL)a[d][i]*a[d+1][i]%MOD;
	NTT(a[d],-1);
}

void dfs1(int x,int fa)
{
	size[x]=1;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa) continue;
		dfs1(e[i].to,x);
		size[x]+=size[e[i].to];
		(s[x]+=s[e[i].to])%=MOD;
	}
	tot=0;
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa) t[++tot].x=size[e[i].to],t[tot].y=s[e[i].to];
	if (!tot) {f[x]=s[x]=1;return;}
	std::sort(t+1,t+tot+1,cmp);
	solve(1,tot,0);
	f[x]=calc(a[0],tot);(s[x]+=f[x])%=MOD;
	a[0][tot+1]=0;
	for (int i=tot+1;i>=1;i--) (a[0][i]+=(LL)a[0][i-1]*(n-size[x])%MOD)%=MOD;
	int w;
	for (int i=1;i<=tot;i++)
	{
		if (t[i].x==t[i-1].x) {(ans+=(LL)w*t[i].y%MOD)%=MOD;continue;}
		for (int j=0;j<=tot+1;j++) b[j]=a[0][j];
		for (int j=1;j<=tot+1;j++) (b[j]+=MOD-(LL)b[j-1]*t[i].x%MOD)%=MOD;
		w=calc(b,tot);
		(ans+=(LL)w*t[i].y%MOD)%=MOD;
	}
}

void dfs2(int x,int fa)
{
	int w=0;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa) continue;
		dfs2(e[i].to,x);
		(ans+=(LL)w*s[e[i].to]%MOD)%=MOD;
		(w+=s[e[i].to])%=MOD;
	}
}

int main()
{
	n=read();k=read();
	jc[0]=jc[1]=ny[0]=ny[1]=1;
	for (int i=2;i<=k;i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=k;i++) ny[i]=(LL)ny[i-1]*ny[i]%MOD;
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		addedge(x,y);
	}
	dfs1(1,0);
	dfs2(1,0);
	printf("%d",ans);
	return 0;
}