#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,t,l,Test_num;
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
		read(n),t=0,l=1;
		for(int i=1;i<=n;++i)read(a[i]);
		for(;;)
		{
			for(;l<=n && !a[l];++l,++t);
			if(l>n)break;
			for(int i=n;i>l;--i)a[i]-=a[i-1];
			if(!t)++l;
			else --t;
			sort(a+l,a+n+1);
		}
		printf("%d\n",a[n]);
	}
	return 0;
}