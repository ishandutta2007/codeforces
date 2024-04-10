#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,Test_num;
int a[1000002],id[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int x,int y)
{
	return a[x]>a[y];
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n);
		for(int i=1;i<=n;++i)read(a[i]),id[i]=i;
		for(int i=n;i;--i)a[i]-=a[i-1];
		sort(id+1,id+n+1,cmp);
		for(int i=1;i<=n;++i)printf("%d%c",id[i],i==n? '\n':' ');
	}
	return 0;
}