#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,m,t=0,cnt=0,ans=1;
int k[500002],rt[500002],siz[500002];
int a[500002][2];
bool u[500002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
int main()
{
	read(n),read(m),++m;
	for(int i=1;i<=m;++i)rt[i]=i,siz[i]=1;
	for(int i=1;i<=n;++i)
	{
		read(k[i]);
		for(int j=0;j<k[i];++j)read(a[i][j]);
		if(k[i]==1)a[i][1]=m;
		getroot(a[i][0]),getroot(a[i][1]);
		if(rt[a[i][0]]!=rt[a[i][1]])siz[rt[a[i][1]]]+=siz[rt[a[i][0]]],rt[rt[a[i][0]]]=rt[a[i][1]],u[i]=1,++t;
	}
	for(int i=1;i<=m;++i)
	{
		getroot(i);
		if(rt[i]==i)cnt+=siz[i]-1;
	}
	for(int i=1;i<=cnt;++i)ans=(ans<<1)%mod;
	printf("%d %d\n",ans,t);
	for(int i=1;i<=n;++i)if(u[i])printf("%d ",i);
	return 0;
}