#include<cstdio>
#include<cstring>
using namespace std;
#define N 1000050
int s1,s2,s3;
long long mod=998244353,dp[N];
long long hash[N][3],ch=1283,pw[N],mod2=1000000009;
long long gethash(int x,int len){return ((hash[x+len][0]-hash[x-1][0]*pw[len+1])%mod2+mod2)%mod2;}
char t1[N],t2[N],t3[N];
int main()
{
	scanf("%s%s%s",t1+1,t2+1,t3+1);pw[0]=1;
	s1=strlen(t1+1);s2=strlen(t2+1);s3=strlen(t3+1);
	for(int i=1;i<=s1;i++)hash[i][0]=(hash[i-1][0]*ch+t1[i])%mod2,pw[i]=pw[i-1]*ch%mod2;
	for(int i=1;i<=s2;i++)hash[i][1]=(hash[i-1][1]*ch+t2[i])%mod2;
	for(int i=1;i<=s3;i++)hash[i][2]=(hash[i-1][2]*ch+t3[i])%mod2;
	dp[s1+1]=1;
	for(int i=s1;i>0;i--)
	{
		dp[i]=dp[i+1];
		int lb=i+s2+1,rb=i+s3-1;
		if(t1[i]=='0')
		{
			if(t2[1]=='0')
			dp[i]=(dp[i]+dp[i+1]-dp[i+2]+mod)%mod;
			continue;
		}
		if(i+s2>s1+1)continue;
		int ls=1,rs=s2,ans=0;
		while(ls<=rs)
		{
			int mid=(ls+rs)>>1;
			if(gethash(i,mid-1)==hash[mid][1])
			ans=mid,ls=mid+1;
			else
			rs=mid-1;
		}
		if(t1[i+ans]>=t2[ans+1]||ans==s2)lb--;
		if(i+s3>s1+1)
		rb=s1+1;
		else
		{
			int ls=1,rs=s3,ans=0;
			while(ls<=rs)
			{
				int mid=(ls+rs)>>1;
				if(gethash(i,mid-1)==hash[mid][2])
				ans=mid,ls=mid+1;
				else
				rs=mid-1;
			}
			if(t1[i+ans]<=t3[ans+1]||ans==s3)rb++;
		}
		dp[i]=(dp[i]+dp[lb]-dp[rb+1]+mod)%mod;
	}
	printf("%d\n",(dp[1]-dp[2]+mod*2)%mod);
}