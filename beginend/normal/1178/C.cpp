#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int MOD=998244353;

int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	int ans=1;
	for (int i=1;i<=n+m;i++) ans=ans*2%MOD;
	printf("%d\n",ans);
	return 0;
}