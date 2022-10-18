#include<bits/stdc++.h>
using namespace std;
void chkmax(int &x,int y){x=max(x,y);}
const int MAXN=2e5;
int n,a[2][MAXN+5],dp[MAXN+5][4][2],msk[MAXN+5];
int main(){
	cin>>n;
	for(int i=0;i<2;i++)for(int j=1;j<=n;j++)
		scanf("%1d",&a[i][j]),msk[j]+=(1<<i)*a[i][j];
	memset(dp,192,sizeof(dp));dp[1][1][0]=0;
	if(a[1][1])dp[1][3][0]=1;
	for(int i=1;i<n;i++)for(int j=0;j<4;j++)for(int k=0;k<2;k++)if(dp[i][j][k]>=0){
		for(int S=msk[i+1];;--S&=msk[i+1]){
			if((j>>(k^1)&1)&&(S>>k&1))continue;
			int nwk;
			if(j==0)nwk=k;else if(j==1)nwk=0;else if(j==2)nwk=1;else nwk=k^1;
			chkmax(dp[i+1][S][nwk],dp[i][j][k]+__builtin_popcount(S));
			if(!S)break;
		}
	}
	int res=0;
	for(int i=0;i<4;i++)for(int j=0;j<2;j++)chkmax(res,dp[n][i][j]);
	cout<<res<<endl;
	return 0;
}