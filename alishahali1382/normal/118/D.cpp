#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int n,m,c,d;
int dp[105][105][15][15];
int mod=1e8;

int f(int n1,int n2,int k1,int k2)
{
	if(n1<0 || n2<0 || k1>c || k2>d){
		return 0;
	}
	if(n1==0 && n2==0){
		return 1;
	}
	if(dp[n1][n2][k1][k2]!=-1){
		return dp[n1][n2][k1][k2];
	}
	dp[n1][n2][k1][k2]=(f(n1-1,n2,k1+1,0)+f(n1,n2-1,0,k2+1))%mod;
	return dp[n1][n2][k1][k2];
}

int main()
{
    cin>>n>>m>>c>>d;
    memset(dp,-1,sizeof(dp));
	cout<<f(n,m,0,0);
    return 0;
}