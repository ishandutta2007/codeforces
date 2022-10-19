#include<bits/stdc++.h>
#define Mx 29
using namespace std;
int n,k,t,ok0,ok1;
int a[10002],b[10002],c[10002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),read(k);
	for(int i=2;i<=n;++i)printf("or 1 %d\n",i),fflush(stdout),read(b[i]);
	for(int i=2;i<=n;++i)printf("and 1 %d\n",i),fflush(stdout),read(c[i]);
	puts("or 2 3"),fflush(stdout),read(t);
	for(int i=Mx;~i;--i)
	{
		ok0=0,ok1=1;
		for(int j=2;j<=n;++j)ok0|=((c[j]>>i)&1),ok1&=((b[j]>>i)&1);
		if(ok1 && (ok0 || !((t>>i)&1)))
		{
			a[1]|=(1<<i);
			for(int j=2;j<=n;++j)a[j]|=(((c[j]>>i)&1)<<i);
		}
		else for(int j=2;j<=n;++j)a[j]|=(((b[j]>>i)&1)<<i);
	}
	sort(a+1,a+n+1),printf("finish %d",a[k]),fflush(stdout);
	return 0;
}