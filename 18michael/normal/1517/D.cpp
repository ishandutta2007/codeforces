#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,k,edge_t=0;
int d[502][502][4],f[502][502][12];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool check(int x,int y)
{
	return (x>0 && x<=n && y>0 && y<=m);
}
int main()
{
	read(n),read(m),read(k);
	if(k&1)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				printf("-1%c",j==m? '\n':' ');
		return 0;
	}
	k>>=1;
	for(int i=1,x;i<=n;++i)
		for(int j=1;j<m;++j)
			read(x),d[i][j+1][0]=d[i][j][1]=x;
	for(int i=1;i<=n;++i)d[i][1][0]=d[i][m][1]=inf;
	for(int i=1,x;i<n;++i)
		for(int j=1;j<=m;++j)
			read(x),d[i+1][j][2]=d[i][j][3]=x;
	for(int i=1;i<=m;++i)d[1][i][2]=d[n][i][3]=inf;
	for(int l=1;l<=k;++l)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				f[i][j][l]=inf;
				if(check(i-1,j))f[i][j][l]=min(f[i][j][l],f[i-1][j][l-1]+d[i][j][2]);
				if(check(i+1,j))f[i][j][l]=min(f[i][j][l],f[i+1][j][l-1]+d[i][j][3]);
				if(check(i,j-1))f[i][j][l]=min(f[i][j][l],f[i][j-1][l-1]+d[i][j][0]);
				if(check(i,j+1))f[i][j][l]=min(f[i][j][l],f[i][j+1][l-1]+d[i][j][1]);
			}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			printf("%d%c",f[i][j][k]*2,j==m? '\n':' ');
	return 0;
}