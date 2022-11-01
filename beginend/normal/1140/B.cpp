#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=105;

int n;
char str[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%s",&n,str+1);
		int x=0,y=0;
		for (int i=1;i<=n;i++)
			if (str[i]=='<') x++;
			else break;
		for (int i=n;i>=1;i--)
			if (str[i]=='>') y++;
			else break;
		if (x&&y) printf("%d\n",std::min(x,y));
		else printf("%d\n",0);
	}
	return 0;
}