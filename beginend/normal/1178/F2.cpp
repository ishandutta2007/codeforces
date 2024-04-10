#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ls d<<1
#define rs d<<1|1

typedef long long LL;

const int N=1005;
const int M=1000005;
const int MOD=998244353;

int n,m,tot,lef[N],rig[N],f[N][N],id[N],a[M],s[M],mn[M*4];
bool vis[N][N];

int solve(int l,int r)
{
	if (l==r||l>r) return 1;
	if (vis[l][r]) return f[l][r];
	vis[l][r]=1;
	int mn=n+1;
	for (int i=l;i<=r;i++) if (a[id[i]]<mn) mn=a[id[i]];
	if (lef[mn]<l||rig[mn]>r) return 0;
	f[l][r]=1;
	for (int i=lef[mn]+1,p=lef[mn]+1;i<rig[mn];i++)
		if (s[id[i]]==s[id[lef[mn]]]&&(i+1==rig[mn]||id[i+1]>id[i]+1)) f[l][r]=(LL)f[l][r]*solve(p,i)%MOD,p=i+1;
	int s1=0,s2=0;
	for (int i=l;i<=lef[mn];i++) if (s[id[i]-1]==s[id[l]-1]) (s1+=(LL)solve(l,i-1)*solve(i,lef[mn]-1)%MOD)%=MOD;
	for (int i=rig[mn];i<=r;i++) if (s[id[i]]==s[id[rig[mn]]]) (s2+=(LL)solve(rig[mn]+1,i)*solve(i+1,r)%MOD)%=MOD;
	f[l][r]=(LL)f[l][r]*s1%MOD*s2%MOD;
	return f[l][r];
}

void build(int d,int l,int r)
{
	if (l==r) {mn[d]=a[l];return;}
	int mid=(l+r)/2;
	build(ls,l,mid);build(rs,mid+1,r);
	mn[d]=std::min(mn[ls],mn[rs]);
}

int query(int d,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return mn[d];
	int mid=(l+r)/2;
	if (y<=mid) return query(ls,l,mid,x,y);
	else if (x>mid) return query(rs,mid+1,r,x,y);
	else return std::min(query(ls,l,mid,x,y),query(rs,mid+1,r,x,y));
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		if (!lef[a[i]]) lef[a[i]]=i;
		rig[a[i]]=i;
	}
	build(1,1,m);
	for (int i=1;i<=n;i++) if (query(1,1,m,lef[i],rig[i])<i) {puts("0");return 0;}
	for (int i=1;i<=n;i++) s[lef[i]]++,s[rig[i]]--,id[++tot]=lef[i],id[++tot]=rig[i];
	std::sort(id+1,id+tot+1);
	tot=std::unique(id+1,id+tot+1)-id-1;
	for (int i=1;i<=m;i++) s[i]+=s[i-1];
	for (int i=1;i<=n;i++)
	{
		lef[i]=std::lower_bound(id+1,id+tot+1,lef[i])-id;
		rig[i]=std::lower_bound(id+1,id+tot+1,rig[i])-id;
	}
	printf("%d\n",solve(1,tot));
	return 0;
}