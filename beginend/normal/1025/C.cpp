#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n,a[N],f[N];
char s[N];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++) s[n+i]=s[i];
	for (int i=1;i<n*2;i++) a[i]=(s[i]!=s[i+1]);
	int ans=0;
	for (int i=1;i<n*2;i++)
	{
		if (a[i]) f[i]=f[i-1]+1;
		else f[i]=0;
		ans=std::max(ans,f[i]);
	}
	ans=std::min(ans,n-1);
	printf("%d\n",ans+1);
	return 0;
}