#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int k[100002],la[2];
int p[100002][2],from[100002][2];
bool dp[100002][2];
int a[100002][2][2];
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
	{
		read(k[i]);
		for(int j=0;j<2;++j)
			for(int l=0;l<2;++l)
				read(a[i][j][l]);
		p[i][0]=p[i-1][0]+(a[i][0][0]<=k[i] && k[i]<=a[i][0][1]),p[i][1]=p[i-1][1]+(a[i][1][0]<=k[i] && k[i]<=a[i][1][1]);
	}
	if(dp[n][0]=(a[n][0][0]<=k[n] && k[n]<=a[n][0][1]))la[0]=n;else la[0]=-1;
	if(dp[n][1]=(a[n][1][0]<=k[n] && k[n]<=a[n][1][1]))la[1]=n;else la[1]=-1;
	for(int i=n-1;~i;--i)
	{
		if(~la[1])a[la[1]][0][0]=max(a[la[1]][0][0],a[i][0][0]),a[la[1]][0][1]=min(a[la[1]][0][1],a[i][0][1]);
		if(~la[0])a[la[0]][1][0]=max(a[la[0]][1][0],a[i][1][0]),a[la[0]][1][1]=min(a[la[0]][1][1],a[i][1][1]);
		if(~la[1])dp[i][0]=((p[la[1]-1][1]-p[i][1]==la[1]-1-i) && (a[la[1]][0][0]<=k[i] && k[i]<=a[la[1]][0][1])),from[i][0]=la[1];
		if(~la[0])dp[i][1]=((p[la[0]-1][0]-p[i][0]==la[0]-1-i) && (a[la[0]][1][0]<=k[i] && k[i]<=a[la[0]][1][1])),from[i][1]=la[0];
		if(dp[i][0])la[0]=i;if(dp[i][1])la[1]=i;
	}
	if(!dp[0][0] && !dp[0][1])return 0&puts("No");
	puts("Yes");if(dp[0][0])t=1;else t=0;
	for(int i=1,j;i<=n;t^=1)for(j=from[i-1][t^1];i<=j;++i)printf("%d ",t);
	return 0;
}