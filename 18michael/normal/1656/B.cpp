#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,k,Test_num;
bool ok;
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
		read(n),read(k),ok=0;
		for(int i=1;i<=n;++i)read(a[i]);
		sort(a+1,a+n+1);
		for(int i=1,j=1;i<=n;++i)
		{
			while(j<=n && a[i]+k>a[j])++j;
			if(j<=n && a[i]+k==a[j])
			{
				ok=1;
				break;
			}
		}
		puts(ok? "YES":"NO");
	}
	return 0;
}