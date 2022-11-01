#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=105;

int n;
char s[N];

bool check(int x,int y)
{
	return x==y||abs(x-y)==2;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		int flag=0;
		for (int i=1;i<=n/2;i++)
			if (!check(s[i]-'a',s[n-i+1]-'a')) {flag=1;break;}
		if (!flag) puts("YES");
		else puts("NO");
	}
	return 0;
}