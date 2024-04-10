#include<bits/stdc++.h>
using namespace std;
int n,Test_num,ok;
int a[100002],b[100002];
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
		for(int i=1;2*i-1<=n;++i)
		{
			read(a[i]);
			if(2*i<=n)read(b[i]);
		}
		sort(a+1,a+(n+1)/2+1),sort(b+1,b+n/2+1);
		for(int i=1;2*i-1<=n;++i)
		{
			if(2*i<=n && b[i]<a[i])ok=0;
			if(i>1 && a[i]<b[i-1])ok=0;
		}
		puts(ok? "YES":"NO");
	}
	return 0;
}