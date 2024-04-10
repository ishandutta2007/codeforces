#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	char ch[2];
	int flag=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			scanf("%s",ch);
			if (ch[0]!='W'&&ch[0]!='G'&&ch[0]!='B') flag=1;
		}
	if (flag) printf("#Color");
	else printf("#Black&White");
	return 0;
}