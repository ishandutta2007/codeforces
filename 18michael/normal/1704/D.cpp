#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m,Test_num;
LL mx;
int a[1000002];
LL sum[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int num(int x,int y)
{
	return (x-1)*m+y;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m),mx=inf;
		for(int i=1;i<=n;++i)
		{
			sum[i]=0;
			for(int j=1;j<=m;++j)read(a[num(i,j)]),sum[i]+=(LL)a[num(i,j)]*j;
			mx=min(mx,sum[i]);
		}
		for(int i=1;i<=n;++i)if(sum[i]^mx)printf("           %d %d\n",i,sum[i]-mx);
	}
	return 0;
}