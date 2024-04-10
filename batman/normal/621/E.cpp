#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define N (101)
#define MOD ((ll)1e9+7)

int n,b,k,x;
ll e[N][N],ans[N][N],ex[N][N];

void tavan()
{
	ans[0][0]=1;
	while(b)
	{
		if(b%2)
		{
				for(int i=0;i<x;i++)
					for(int j=0;j<x;j++)
					{
						ex[i][j]=0;
						for(int k=0;k<x;k++)
							ex[i][j]+=ans[i][k]*e[k][j],ex[i][j]%=MOD;
					}
				for(int i=0;i<x;i++)
					for(int j=0;j<x;j++)
						ans[i][j]=ex[i][j];	
		}
		b/=2;
		for(int i=0;i<x;i++)
			for(int j=0;j<x;j++)
			{
				ex[i][j]=0;
				for(int k=0;k<x;k++)
				ex[i][j]+=e[i][k]*e[k][j],ex[i][j]%=MOD;
			}
		for(int i=0;i<x;i++)
			for(int j=0;j<x;j++)
				e[i][j]=ex[i][j];
	}
}

int main()
{
	scanf("%d%d%d%d",&n,&b,&k,&x);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		for(int j=0;j<x;j++)
			e[j][(j*10+a)%x]++;
	}
	tavan();
	printf("%I64d",ans[0][k]);
    return 0;
}