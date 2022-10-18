#include <iostream>
#include <algorithm> 
#define __ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

const long long MOD=1e9+7;
long long dp[20][1000050],two[1000050];

int main()
{
	long long q,x,y,sum,ans,counts;
	for(x=1,dp[0][x]=1,two[0]=1;x<=1000000;x++)
		dp[0][x]=1,two[x]=two[x-1]*2%MOD;
	for(x=1;x<20;x++)
		for(sum=0,y=0;y<=1000000;y++)
			sum=(dp[x-1][y]+sum)%MOD,dp[x][y]=sum;
	for(x=1,two[0]=1;x<20;x++)
		two[x]=two[x-1]*2;
	cin >> q;
	while(q--)
	{
		cin >> x >> y;
		for(sum=2,ans=1;sum*sum<=x;sum++)
		{
			if(x%sum!=0) continue;
			counts=0;
			while(x%sum==0) counts++,x/=sum;
			ans=ans*dp[counts][y]%MOD;
		}
		if(x!=1)
			ans=ans*dp[1][y]%MOD;
		cout << ans*two[y-1]%MOD << "\n"; 
	}
}