#include<bits/stdc++.h>
using namespace std;
const int N=200005,M=3005,P=998244353;
int n,m,s,w,a[N],b[N],dp[M][M];
inline int pw(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)r=1ll*r*a%P;return r;}
inline int pr(int a,int b){return 1ll*b*pw(a,P-2)%P;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),s+=b[i],w+=a[i]?b[i]:0;
	dp[0][0]=1;
	for(int i=0;i<m;i++)for(int j=0;j<=i;j++)
	{
		dp[i+1][j]=(dp[i+1][j]+1ll*dp[i][j]*pr(s+j-(i-j),s-w-(i-j)))%P;
		dp[i+1][j+1]=(dp[i+1][j+1]+1ll*dp[i][j]*pr(s+j-(i-j),w+j))%P;
	}
	int ans1=0,ans2=0;
	for(int j=0;j<=m;j++)
	{
		ans1=(ans1+1ll*j*dp[m][j])%P;
		ans2=(ans2+1ll*(m-j)*dp[m][j])%P;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i])
		{
			int t=1ll*b[i]*pw(w,P-2)%P;
			printf("%d\n",(b[i]+1ll*t*ans1)%P);
		}
		else
		{
			int t=1ll*b[i]*pw(s-w,P-2)%P;
			printf("%d\n",(b[i]+P-1ll*t*ans2%P)%P);
		}
	}
	return 0;
}