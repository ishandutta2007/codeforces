#include<cstdio>
#include<cstring>
#define LL long long
int ls,lt,l=1,r=1;LL ans=0;
char A[6]={'R','R','G','B','B','G'},B[6]={'G','B','B','G','R','R'},s[1000002],t[1000002];
int cnt[1000002][6];
int main()
{
	scanf("%s%s",s+1,t+1),ls=strlen(s+1),lt=strlen(t+1);
	for(int i=2;i<=lt;++i)for(int j=0;j<6;++j)cnt[i][j]=cnt[i-1][j]+(t[i-1]==A[j] && t[i]==B[j]);
	for(int i=1;i<=ls;++i)
	{
		for(l+=(t[l]==s[i-1]),r+=(r<lt && s[i-1]==t[r]);r<lt && t[r]!=s[i];)++r;ans+=r-l+1;
		if(l<r)for(int j=0;j<6;++j)if(s[i-1]==A[j] && s[i]==B[j])ans-=cnt[r][5-j]-cnt[l][5-j];
	}
	return 0&printf("%lld",ans);
}