#include<cstdio>
double dp[30][30][201];
int main()
{
	int n,kk;
	scanf("%d%d",&n,&kk);
	int arr[30];
	for(int i=0;i<n;i++) scanf("%d",arr+i);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(arr[i]>arr[j]) dp[i][j][0]=1;
	for(int x=1;x<=kk;x++)
	{
		for(int k=0;k<n;k++)
		{
			for(int l=k;l<n;l++)
			{
				for(int i=0;i<n;i++)
					for(int j=i+1;j<n;j++)
					{
						int ii=i;
						int jj=j;
						int swap=0;
						if(k<=i && i<=l)
						{
							ii=k+l-i;
							swap++;
						}
						if(k<=j && j<=l)
						{
							jj=k+l-j;
							swap++;
						}
						if(swap==2) dp[jj][ii][x]+=1-dp[i][j][x-1];
						else dp[ii][jj][x]+=dp[i][j][x-1];
					}
			}
		}
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				dp[i][j][x]/=n*(n+1)/2;
	}
	double ans=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			ans+=dp[i][j][kk];
	printf("%.12lf",ans);
}