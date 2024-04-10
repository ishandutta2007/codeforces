#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=300005;
int n,m;
const int MOD=998244353;
const int Inv2=499122177;
int add (int x,int y){x=x+y;return x>=MOD?x-MOD:x;}
int dec (int x,int y){x=x-y;return x<0?x+MOD:x;}
int mul (int x,int y){return (LL)x*y%MOD;}
int Pow (int x,int y)
{
	int t=1;
	while (y)
	{
		if (y&1) t=mul(t,x);
		x=mul(x,x);y>>=1;
	}
	return t;
}
int JC[N],inv[N];
int f[N],pw[N],h[N];
void Init (int n)
{
	h[0]=1;h[1]=1;for (int u=2;u<=n;u++) h[u]=add(h[u-1],mul(u-1,h[u-2])); 
	f[0]=1;for (int u=2;u<=n;u++) f[u]=mul(f[u-2],u-1);
	JC[0]=1;for (int u=1;u<=n;u++) JC[u]=mul(JC[u-1],u);
	inv[n]=Pow(JC[n],MOD-2);
	for (int u=n;u>=1;u--) inv[u-1]=mul(inv[u],u);
	pw[0]=1;for (int u=1;u<=n;u++) pw[u]=mul(pw[u-1],2);
	//printf("%d %d\n",f[2],mul(2,Inv2));
}
int C (int x,int y)
{
	return x<y?0:mul(JC[x],mul(inv[y],inv[x-y]));
}
int dp[100][100];
int calc (int x)
{
	//if (x==0) return 1;
	int t=n-x;
	return C(t,x);
}
int main()
{
	Init(300000);
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		int ans=0;
//		dp[0][0]=1;
//		dp[1][0]=1;
//		for (int u=2;u<=n;u++)
//		{
//			dp[u][0]=1;
//			for (int i=1;i<=u;i++)
//			dp[u][i]=add(dp[u-1][i],dp[u-2][i-1]);
//		}
		for (int u=0;u*2<=n;u+=2)
		{
			int t=n-u*2;
		//	printf("%d %d %d\n",u,dp[n][u],calc(u));
			int t1=mul(pw[u/2],mul(calc(u),f[u]));
			ans=add(ans,mul(t1,h[t]));
			continue;
//			int sum=0;
//			for (int i=0;i*2<=t;i++)
//			{
//				sum=add(sum,mul(C(t,i*2),f[i*2]));
//				//ans=add(ans,mul(t1,mul(C(t,i*2),f[i*2])));
//			}
//			printf("%d %d\n",sum,h[t]);
//			ans=add(ans,mul(sum,t1));
		}
		printf("%d\n",ans);
	}
	return 0;
}