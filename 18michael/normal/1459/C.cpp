#include<cstdio>
#define LL long long
int n,m;LL T=0;
LL a[200002],b[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL abs(LL x)
{
	return x>0? x:-x;
}
inline LL gcd(LL a,LL b)
{
	return b? gcd(b,a%b):a;
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=m;++i)read(b[i]);
	for(int i=2;i<=n;++i)T=gcd(T,abs(a[i]-a[1]));
	for(int i=1;i<=m;++i)printf("%lld ",gcd(T,a[1]+b[i]));
	return 0;
}