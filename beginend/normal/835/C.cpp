#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=105;

int n,q,c,a[N][N][15];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int main()
{
	n=read();q=read();c=read()+1;
	for (int i=1;i<=n;i++)
	{
		int x=read(),y=read(),s=read();
		a[x][y][s]++;
	}
	for (int k=0;k<c;k++)
		for (int i=1;i<=100;i++)
			for (int j=1;j<=100;j++)
				a[i][j][k]+=a[i-1][j][k]+a[i][j-1][k]-a[i-1][j-1][k];
	while (q--)
	{
		int t=read()%c,x1=read(),y1=read(),x2=read(),y2=read();
		int ans=0;
		for (int i=0;i<c;i++) ans+=(i+t)%c*(a[x2][y2][i]-a[x1-1][y2][i]-a[x2][y1-1][i]+a[x1-1][y1-1][i]);
		printf("%d\n",ans);
	}
	return 0;
}