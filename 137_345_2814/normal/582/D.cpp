#include<cstdio>
#include<cstring>
using namespace std;
#define N 3550
#define mod 1000000007
int p,a,s[N],le,dp[N][N][2][2],len;
int t[N],t2[N];
char v[N];
int main()
{
	scanf("%d%d%s",&p,&a,v+1);
	if(a>3400){printf("0\n");return 0;}
	len=strlen(v+1);
	for(int i=1;i<=len;i++)t[len-i]=v[i]-'0';
	while(1)
	{
		int fg=0;
		long long st=0;
		for(int j=len;j>=0;j--)
		{
			st=st*10+t[j];
			t2[j]=st/p;
			if(t2[j])fg=1; 
			st%=p;
		}
		s[++le]=st;
		if(!fg)break;
		for(int j=len;j>=0;j--)t[j]=t2[j];
	}
	dp[1][0][0][0]=1;
	for(int i=1;i<=le;i++)
	for(int j=0;j<=le;j++)
	for(int s1=0;s1<2;s1++)
	for(int s2=0;s2<2;s2++)
	for(int s3=0;s3<2;s3++)
	for(int s4=0;s4<2;s4++)
	if(dp[i][j][s3][s4])
	{
	//	printf("%d %d %d %d %d\n",i,j,s3,s4,dp[i][j][s3][s4]);
		int t1=s1==s3,t2=s2==s4;
		int as=0;
		if(s1&&s2)as=1ll*(p-2-s[i])*(p-1-s[i])%mod*(mod+1)/2%mod;
		else if(!s1&&!s2)as=1ll*(s[i]-1)*s[i]%mod*(mod+1)/2%mod;
		else if(s1&&!s2)as=1ll*(p-1+s[i]+1)*(p-s[i]-1)%mod*(mod+1)/2%mod*(s[i]!=p-1);
		else if(s2&&!s1)as=1ll*(p-1+p-s[i])*s[i]%mod*(mod+1)/2%mod*(s[i]!=0);
		if(t1)as=(as+(s2?p-1-s[i]:s[i]))%mod;
		if(t2)as=(as+(s1?p-1-s[i]:s[i]))%mod;
		if(t1&&t2)as++;
//		printf("%d %d %d %d -> %d %d %d %d : %d\n",i,j,s3,s4,i+1,j+s2,s1,s2,as);
		dp[i+1][j+s2][s1][s2]=(dp[i+1][j+s2][s1][s2]+1ll*dp[i][j][s3][s4]*as)%mod;
	}
	int as=0;
	for(int i=a;i<=3500;i++)as=(as+dp[le+1][i][0][0])%mod;
	printf("%d\n",as);
}