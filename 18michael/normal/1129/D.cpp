#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,k,sq;
int a[100002],bl[100002],laz[322],st[322],ed[322],t[100002],la[100002],las[100002],f[100002];
int sumf[322][322];
inline void upd(int &x,int y)
{
	if((x+=y)>=mod)x-=mod;
}
inline void build(int x)
{
	for(int i=st[x];i<=ed[x];++i)t[i]+=laz[x],sumf[x][i-st[x]]=0;
	laz[x]=n;
	for(int i=st[x];i<=ed[x];++i)laz[x]=min(laz[x],t[i]);
	for(int i=st[x];i<=ed[x];++i)upd(sumf[x][t[i]-=laz[x]],f[i-1]);
	for(int i=st[x]+1;i<=ed[x];++i)upd(sumf[x][i-st[x]],sumf[x][i-st[x]-1]);
}
inline void add(int l,int r,int x)
{
	if(l>r)return ;
	if(bl[l]==bl[r])
	{
		for(int i=l;i<=r;++i)t[i]+=x;
		return build(bl[l]);
	}
	for(int i=l;i<=ed[bl[l]];++i)t[i]+=x;
	for(int i=st[bl[r]];i<=r;++i)t[i]+=x;
	build(bl[l]),build(bl[r]);
	for(int i=bl[l]+1;i<bl[r];++i)laz[i]+=x;
}
inline int query(int x)
{
	int res=0;
	for(int i=1;i<=bl[n];++i)
	{
		if(ed[i]>x)
		{
			for(int j=st[i];j<=x;++j)if(t[j]+laz[i]<=k)upd(res,f[j-1]);
			break;
		}
		if(k-laz[i]>=0)upd(res,sumf[i][min(k-laz[i],ed[i]-st[i])]);
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&k),sq=sqrt(n),f[0]=1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),bl[i]=(i-1)/sq+1,la[i]=las[a[i]],las[a[i]]=i;
	for(int i=1;i<=bl[n];++i)st[i]=(i-1)*sq+1,ed[i]=min(i*sq,n),build(i);
	for(int i=1;i<=n;++i)add(la[la[i]]+1,la[i],-1),add(la[i]+1,i,1),f[i]=query(i);
	return 0&printf("%d",f[n]);
}