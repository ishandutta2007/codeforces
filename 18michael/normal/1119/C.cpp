#include<cstdio>
int n,m,x;
int a[2][502][502]={},b[2][502][502]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			read(x),a[0][i][j]=a[0][i][j-1]+x,a[1][i][j]=a[1][i-1][j]+x;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			read(x),b[0][i][j]=b[0][i][j-1]+x,b[1][i][j]=b[1][i-1][j]+x;
	for(int i=1;i<=n;++i)if((a[0][i][m]&1)!=(b[0][i][m]&1))return 0&puts("No");
	for(int i=1;i<=m;++i)if((a[1][n][i]&1)!=(b[1][n][i]&1))return 0&puts("No");
	return 0&puts("Yes");
}