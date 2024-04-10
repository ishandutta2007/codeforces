#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n;int p[1000002];
LL a[1000002],f[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL gcd(LL a,LL b)
{
	return b? gcd(b,a%b):a;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=2;i<=n;++i)read(p[i]);
	for(int i=n;i>1;--i)a[p[i]]+=a[i];
	for(int i=1;i<=n;++i)for(LL j=1,t=a[1]/gcd(a[1],a[i]);j*t<=n;++j)++f[j*t];
	for(int i=n;i;--i)if(f[i]==i){f[i]=1;for(int j=2;j*i<=n;++j)f[i]+=f[j*i];}else f[i]=0;
	return 0&printf("%lld",f[1]);
}