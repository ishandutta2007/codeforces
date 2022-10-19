#include<bits/stdc++.h>
#define Mx 200000
using namespace std;
int n,t=0,sum=0;
int a[102],f[200002];
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
	for(int i=1;i<=n;++i)read(a[i]),t=__gcd(t,a[i]);
	for(int i=1;i<=n;++i)a[i]/=t,sum+=a[i];
	if(sum&1)return 0&puts("0");
	f[0]=1;
	for(int i=1;i<=n;++i)
		for(int j=Mx;j>=a[i];--j)
			f[j]|=f[j-a[i]];
	if(!f[sum/2])return 0&puts("0");
	for(int i=1;i<=n;++i)if(a[i]&1)return 0&printf("1\n%d",i);
	return 0;
}