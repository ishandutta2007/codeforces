#include<bits/stdc++.h>
using namespace std;
int n;
int a[502][502]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool check(int x,int y)
{
	return (x>0 && x<=n && y>0 && y<=n && x>=y && !a[x][y]);
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(a[i][i]);
	for(int i=n,nx,ny;i;--i)
	{
		nx=ny=i;
		for(int j=a[i][i];j;--j)
		{
			a[nx][ny]=a[i][i];
			if(check(nx,ny+1))++ny;
			else if(check(nx+1,ny))++nx;
			else --ny;
		}
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=i;++j)printf("%d%c",a[i][j],j==i? '\n':' ');
	return 0;
}