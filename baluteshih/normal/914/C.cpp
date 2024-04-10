#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <bitset>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

long long pas[1001][1001],dp[1001];
const long long MOD=1e9+7;
bitset<1001> n;

void build()
{
	pas[0][0]=1;
	for(long long i=1;i<=1000;pas[i][0]=1,i++)
		for(long long j=1;j<=1000;j++)
			pas[i][j]=(pas[i-1][j]+pas[i-1][j-1])%MOD;
}

long long C(long long n,long long m)
{
	if(m<0) return 0;
	return pas[n][m];
}

long long get_dp(long long n)
{
	if(n==1) return 0;
	if(dp[n]) return dp[n];
	long long counts=0;
	for(long long tmp=n;tmp;tmp/=2)
		if(tmp&1) counts++;
	dp[counts]=get_dp(counts); 
	return dp[counts]+1;
}

int main()
{
	long long i,k,high,ans,counts=0,x,ANS=0,L;
	build();
	for(i=2;i<=1000;i++)
		dp[i]=get_dp(i);
	cin >> n >> k;
	if(k==0)
	{
		cout << "1\n";
		return 0;
	}
	for(high=1000;!n[high];high--) ;
	L=n.count(); 
	for(x=1;x<=1000;x++)
	{
		if(dp[x]+1==k)
		{
			counts=L;
			ans=(pas[high][x]);
			for(ans=(ans+C(0,x-counts))%MOD,i=0;i<high;i++)
				if(n[i]) counts--,ans=(ans+C(i,x-counts))%MOD;
			if(x==1) ans=(ans-1+MOD)%MOD;
			ANS=(ANS+ans)%MOD;
		}
	}
	cout << ANS << "\n"; 
}