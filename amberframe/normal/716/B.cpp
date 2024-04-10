#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>
using namespace std;

typedef long long LL;
const int maxn = 100005;

char str[maxn];
int bac[maxn],cnt,sum;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("word.in","r",stdin);
		freopen("word.out","w",stdout);
	#endif
	scanf("%s",str+1);
	int len=strlen(str+1);
	if (len<26) {
		puts("-1");return 0;
	}
	for (int i=1;i<=26;i++) {
		if (str[i]=='?') ++sum;
		else if (!bac[str[i]]++) ++cnt;
	}
	if (sum+cnt==26) {
		for (int i=1;i<=26;i++)
		if (str[i]=='?') {
			int j='A';while (bac[j]) ++j;
			bac[j]=1;str[i]=j;
		}
		for (int k=1;k<=len;k++)
		if (str[k]=='?') str[k]='A';
		printf("%s",str+1);
		return 0;
	}
	for (int i=27;i<=len;i++)
	{
		if (str[i-26]=='?') sum--;
		else if (!--bac[str[i-26]]) cnt--;
		if (str[i]=='?') sum++;
		else if (!bac[str[i]]++) cnt++;
		if (cnt+sum==26) {
			for (int k=i-25;k<=i;k++)
			if (str[k]=='?') {
				int j='A';while (bac[j]) ++j;
				bac[j]=1;str[k]=j;
			}
			for (int k=1;k<=len;k++)
			if (str[k]=='?') str[k]='A';
			printf("%s",str+1);
			return 0;
		}
	}
	puts("-1");
	return 0;
}