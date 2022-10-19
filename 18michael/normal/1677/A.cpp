#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,Test_num;
LL ans;
int a[5002];
int pre[5002][5002];
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
		read(n),ans=0;
		for(int i=1;i<=n;++i)read(a[i]);
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)pre[i][j]=pre[i][j-1]+(a[j]<a[i]);
		for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)ans+=(pre[i][n]-pre[i][j])*pre[j][i-1];
		printf("%lld\n",ans);
	}
	return 0;
}