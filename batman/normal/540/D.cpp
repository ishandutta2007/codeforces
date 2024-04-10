#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll N=110;

ll r,s,p;
ld dp[3][N][N][N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>r>>s>>p;
	for(int i=1;i<N;i++)dp[0][i][0][0]=dp[1][0][i][0]=dp[2][0][0][i]=1;
	for(int i=0;i<=r;i++)
		for(int j=0;j<=s;j++)
			for(int k=0;k<=p;k++)
			{
				if(!(i || j) || !(i || k) || !(j || k))continue;
				ll x1=i*j,x2=j*k,x3=i*k,sum=x1+x2+x3;
				for(int q=0;q<3;q++)
				{
					if(j)dp[q][i][j][k]+=x1*dp[q][i][j-1][k];
					if(k)dp[q][i][j][k]+=x2*dp[q][i][j][k-1];
					if(i)dp[q][i][j][k]+=x3*dp[q][i-1][j][k];
					dp[q][i][j][k]/=(ld)sum;
				}
			}
	cout<<fixed<<setprecision(12)<<dp[0][r][s][p]<<" "<<dp[1][r][s][p]<<" "<<dp[2][r][s][p]<<"\n";
  	return 0;
}