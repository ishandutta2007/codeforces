#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
const ll N=31;
const ll K=201;

ll n,k,a[N];
ld dp[N][N][K];


int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			dp[i][j][0]=(a[i]>a[j]);
	for(int k2=1;k2<=k;k2++)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				for(int p=1;p<=n;p++)
					for(int q=p;q<=n;q++)
					{
						ll new_i=i,new_j=j;
						if(p<=i && i<=q)new_i=q+p-i;
						if(p<=j && j<=q)new_j=q+p-j;
						if(new_i<=new_j)dp[i][j][k2]+=dp[new_i][new_j][k2-1];
						else dp[i][j][k2]+=(ld)1-dp[new_j][new_i][k2-1];
					}
				dp[i][j][k2]/=(ld)n*(n+1)/2;
			}
	ld ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			ans+=dp[i][j][k];
	cout<<fixed<<setprecision(14)<<ans<<"\n";
  	return 0;
}