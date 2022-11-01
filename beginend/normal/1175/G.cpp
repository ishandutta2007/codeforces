#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=20005;
const int inf=1e9;

int n,m,b[N],a[N],que[N],xi[N],yi[N],f[105][N],c[N];

void trans1(int l,int r,int le)
{
	int mid=(l+r)/2;
	int h=mid+2,t=mid+1,tot=0;
	for (int i=mid-1;i>=l;i--)
	{
		int x=b[i+1],y=i*b[i+1]-f[le-1][i];
		if (!tot||x!=xi[tot]) xi[++tot]=x,yi[tot]=y;
		else yi[tot]=std::max(y,yi[tot]);
	}
	int p=tot;
	for (int i=r;i>=mid+1;i--)
	{
		while (p>=1&&xi[p]>=b[i])
		{
			while (h<t&&(LL)(yi[p]-yi[que[h]])*(xi[que[h]]-xi[que[h+1]])<(LL)(yi[que[h]]-yi[que[h+1]])*(xi[p]-xi[que[h]])) h++;
			que[--h]=p;p--;
		}
		if (p==tot) continue;
		int lef=h,rig=t-1;
		while (lef<=rig)
		{
			int M=(lef+rig)/2;
			if ((yi[que[M+1]]-yi[que[M]])>(LL)i*(xi[que[M+1]]-xi[que[M]])) lef=M+1;
			else rig=M-1;
		}
		f[le][i]=std::min(f[le][i],xi[que[lef]]*i-yi[que[lef]]);
	}
}

void trans2(int l,int r,int le)
{
	int mid=(l+r)/2;
	int h=mid+2,t=mid+1,tot=0;
	for (int i=l;i<=mid;i++)
	{
		int x=i,y=f[le-1][i];
		xi[++tot]=x,yi[tot]=y;
	}
	int p=tot;
	for (int i=mid+1;i<=r;i++)
	{
		while (p>=1&&b[xi[p]+1]<=b[i])
		{
			while (h<t&&(LL)(yi[p]-yi[que[h]])*(xi[que[h]]-xi[que[h+1]])>(LL)(yi[que[h]]-yi[que[h+1]])*(xi[p]-xi[que[h]])) h++;
			que[--h]=p;p--;
		}
		if (p==tot) continue;
		int lef=h,rig=t-1;
		while (lef<=rig)
		{
			int M=(lef+rig)/2;
			if (yi[que[M]]-xi[que[M]]*b[i]>=yi[que[M+1]]-xi[que[M+1]]*b[i]) lef=M+1;
			else rig=M-1;
		}
		f[le][i]=std::min(f[le][i],yi[que[lef]]-xi[que[lef]]*b[i]+i*b[i]);
	}
	for (int i=mid+1;i<=r;i++) f[le][i]=std::min(f[le][i],yi[que[t]]-xi[que[t]]*b[i]+i*b[i]);
}

void cdq(int l,int r,int le)
{
	if (l==r) return;
	int mid=(l+r)/2;
	cdq(l,mid,le);
	b[mid]=a[mid];
	for (int i=mid-1;i>=l;i--) b[i]=std::max(b[i+1],a[i]);
	b[mid+1]=a[mid+1];
	for (int i=mid+2;i<=r;i++) b[i]=std::max(b[i-1],a[i]);
	trans1(l,r,le);
	trans2(l,r,le);
	cdq(mid+1,r,le);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int mx=0;
	for (int i=1;i<=n;i++) mx=std::max(mx,a[i]),f[1][i]=mx*i;
	for (int j=2;j<=m;j++)
	{
		for (int i=j-1;i<=n;i++) f[j][i]=inf;
		cdq(j-1,n,j);
	}
	printf("%d\n",f[m][n]);
	return 0;
}