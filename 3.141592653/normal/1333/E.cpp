#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
int n;
int v[1111][1111];
int main()
{
	scanf("%d",&n);
	if(n==1||n==2)return puts("-1"),0;
	register int i,ii;
	int t=n*n,x=1,y=0;
	for(;;)
	{
		if(t==0)break;
		while(y<n&&(!v[x][y+1]))v[x][++y]=t--;
		while(x<n&&(!v[x+1][y]))v[++x][y]=t--;
		while(y>1&&(!v[x][y-1]))v[x][--y]=t--;
		while(x>1&&(!v[x-1][y]))v[--x][y]=t--;
	}v[1][1]-=4*n-6;
	for(i=3;i<=n;i++)v[i][1]++;
	for(i=2;i<n;i++)v[n][i]++,v[1][i]++;
	v[n][n]+=n;
	for(i=1;i<=n;i++,puts(""))
		for(ii=1;ii<=n;ii++)printf("%d ",v[i][ii]);
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/