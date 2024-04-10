#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,Test_num,sum=0;
LL ans,res;
LL a[102],b[102],pre[102];
LL f[2][10002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),ans=0,res=inf,f[0][0]=0;
		for(int i=1;i<=n;++i)read(a[i]),pre[i]=a[i],ans+=a[i]*a[i]*(n-1);
		for(int i=1;i<=n;++i)read(b[i]),pre[i]+=pre[i-1]+b[i],sum+=max(a[i],b[i]),ans+=b[i]*b[i]*(n-1);
		for(int i=1;i<=sum;++i)f[0][i]=inf;
		for(int i=1,i0=0,i1=1;i<=n;++i,i0^=1,i1^=1)
		{
			for(int j=0;j<=sum;++j)f[i1][j]=inf;
			for(int j=0;j<=sum;++j)
				if(f[i0][j]<inf)
				{
					if(j+a[i]<=sum)f[i1][j+a[i]]=min(f[i1][j+a[i]],f[i0][j]+a[i]*j+b[i]*(pre[i-1]-j));
					if(j+b[i]<=sum)f[i1][j+b[i]]=min(f[i1][j+b[i]],f[i0][j]+b[i]*j+a[i]*(pre[i-1]-j));
				}
		}
		for(int i=0;i<=sum;++i)res=min(res,f[n&1][i]);
		printf("%lld\n",ans+2*res);
	}
	return 0;
}