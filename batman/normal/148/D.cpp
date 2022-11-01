#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (1010)
#define INF ((ll)1e15)
#define MOD ((ll)1e9+7)

ll a,b;
ld dp[2][N][N];

int main()
{
	cin>>a>>b;
	dp[0][0][0]=0;dp[1][0][0]=1;
	for(int i=1;i<N;i++)dp[0][0][i]=dp[1][0][i]=0,dp[0][i][0]=dp[1][i][0]=1;
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
		{
			dp[0][i][j]=(ld)i/(ld)(i+j)+(ld)j/(ld)(i+j)*((ld)1-dp[1][i][j-1]);
			dp[1][i][j]=(ld)i/(ld)(i+j)+(ld)j/(ld)(i+j)*((ld)(i)/(ld)(i+j-1)*((ld)1-dp[0][i-1][j-1])+(ld)(j-1)/(ld)(i+j-1)*((j>1)?((ld)1-dp[0][i][j-2]):0));
		}
	cout<<fixed<<setprecision(12)<<dp[0][a][b];	
    return 0;
}