#include<cstdio>
#include<cmath>
int n;int a[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void match(int x,int Mx)
{
	if(x+1==Mx)
	{
		for(int i=0;i<Mx;++i)a[i]=Mx-i-1;
		return ;
	}
	if(Mx>x)match(x,(Mx>>1));
	else
	{
		for(int i=Mx;i<=x;++i)a[i]=2*Mx-i-1,a[2*Mx-i-1]=i;
		match(2*Mx-x-2,(Mx>>1));
	}
}
int main()
{
	read(n),printf("%lld\n",1LL*n*(n+1)),match(n,1<<((int)(log(n)/log(2))+1));
	for(int i=0;i<=n;++i)printf("%d ",a[i]);
	return 0;
}