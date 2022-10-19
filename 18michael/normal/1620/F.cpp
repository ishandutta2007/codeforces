#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,z,val,Test_num;
int a[1000002];
int f[1000002][2][2];
typedef pair<int,int> P;
P p;
P from[1000002][2][2];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void upd(int x,int y,int w)
{
	if(w<f[z][x][y])f[z][x][y]=w,from[z][x][y]=p;
}
inline void calc(int x,int y)
{
	if(x==inf || y==inf)return ;
	val=a[z];
	if(val>y)
	{
		if(val<x)upd(1,0,x);
		else upd(0,0,y);
	}
	val=-a[z];
	if(val>y)
	{
		if(val<x)upd(1,1,x);
		else upd(0,1,y);
	}
}
inline void print(int x,int y,int z)
{
	if(x>1)print(x-1,from[x][y][z].first,from[x][y][z].second);
	printf("%d%c",z? -a[x]:a[x],x==n? '\n':' ');
}
inline void solve()
{
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		for(int j=0;j<2;++j)for(int k=0;k<2;++k)f[i][j][k]=inf;
	}
	a[0]=inf,f[0][0][0]=f[0][0][1]=f[0][1][0]=f[0][1][1]=-inf;
	for(int i=0;i<n;++i)z=i+1,p=P(0,0),calc(a[i],f[i][0][0]),p=P(0,1),calc(-a[i],f[i][0][1]),p=P(1,0),calc(f[i][1][0],a[i]),p=P(1,1),calc(f[i][1][1],-a[i]);
	for(int i=0;i<2;++i)for(int j=0;j<2;++j)if(f[n][i][j]<inf)return puts("YES"),print(n,i,j);
	puts("NO");
}
int main()
{
	read(Test_num);
	while(Test_num--)solve();
	return 0;
}