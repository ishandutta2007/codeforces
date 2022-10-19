#include<cstdio>
int n,x,ans=0;
int dif[1000002]={};
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
	for(int i=2;i<=n;++i)x=((n/i)&1),dif[1]^=x,dif[i]^=x,x=(n%i),dif[1]^=1,dif[x+1]^=1;
	for(int i=1;i<=n;++i)dif[i]^=dif[i-1],read(x),ans^=(x^(dif[i]*i));
	printf("%d",ans);
	return 0;
}