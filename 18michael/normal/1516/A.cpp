#include<bits/stdc++.h>
using namespace std;
int n,k,Test_num;
int a[102];
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
		read(n),read(k);
		for(int i=1;i<=n;++i)read(a[i]);
		for(int i=1;i<n && k;++i)while(a[i] && k)--a[i],++a[n],--k;
		for(int i=1;i<=n;++i)printf("%d%c",a[i],i==n? '\n':' ');
	}
	return 0;
}