#include<bits/stdc++.h>
using std::min;
using std::max;
typedef long long ll;

int n,k,a[1<<20],b[1<<20];
int c[1<<20],d[1<<20];
bool dp[1<<10][1<<10][2]; 
void exec()
{
	scanf("%d",&n);
	int c[2]={0,0};
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),a[i]=a[i]&1,c[a[i]]++;
	dp[0][0][0]=1;
	dp[0][0][1]=0;
	for(int i=0;i<=100;i++)
		for(int ii=0;ii<=100;ii++)
		{
			if(i)dp[i][ii][0]|=
			!dp[i-1][ii][(ii+1)&1],
			dp[i][ii][1]|=
			!dp[i-1][ii][(ii)&1];
			if(ii)dp[i][ii][0]|=
			!dp[i][ii-1][(ii+1)&1],
			dp[i][ii][1]|=
			!dp[i][ii-1][(ii)&1];
			//printf("%d %d (%d,%d)\n",i,ii
		//,dp[i][ii][0],dp[i][ii][1]);
		}
	//fprintf(stderr,"%d %d %d \n",c[0],c[1],dp[c[0]][c[1]][0]);
	puts(dp[c[0]][c[1]][0]? "Alice":"Bob");
}

int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}