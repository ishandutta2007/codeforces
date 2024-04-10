#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,k,Test_num;
LL ans;
LL a[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL C(LL x)
{
	return x*(x-1)/2;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(k),ans=0;
		for(int i=1;i<=n;++i)read(a[i]),a[i]+=a[i-1];
		if(k<=n)
		{
			for(int i=1;i<=n-k+1;++i)ans=max(ans,a[i+k-1]-a[i-1]);
			ans+=C(k);
		}
		else ans=a[n]+(LL)(k-n)*n+C(n);
		printf("%lld\n",ans);
	}
	return 0;
}