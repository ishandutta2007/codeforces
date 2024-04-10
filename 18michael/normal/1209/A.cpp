#include<bits/stdc++.h>
using namespace std;
int n,t=0;
int a[102],u[102]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		if(!u[i])
		{
			++t;
			for(int j=i;j<=n;++j)
				if(!(a[j]%a[i]))
					u[j]=1;
		}
	return 0&printf("%d",t);
}