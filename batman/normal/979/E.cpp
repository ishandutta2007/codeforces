#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)52)
#define MOD ((ll)1e9+7)

int n,tvn2[N],C[N][N],dp[N][N][N][N];
int ans;
bool p;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>p;
	tvn2[0]=1;for(int i=1;i<N;i++)tvn2[i]=tvn2[i-1]*2%MOD;
	for(int i=0;i<N;i++)C[i][i]=C[i][0]=1;
	for(int i=1;i<N;i++)for(int j=1;j<i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	dp[0][0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
	//	cout<<i<<"||| "<<endl;
		int x;cin>>x;
		for(int w0=0;w0<i;w0++)
			for(int w1=0;w1<i-w0;w1++)
				for(int b0=0;b0<i-w0-w1;b0++)
				{
					int b1=i-1-w0-w1-b0;
				//	cout<<w0<<" "<<w1<<" "<<b0<<" "<<b1<<endl;
					if(x==0 || x==-1)
					{
						for(int j=0;j<=w1;j++)
							dp[i][w0][w1][b0+(j%2==1)]+=1LL*C[w1][j]*tvn2[i-1-w1]%MOD*dp[i-1][w0][w1][b0]%MOD,
							dp[i][w0][w1][b0+(j%2==1)]%=MOD;
					}
					if(x==1 || x==-1)
					{
						for(int j=0;j<=b1;j++)
							dp[i][w0+(j%2==1)][w1+(j%2==0)][b0]+=1LL*C[b1][j]*tvn2[i-1-b1]%MOD*dp[i-1][w0][w1][b0]%MOD,
							dp[i][w0+(j%2==1)][w1+(j%2==0)][b0]%=MOD;
					}
				}
	}

	//	cout<<i<<"|||||||||||| \n";
		for(int w0=0;w0<=n;w0++)
			for(int w1=0;w1<=n-w0;w1++)
				for(int b0=0;b0<=n-w0-w1;b0++)
				{
					int b1=n-w0-w1-b0;
			//		if(dp[i][w0][w1][b0])cout<<w0<<" "<<w1<<" "<<b0<<" "<<b1<<" "<<dp[i][w0][w1][b0]<<"\n";
					if((w1+b1)%2==p)ans+=dp[n][w0][w1][b0],ans%=MOD;
				}
	cout<<ans<<"\n";
	return 0;
}