#include<bits/stdc++.h>
using namespace std;
int n,Testnum,ok;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(Testnum);
	while(Testnum--)
	{
		read(n),ok=0;
		for(int i=1,x,t;i<=n;++i)
		{
			read(x),t=sqrt(x);
			if(t*t!=x)ok=1;
		}
		puts(ok? "YES":"NO");
	}
	return 0;
}