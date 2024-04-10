#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int w,h,Test_num;
LL ans;
int k[4],a[1000002];
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
		read(w),read(h),ans=0;
		for(int i=0;i<4;++i)
		{
			read(k[i]);
			for(int j=1;j<=k[i];++j)read(a[j]);
			ans=max(ans,1LL*(a[k[i]]-a[1])*(i<2? h:w));
		}
		printf("%lld\n",ans);
	}
	return 0;
}