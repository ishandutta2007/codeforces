#include<bits/stdc++.h>
using namespace std;
int n,m,ans,Test_num;
char s[402];
int a[402][402],p[402][402],h[402][402],l[402][402];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int calc(int sx,int sy,int ex,int ey)
{
	return p[ex-1][ey-1]-p[sx][ey-1]-p[ex-1][sy]+p[sx][sy]
	+h[ex][ey-1]-h[ex][sy]+h[sx][ey-1]-h[sx][sy]
	+l[ex-1][ey]-l[sx][ey]+l[ex-1][sy]-l[sx][sy];
}
inline int calc1(int sx,int sy,int ex,int ey)
{
	return p[ex-1][ey-1]-p[sx][ey-1]-p[ex-1][sy]+p[sx][sy]
	+h[sx][ey-1]-h[sx][sy]
	+l[ex-1][sy]-l[sx][sy];
}
inline int calc2(int sx,int sy,int ex,int ey)
{
	return p[ex-1][ey-1]-p[sx][ey-1]-p[ex-1][sy]+p[sx][sy]
	+h[ex][ey-1]-h[ex][sy]+h[sx][ey-1]-h[sx][sy]
	+l[ex-1][sy]-l[sx][sy];
}
inline void Main()
{
	read(n),read(m),ans=16;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			p[i][j]=h[i][j]=l[i][j]=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;++j)a[i][j]=s[j]-'0',h[i][j]=h[i][j-1]+a[i][j],l[i][j]=l[i-1][j]+a[i][j],p[i][j]=p[i-1][j]+h[i][j];
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			h[i][j]=j-h[i][j],l[i][j]=i-l[i][j];
	for(int i=1;i<=n-4;++i)
		for(int j=1;j<=m-3;++j)
			ans=min(ans,calc(i,j,i+4,j+3));
	for(int i=1;i<=n-4;++i)
		for(int j=1;j<=m-3;++j)
			for(int i1=i+4;i1<=n;++i1)
			{
				if(calc1(i,j,i1,j+3)>=ans)break;
				for(int j1=j+3;j1<=m;++j1)
				{
					if(calc2(i,j,i1,j1)>=ans)break;
					ans=min(ans,calc(i,j,i1,j1));
				}
			}
	printf("%d\n",ans);
}
int main()
{
	for(read(Test_num);Test_num--;)
	Main();
	return 0;
}