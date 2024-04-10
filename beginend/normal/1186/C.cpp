#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=1000005;

int n,m,s[N];
char a[N],b[N];

int main()
{
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	for (int i=1;i<=n;i++)
		if (a[i]=='1') s[i]=s[i-1]+1;
		else s[i]=s[i-1];
	int tot=0;
	for (int i=1;i<=m;i++) if (b[i]=='1') tot++;
	int ans=0;
	for (int i=1;i+m-1<=n;i++)
		if (((s[i+m-1]-s[i-1])&1)==(tot&1)) ans++;
	printf("%d\n",ans);
	return 0;
}