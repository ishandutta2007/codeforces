#include<cstdio>
#define MAXN 1010
double dp[MAXN][MAXN];
int a[MAXN];
int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%d",a+i);
	for(int i=0;i<N;i++)
		for(int j=0;j<i;j++)
			if(a[i]<a[j])
				dp[j][i]=1.0;
	double qx[MAXN];
	double qy[MAXN];
	for(int i=0;i<M;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--; y--;
		if(x>y)
		{
			int tmp=x;
			x=y;
			y=tmp;
		}
		for(int j=0;j<x;j++)
			qx[j]=(dp[j][x]+dp[j][y])/2;
		for(int j=y+1;j<N;j++)
			qx[j]=(dp[x][j]+dp[y][j])/2;
		for(int j=x+1;j<y;j++)
			//xj invers per = (1+xj-yj)/2
			//jy invers per = (1+xj-yj)/2
			qx[j]=(1+dp[x][j]-dp[j][y])/2;
		for(int j=0;j<x;j++)
			dp[j][x]=dp[j][y]=qx[j];
		for(int j=y+1;j<N;j++)
			dp[x][j]=dp[y][j]=qx[j];
		for(int j=x+1;j<y;j++)
		{
			dp[x][j]=qx[j];
			dp[j][y]=1-qx[j];
		}
		dp[x][y]=0.5;
	}
	double res=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<i;j++)
			res+=dp[j][i];
	printf("%.12lf",res);
}