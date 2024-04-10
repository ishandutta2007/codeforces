#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=65005;

int n;
char str[N];

int main()
{
	scanf("%d%s",&n,str+1);
	long long ans=0;
	for (int i=1;i<=n;i++)
		if ((str[i]-'0')%2==0) ans+=i;
	printf("%lld\n",ans);
	return 0;
}