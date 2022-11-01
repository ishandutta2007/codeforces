#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((int)301*1000)
#define K ((int)30)
#define INF ((ll)1e18)

int n,a[N],ex[N];
ll dp[2][N];
pair <int,int> par[2][N];
vector <int> res;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		dp[0][i]=dp[1][i]=-INF;
		scanf("%d",&a[i]);
		for(int j=i;j>=max(i-K,1);j--)ex[j]=-1;
		ex[i]=a[i];
		for(int j=i-1;j>=max(i-K,1);j--)
		{
			ex[j]=a[j]-ex[j+1];
			if(ex[j]<0)break;
		}
		for(int j=i;j>=max(i-K,1);j--)
		{
			int lst=a[j];
			if(ex[j]>=0 && dp[0][i]<dp[1][j-1]+ex[j])
				dp[0][i]=dp[1][j-1]+ex[j],par[0][i]={j,j};
			if(i!=j && ex[j]>=0 && dp[1][i]<dp[1][j-1]+ex[j])
				dp[1][i]=dp[1][j-1]+ex[j],par[1][i]={j,j};
			for(int k=j+1;k<=i;k++)
			{
				lst=a[k]-lst;
				if(lst<0)break;
				if(ex[k]+lst-a[k]>=0 && dp[0][i]<dp[0][j-1]+ex[k]+lst-a[k])
					dp[0][i]=dp[0][j-1]+ex[k]+lst-a[k],par[0][i]={j,k};
				if(i!=k && ex[k]+lst-a[k]>=0 && dp[1][i]<dp[0][j-1]+ex[k]+lst-a[k])
					dp[1][i]=dp[0][j-1]+ex[k]+lst-a[k],par[1][i]={j,k};
			}
		}
	}
	int p=0,x=n;
	while(x)
	{
		int y=par[p][x].first,z=par[p][x].second;
		for(int i=y;i<z;i++)
			if(a[i]>0)
				res.push_back(i),
				a[i+1]-=a[i],a[i]=0;
		for(int i=x;i>z;i--)
			if(a[i]>0)
				res.push_back(i-1),
				a[i-1]-=a[i],a[i]=0;
		if(y==z)p=1;
		else p=0;
		x=y-1;
	}
	printf("%d\n",res.size());
	for(auto u:res)printf("%d\n",u);
	return 0;
}