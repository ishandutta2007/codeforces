
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int a[101]={};
int dp[101][(1<<16)]={},way[101][(1<<16)]={};

const int prm[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

int table[54]={};

void out(int now_x,int now_y)
{
	if(!now_x)return;
	out(now_x-1,now_y^table[way[now_x][now_y]]);
	printf("%d ",way[now_x][now_y]);
}

int main()
{
	int n=0;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	for(int i=1;i<=58;i++)
	{
		for(int j=0;j<16;j++)
		{
			if(i%prm[j]==0)
			{
				table[i]^=(1<<j);
			}
		}
	}
                                 
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(1<<16);j++)
		{
			dp[i][j]=1e9;
			for(int k=1;k<=58;k++)
			{
				if((table[k]|j)!=j)continue;
				int tmp=abs(k-a[i])+dp[i-1][j^table[k]];
				if(tmp<dp[i][j])dp[i][j]=tmp,way[i][j]=k;
			}
		}
	}
	
	out(n,(1<<16)-1);
}