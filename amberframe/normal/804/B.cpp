#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
const int maxn = 1000005;

char str[maxn];LL ans,cur;int n;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("steps.in","r",stdin);
		freopen("steps.out","w",stdout);
	#endif
	scanf("%s",str+1);n=strlen(str+1);
	for (int i=1;i<=n;i++)
	if (str[i]=='a') cur=(cur*2+1)%mod;
	else (ans+=cur)%=mod;
	printf("%lld",ans);
	return 0;
}