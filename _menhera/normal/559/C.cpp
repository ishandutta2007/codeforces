#include<cstdio>
#include<algorithm>
using namespace std;
const int MOD=1000000007;
int dp[2020];
pair<int, int> P[2020];
int H,W,N;
int fact[202020];
int invfact[202020];
int pow(int a,int b)
{
	if(b==0) return 1;
	if(b==1) return a;
	int v=pow(a,b/2);
	int ans=1LL*v*v%MOD;
	if(b&1) ans=1LL*ans*a%MOD;
	return ans;
}
int modinv(int a)
{
	return pow(a,MOD-2);
}
int comb(int a,int b)
{
	return (1LL*((1LL*fact[a]*invfact[b])%MOD)*invfact[a-b])%MOD;
}
int main()
{
	scanf("%d%d%d",&H,&W,&N);
	fact[0]=1;
	for(int i=1;i<202010;i++) fact[i]=(1LL*i*fact[i-1])%MOD;
	for(int i=0;i<202010;i++) invfact[i]=modinv(fact[i]);
	for(int i=0;i<N;i++)
	{
		int A,B;
		scanf("%d%d",&A,&B);
		P[i]=make_pair(A,B);
	}
	sort(P,P+N);
	int ans=comb(H+W-2,H-1);
	for(int i=0;i<N;i++)
	{
		int X=P[i].first;
		int Y=P[i].second;
		dp[i]=comb(X+Y-2,X-1);
		for(int j=0;j<i;j++)
		{
			int SX=P[j].first;
			int SY=P[j].second;
			if(SX<=X && SY <= Y)
			{
				dp[i]-=1LL*dp[j]*comb(X+Y-SX-SY,X-SX)%MOD;
				dp[i]+=MOD;
				dp[i]%=MOD;
			}
		}
		ans-=1LL*dp[i]*comb(H+W-X-Y,H-X)%MOD;
		ans+=MOD;
		ans%=MOD;
	}
	printf("%d",ans);
	return 0;
}