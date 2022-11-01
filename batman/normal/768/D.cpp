#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)1010)
#define M ((ll)10010)
#define K ((ll)52)

ld tavan(ld x,ll y){ld res=1;while(y){res*=y%2?x:1;x*=x;y/=2;}return res;}

ll k,q;
ld dp[M][N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>k>>q;
	for(int i=0;i<M;i++)dp[i][0]=1;
	for(ll i=1;i<M;i++)
		for(int j=1;j<=min(i,N-1);j++)
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*tavan((ld)(j-1)/j,i-1);
	
	for(int i=0;i<q;i++)
	{
		ld p;cin>>p;
		p/=(ld)2000;
		for(int j=k;j<M;j++)
			if(dp[j][k]>=p)
			{
				cout<<j<<"\n";
				break;
			}
		//cout<<dp[M-1][k];
	}
	return 0;
}