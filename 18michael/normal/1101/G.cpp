#include<bits/stdc++.h>
#define Mx 29
using namespace std;
int n,p=0,ans=0;
int a[32];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void insert(int x)
{
	for(int i=Mx;~i;--i)
		if((x>>i)&1)
		{
			if(!a[i])
			{
				a[i]=x,++ans;
				return ;
			}
			x^=a[i];
		}
}
int main()
{
	read(n);
	for(int i=1,x;i<=n;++i)read(x),p^=x,insert(p);
	return 0&printf("%d",p? ans:-1);
}