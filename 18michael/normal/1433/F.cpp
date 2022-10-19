#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,k,m1;
int p[72][72],f[72][72],g[72][72],a[72][72];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),read(m),read(k),m1=(m>>1);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=m1;++j)
			for(int l=0;l<k;++l)
				a[j][l]=-inf;
		a[0][0]=0;
		for(int j=1;j<=m;++j)
		{
			read(p[i][j]);
			for(int l=m1;l;--l)
				for(int o=0;o<k;++o)
					a[l][o]=max(a[l][o],a[l-1][(((o-p[i][j])%k)+k)%k]+p[i][j]);
		}
		for(int j=0;j<k;++j)
		{
			g[i][j]=-inf;
			for(int l=0;l<=m1;++l)
				g[i][j]=max(g[i][j],a[l][j]);
		}
	}
	for(int i=0;i<=n;++i)
		for(int j=0;j<k;++j)
			f[i][j]=-inf;
	f[0][0]=0;
	for(int i=1;i<=n;++i)
		for(int j=0;j<k;++j)
			for(int l=0;l<k;++l)
				f[i][(j+l)%k]=max(f[i][(j+l)%k],f[i-1][j]+g[i][l]);
	return 0&printf("%d",f[n][0]);
}