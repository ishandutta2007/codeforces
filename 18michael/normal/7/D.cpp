#include<cstdio>
#include<cstring>
#define LL long long
int len,mx=0;LL ans=0;
int R[10000002],dp[5000002];
char s[10000002];
inline int min(int x,int y)
{
	return x<y? x:y;
}
inline int max(int x,int y)
{
	return x>y? x:y;
}
int main()
{
	scanf("%s",s+1),len=strlen(s+1),dp[0]=0;
	for(int i=len;i;--i)s[2*i-1]=s[i],s[2*i-2]='#';
	len=2*len-1;
	for(int i=1;i<=len;++i)
	{
		if(i<=mx+R[mx]-1)R[i]=min(R[2*mx-i],max(mx+R[mx]-1-i,0));
		while(i+R[i]<=len && i-R[i]>0 && s[i+R[i]]==s[i-R[i]])++R[i];
		if(i+R[i]-1>mx+R[mx]-1)mx=i;
	}
	for(int i=1;i<=len;++i)dp[i]=(R[i]==i? dp[i/2]+1:0),ans+=dp[i];
	return 0&printf("%lld",ans);
}