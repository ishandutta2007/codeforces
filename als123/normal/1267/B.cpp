#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

const int maxn=3e5+7;

using namespace std;

int n,cnt;
int a[maxn],b[maxn];
char s[maxn];

int main()
{
	n=strlen(s+1);
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)
	{
		if ((i==1) || (s[i]!=s[i-1]))
		{
			a[++cnt]=s[i]-'A';
			b[cnt]=1;
		}
		else b[cnt]++;
	}
	if ((cnt&1) && (b[cnt/2+1]>=2))
	{
		int flag=1;
		for (int i=1;i<=cnt/2;i++)
		{
			if ((a[i]!=a[cnt-i+1]) || (b[i]+b[cnt-i+1]<3))
			{
				flag=0;
				break;
			}
		}
		if (flag) printf("%d\n",b[cnt/2+1]+1);
		     else printf("0\n");
	}
	else printf("0\n");
}