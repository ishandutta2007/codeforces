#include<cstdio>
#include<cstring>
using namespace std;
#define N 505
#define mod 1000000007
char s[N],v2[11]="abcdABCD";
int ty[8]={255,3855,13107,21845,65280,61680,52428,43690};
int dp[N][65540],ct,n,v,b,v3[65540];
void fwt1(int *a)
{
	for(int i=2;i<=1<<16;i<<=1)
	for(int j=0;j<1<<16;j+=i)
	for(int k=j;k<j+(i>>1);k++)
	a[k+(i>>1)]=(a[k+(i>>1)]+a[k])%mod;
}
void fwt2(int *a)
{
	for(int i=2;i<=1<<16;i<<=1)
	for(int j=0;j<1<<16;j+=i)
	for(int k=j;k<j+(i>>1);k++)
	a[k]=(a[k+(i>>1)]+a[k])%mod;
}
void fwt3(int *a)
{
	for(int i=2;i<=1<<16;i<<=1)
	for(int j=0;j<1<<16;j+=i)
	for(int k=j;k<j+(i>>1);k++)
	a[k+(i>>1)]=(a[k+(i>>1)]-a[k]+mod)%mod;
}
void fwt4(int *a)
{
	for(int i=2;i<=1<<16;i<<=1)
	for(int j=0;j<1<<16;j+=i)
	for(int k=j;k<j+(i>>1);k++)
	a[k]=(mod-a[k+(i>>1)]+a[k])%mod;
}
int solve(int l,int r)
{
	if(l==r)
	{
		int s1=++ct;
		if(s[l]=='?')
		for(int j=0;j<8;j++)dp[s1][ty[j]]=1;
		else for(int j=0;j<8;j++)if(s[l]==v2[j])dp[s1][ty[j]]=1;
		return s1;
	}
	int mid=l+1,v4=1;
	for(int i=l+1;i<=r;i++)
	{
		if(s[i]=='(')v4++;
		if(s[i]==')')v4--;
		if(!v4){mid=i+1;break;}
	}
	if(s[l]!='(')mid=l+1;
	if(mid==r+1)return solve(l+1,r-1);
	int s1=++ct;
	int v1=solve(l,mid-1),v2=solve(mid+1,r);
	if(s[mid]!='|')
	{
		fwt2(dp[v1]);fwt2(dp[v2]);
		for(int i=0;i<1<<16;i++)v3[i]=1ll*dp[v1][i]*dp[v2][i]%mod;
		fwt4(v3);fwt4(dp[v1]);fwt4(dp[v2]);
		for(int i=0;i<1<<16;i++)dp[s1][i]=(dp[s1][i]+v3[i])%mod;
	}
	if(s[mid]!='&')
	{
		fwt1(dp[v1]);fwt1(dp[v2]);
		for(int i=0;i<1<<16;i++)v3[i]=1ll*dp[v1][i]*dp[v2][i]%mod;
		fwt3(v3);
		for(int i=0;i<1<<16;i++)dp[s1][i]=(dp[s1][i]+v3[i])%mod;
	}
	return s1;
}
int main()
{
	scanf("%s",s+1);
	int tp=solve(1,strlen(s+1));
	scanf("%d",&n);
	while(n--)
	{
		int tp1=0;
		for(int j=0;j<4;j++)scanf("%d",&v),tp1=tp1*2+v;scanf("%d",&b);
		for(int j=0;j<1<<16;j++)if(((j>>tp1)&1)^b)dp[tp][j]=0;
	}
	int as=0;for(int j=0;j<1<<16;j++)as=(as+dp[tp][j])%mod;
	printf("%d\n",as);
}