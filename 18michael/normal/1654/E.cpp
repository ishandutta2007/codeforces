#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#include<bits/stdc++.h>
#define Mx 100000
#define Mx1 31900000
#define LL long long
using namespace std;
int n,ans=0,sq,vec_t=0;
int a[100002],cnt[200002],vec[200002],t[32000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),sq=sqrt(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=0;i<=sq;++i)
	{
		for(int j=1;j<=n;++j)++t[a[j]+j*i];
		for(int j=1;j<=n;++j)ans=max(ans,t[a[j]+j*i]),t[a[j]+j*i]=0;
	}
	for(int i=-sq;i<0;++i)
	{
		for(int j=1;j<=n;++j)++t[a[j]+j*i+Mx1];
		for(int j=1;j<=n;++j)ans=max(ans,t[a[j]+j*i+Mx1]),t[a[j]+j*i+Mx1]=0;
	}
	for(int i=1,x;i<=n;++i)
	{
		for(int j=max(1,i-Mx/sq);j<i;++j)
			if(j!=i && !((a[i]-a[j])%(i-j)))
			{
				x=(a[i]-a[j])/(i-j)+Mx;
				if(!cnt[x])vec[++vec_t]=x;
				++cnt[x];
			}
		while(vec_t)ans=max(ans,cnt[vec[vec_t]]+1),cnt[vec[vec_t]]=0,--vec_t;
	}
	return 0&printf("%d",n-ans);
}