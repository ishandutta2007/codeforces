#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int n,m,t,Test_num;LL A,B,sum;
int a[1000002],b[1000002],mn[1000002],res[1000002];
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
		read(n),read(m),t=A=B=sum=0;
		for(int i=1;i<=n;++i)read(a[i]),sum+=abs(a[i]);
		for(int i=1,x;i<=m;++i)read(x),t=__gcd(t,x);
		for(int i=0;i<t;++i)mn[i]=inf,res[i]=1;
		for(int i=1;i<=n;++i)mn[i%t]=min(mn[i%t],abs(a[i])),res[i%t]*=(a[i]>0? 1:(a[i]<0? -1:0));
		for(int i=0;i<t;++i)A+=(res[i]<0? mn[i]:0),B+=(res[i]>0? mn[i]:0);
		printf("%lld\n",sum-min(A,B)*2);
	}
	return 0;
}