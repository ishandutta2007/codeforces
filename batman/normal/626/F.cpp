#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=((ll)202);
const ll K=((ll)1010);
const ll MOD=((ll)1e9+7);
ll n,k,a[N],dp[2][K][N];
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	dp[1][0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=k;j++)
			for(int q=0;q<=n;q++)
			{
				ll d=a[i]-((i==0)?a[i]-1:a[i-1]);
				dp[(i&1)][j][q]=0;
				if(j-(q-1)*d>=0 && q-1>=0)dp[(i&1)][j][q]+=dp[!(i&1)][j-(q-1)*d][q-1];
				if(j-q*d>=0)dp[(i&1)][j][q]+=dp[!(i&1)][j-q*d][q]*(q+1);
				if(j-(q+1)*d>=0)dp[(i&1)][j][q]+=dp[!(i&1)][j-(q+1)*d][q+1]*(q+1);
				dp[(i&1)][j][q]%=MOD;
			}
	for(int i=1;i<=k;i++)dp[!(n&1)][i][0]+=dp[!(n&1)][i-1][0];
	cout<<(dp[!(n&1)][k][0]%MOD);
    return 0;
}