#include<bits/stdc++.h>
using namespace std;
int n,ok,Test_num;
int a[52];
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
		read(n),ok=1;
		for(int i=1;i<=n;++i)read(a[i]);
		for(int i=1;i<=n;++i)if(a[i]!=i)ok=0;
		if(ok)puts("0");
		else if(a[1]==1 || a[n]==n)puts("1");
		else if(a[1]!=n || a[n]!=1)puts("2");
		else puts("3");
	}
	return 0;
}