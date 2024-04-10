#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=1000005;

int n,pre[N],suf[N];
char s[N];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=2;i<=n;i++) pre[i]=pre[i-1]+(s[i]=='v'&&s[i-1]=='v');
	for (int i=n-1;i>=1;i--) suf[i]=suf[i+1]+(s[i]=='v'&&s[i+1]=='v');
	LL ans=0;
	for (int i=1;i<=n;i++) if (s[i]=='o') ans+=(LL)pre[i]*suf[i];
	printf("%lld\n",ans);
	return 0;
}