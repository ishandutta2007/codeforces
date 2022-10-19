#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int n,X,mn,mx,ans,Test_num;
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
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(X),ans=0,mn=inf,mx=-inf;
		for(int i=1;i<=n;++i)
		{
			read(a[i]);
			if(max(mx,a[i])-min(mn,a[i])>(X<<1))++ans,mn=mx=a[i];
			else mx=max(mx,a[i]),mn=min(mn,a[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}