#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;

int n;
LL f[N][15];
char s[N];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	LL ans=0;
	for (int i=1;i<=n;i++)
	{
		int x=s[i]-'0';
		if (x) f[i][x]++;
		for (int j=0;j<=10;j++) if (x<j) f[i][(j*(j-1)/2+x+10)%11]+=f[i-1][j];
		for (int j=0;j<=10;j++) ans+=f[i][j];
	}
	printf("%lld\n",ans);
	return 0;
}