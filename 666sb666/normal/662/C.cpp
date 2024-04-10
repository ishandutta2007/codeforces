#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1<<20,M=1e5+5;
int n,m,a[M],cnt[N];
LL f[N],g[N];
inline void FWT(int n,LL*a)
{
	for(int i=1;i<n;i<<=1)
		for(int j=0;j<n;j+=(i<<1))
			for(int k=0;k<i;k++)
			{
				LL x=a[j+k],y=a[i+j+k];
				a[j+k]=x+y;a[i+j+k]=x-y;
			}
}
inline void UFWT(int n,LL*a)
{
	for(int i=1;i<n;i<<=1)
		for(int j=0;j<n;j+=(i<<1))
			for(int k=0;k<i;k++)
			{
				LL x=a[j+k],y=a[i+j+k];
				a[j+k]=(x+y)/2;a[i+j+k]=(x-y)/2;
			}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=1;j<=m;j++)
		{
			char ch=getchar();
			while(ch!='0'&&ch!='1')ch=getchar();
			a[j]|=((ch-'0')<<i);
		}
	for(int i=1;i<=m;i++)f[a[i]]++;
	for(int S=1;S<(1<<n);S++)cnt[S]=cnt[S^(S&-S)]+1;
	for(int S=0;S<(1<<n);S++)g[S]=min(cnt[S],cnt[(1<<n)-1-S]);
	FWT(1<<n,f);FWT(1<<n,g);
	for(int i=0;i<(1<<n);i++)f[i]*=g[i];
	UFWT(1<<n,f);
	int ans=f[0];
	for(int i=0;i<(1<<n);i++)ans=min(ans,(int)f[i]);
	printf("%d\n",ans);
	return 0;
}