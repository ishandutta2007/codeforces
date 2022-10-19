#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,cnt,Test_num;
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
		read(n),cnt=0;
		for(int i=1;i<=n;++i)read(a[i]),cnt+=(a[i]==1);
		if(!cnt || cnt==n)
		{
			puts("YES");
			continue;
		}
		sort(a+1,a+n+1);
		for(int i=n;i>1;--i)
			if(a[i]-a[i-1]==1)
			{
				cnt=0;
				break;
			}
		puts(cnt? "YES":"NO");
	}
	return 0;
}