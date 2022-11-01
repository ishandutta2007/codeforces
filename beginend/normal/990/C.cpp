#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=300005;
const int inf=1000000000;

int n,t1[N],t2[N];
char str[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",str);
		int len=strlen(str),mn=0,s=0;
		for (int j=0;j<len;j++)
		{
			if (str[j]=='(') s++;
			else s--;
			mn=std::min(mn,s);
		}
		if (mn>=0) t1[s]++;
		if (s-mn<=0) t2[-s]++;
	}
	LL ans=0;
	for (int i=0;i<=300000;i++) ans+=(LL)t1[i]*t2[i];
	printf("%I64d",ans);
	return 0;
}