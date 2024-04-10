#include<bits/stdc++.h>
using namespace std;
int n;
int a[2002],pre1[2002],pre2[2002],f[2002],g[2002];
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
	for(int i=1;i<=n;++i)read(a[i]),pre1[i]=pre1[i-1]+(a[i]==1),pre2[i]=pre2[i-1]+(a[i]==2);
	for(int i=1;i<=n;++i)f[i]=pre1[i];
	for(int i=1;i<=n;++i)
	{
		g[i]=g[i-1];
		for(int j=0;j<=i;++j)g[i]=max(g[i],f[j]+pre2[i]-pre2[j]);
	}
	for(int i=1;i<=n;++i)
	{
		f[i]=f[i-1];
		for(int j=0;j<=i;++j)f[i]=max(f[i],g[j]+pre1[i]-pre1[j]);
	}
	for(int i=1;i<=n;++i)
	{
		g[i]=g[i-1];
		for(int j=0;j<=i;++j)g[i]=max(g[i],f[j]+pre2[i]-pre2[j]);
	}
	return 0&printf("%d",g[n]);
}