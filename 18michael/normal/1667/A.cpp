#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,Test_num;
LL las,ans,res,t;
int a[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),ans=inf;
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=0;i<=n;++i)
	{
		//printf("i:%d\n",i);
		res=las=0;
		for(int j=i;j;--j)
		{
			t=(las-1)/a[j];
			while(t*a[j]>=las)--t;
			while((t+1)*a[j]<las)++t;
			//printf("j:%d t:%lld\n",j,t);
			res-=t,las=t*a[j];
		}
		las=-1;
		for(int j=i+1;j<=n;++j)
		{
			t=(las+1)/a[j];
			while(t*a[j]<=las)++t;
			while((t-1)*a[j]>las)--t;
			//printf("j:%d t:%lld\n",j,t);
			res+=t,las=t*a[j];
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}