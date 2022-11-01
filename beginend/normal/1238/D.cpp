#include<bits/stdc++.h>

typedef long long LL;

const int N=300005;

int n;
char str[N];

int main()
{
	scanf("%d%s",&n,str+1);
	LL ans=0;
	int ls=0;
	for (int i=1;i<=n;i++)
	{
		if (i==1||str[i]==str[i-1]) ls++,ans+=i-1-(ls<i);
		else ans+=i-1-ls,ls=1;
	}
	printf("%lld\n",ans);
	return 0;
}