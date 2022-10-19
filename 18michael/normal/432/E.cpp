#include<bits/stdc++.h>
using namespace std;
int n,m;
char c[102][102]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline char find(int x,int y)
{
	if(c[x-1][y]!='A' && c[x][y-1]!='A' && c[x][y+1]!='A')return 'A';
	if(c[x-1][y]!='B' && c[x][y-1]!='B' && c[x][y+1]!='B')return 'B';
	if(c[x-1][y]!='C' && c[x][y-1]!='C' && c[x][y+1]!='C')return 'C';
	return 'D';
}
inline void paint(int sx,int ex,int sy,int ey,char C)
{
	for(int i=sx;i<=ex;++i)
		for(int j=sy;j<=ey;++j)
			c[i][j]=C;
}
inline void solve(int x,int y)
{
	int t=0;char C=find(x,y);
	while(x+t<n && y+t<m && !c[x][y+t+1] && find(x,y+t+1)==C)++t;
	paint(x,x+t,y,y+t,C);
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(!c[i][j])solve(i,j);
			printf("%c",c[i][j]);
		}
		puts("");
	}
	return 0;
}