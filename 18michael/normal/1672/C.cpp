#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,mn,mx,Test_num;
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
		read(n),mn=n,mx=0;
		for(int i=1;i<=n;++i)read(a[i]);
		for(int i=1;i<n;++i)
			if(a[i]==a[i+1])
			{
				mn=min(mn,i);
				mx=max(mx,i+1);
			}
		if(!mx)
		{
			puts("0");
			continue;
		}
		if(mn+1==mx)
		{
			puts("0");
			continue;
		}
		if(mn+2==mx)
		{
			puts("1");
			continue;
		}
		printf("%d\n",mx-mn-2);
	}
	return 0;
}