#include<bits/stdc++.h>
using namespace std;
int n,k,t,Test_num;
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
		read(n),read(k),t=n+1;
		if(k>(n-1)/2)
		{
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;++i)a[i]=0;
		for(int i=1;i<=k;++i)a[2*i]=(--t);
		for(int i=1;i<=n;++i)if(!a[i])a[i]=(--t);
		for(int i=1;i<=n;++i)printf("%d%c",a[i],i==n? '\n':' ');
	}
	return 0;
}