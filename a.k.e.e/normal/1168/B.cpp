#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN=300005;

int n;
char s[MAXN];
int calc(int len)
{
	int x[11],res=0;
	for(int i=1;i<=n-len+1;i++)
	{
		bool flag=1;
		for(int j=1;j<=len;j++)
			x[j]=s[i+j-1]-'0';
		for(int j=1;j<=len;j++)
		{
			for(int k=1;j-k>0 && j+k<=len;k++)
				if(x[j]==x[j-k] && x[j]==x[j+k])
					{flag=0;break;}
			if(!flag)break;
		}
		if(flag)++res;
	}
	return res;
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	ll ans=(ll)n*(n+1)/2;
	for(int i=1;i<=8;i++)
		ans-=calc(i);
	printf("%lld\n",ans);
	return 0;
}