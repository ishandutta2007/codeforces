#include<cstdio>
#define LL long long
LL n,m,t,ans=1;
char s[100005];
int main()
{
	scanf("%lld%lld%s",&n,&m,s+2),s[0]=s[1]='#';
	for(int i=1;i<=n;++i)
	{
		if(s[i+1]==s[i-1])++t;else t=0;
		if(s[i+1]!=s[i])ans+=n*(m-1)-t-1;
	}
	return 0&printf("%lld",ans);
}