#include<bits/stdc++.h>
#define Mx 20
using namespace std;
int n,ans=0;
int mn[2097162]={};
struct aaa
{
	int fir,sec;
}mx[2097162]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void merge(aaa &x,aaa y)
{
	if(!x.fir)x=y;
	else if(y.fir)
	{
		if(y.fir>x.fir)
		{
			x.sec=x.fir,x.fir=y.fir;
			if(y.sec>x.sec)x.sec=y.sec;
		}
		else if(y.fir>x.sec)x.sec=y.fir;
	}
}
inline bool check(int x)
{
	for(int i=x;;i=(i-1)&x)
	{
		if(mn[i] && mx[x^i].sec && mn[i]<mx[x^i].sec)return 1;
		if(!i)return 0;
	}
}
int main()
{
	read(n);
	for(int i=1,x;i<=n;++i)
	{
		read(x);if(!mn[x])mn[x]=i;
		mx[x].sec=mx[x].fir,mx[x].fir=i;
	}
	for(int i=0;i<=Mx;++i)
		for(int j=(1<<(Mx+1))-1;~j;--j)
			if(!((j>>i)&1))
			{
				if(!mn[j] || (mn[j^(1<<i)] && mn[j]>mn[j^(1<<i)]))mn[j]=mn[j^(1<<i)];
				merge(mx[j],mx[j^(1<<i)]);
			}
	for(int i=Mx;~i;--i)if(check(ans|(1<<i)))ans|=(1<<i);
	return 0&printf("%d",ans);
}