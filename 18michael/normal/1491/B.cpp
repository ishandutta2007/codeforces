#include<bits/stdc++.h>
using namespace std;
int n,u,v,Test_num,ok,ok1;
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
		read(n),read(u),read(v),ok=0,ok1=0;
		for(int i=1;i<=n;++i)read(a[i]),ok|=(i>1 && a[i]!=a[i-1]),ok1|=(i>1 && abs(a[i]-a[i-1])>1);
		printf("%d\n",ok1? 0:min(u,v)+(ok? 0:v));
	}
	return 0;
}