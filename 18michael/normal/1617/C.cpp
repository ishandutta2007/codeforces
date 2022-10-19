#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
int n,t,Test_num;
bool ok;
int a[100002];
bool u[100002];
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
		read(n),ok=1,t=n;
		for(int i=1;i<=n;++i)u[i]=0;
		for(int i=1;i<=t;++i)
		{
			read(a[i]);
			if(a[i]<=n && !u[a[i]])u[a[i]]=1,--i,--t;
		}
		sort(a+1,a+t+1),t=1;
		for(int i=1;i<=n;++i)
		{
			if(u[i])continue;
			if(2*i>=a[t])
			{
				ok=0;
				break;
			}
			++t;
		}
		printf("%d\n",ok? t-1:-1);
	}
	return 0;
}