#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,sq;
LL ans=0,res=0;
int bl[100002],st[322],ed[322],id[100002],s_t[322],t[322];
int s[322][322];
LL a[100002],b[100002],lazk[322],lazb[322];
typedef pair<LL,int> P;
P mx;
inline bool cmp(int x,int y)
{
	return a[x]<a[y];
}
inline void maintain(int x)
{
	for(int i=st[x];i<=ed[x];++i)b[i]+=lazk[x]*a[i];
	s_t[x]=lazk[x]=0,t[x]=1;
	for(int i=st[x];i<=ed[x];++i)
	{
		if(s_t[x] && a[s[x][s_t[x]]]==a[id[i]] && b[id[i]]<=b[s[x][s_t[x]]])continue;
		for(;s_t[x] && b[s[x][s_t[x]]]<=b[id[i]];--s_t[x]);
		for(;s_t[x]>1 && ceil(1.0*(b[s[x][s_t[x]-1]]-b[s[x][s_t[x]]])/(a[s[x][s_t[x]]]-a[s[x][s_t[x]-1]]))>=ceil(1.0*(b[s[x][s_t[x]]]-b[id[i]])/(a[id[i]]-a[s[x][s_t[x]]]));--s_t[x]);
		s[x][++s_t[x]]=id[i];
	}
}
inline P getmx(int x)
{
	for(;t[x]<s_t[x] && a[s[x][t[x]]]*lazk[x]+b[s[x][t[x]]]<=a[s[x][t[x]+1]]*lazk[x]+b[s[x][t[x]+1]];++t[x]);
	return P(a[s[x][t[x]]]*lazk[x]+b[s[x][t[x]]]+lazb[x],s[x][t[x]]);
}
int main()
{
	scanf("%d",&n),sq=sqrt(n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]),b[i]=a[i],bl[i]=(i-1)/sq+1,id[i]=i;
	for(int i=1;i<=bl[n];++i)st[i]=(i-1)*sq+1,ed[i]=min(i*sq,n),sort(id+st[i],id+ed[i]+1,cmp),maintain(i);
	for(int i=1;i<=n;++i)
	{
		mx=P(-inf,0);
		for(int j=1;j<=bl[n];++j)mx=max(mx,getmx(j));
		ans=max(ans,res+=mx.first);
		if(mx.second>1)
		{
			for(int j=1;j<bl[mx.second-1];++j)lazb[j]+=a[mx.second];
			for(int j=st[bl[mx.second-1]];j<mx.second;++j)b[j]+=a[mx.second];
		}
		if(mx.second<n)
		{
			for(int j=mx.second+1;j<=ed[bl[mx.second+1]];++j)b[j]+=a[j];
			for(int j=bl[mx.second+1]+1;j<=bl[n];++j)++lazk[j];
		}
		b[mx.second]=-inf,maintain(bl[mx.second]);
	}
	return 0&printf("%lld",ans);
}