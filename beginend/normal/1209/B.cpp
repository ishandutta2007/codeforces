#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=2005;

int n,ans[N];
char s[N];

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		int now=s[i]-'0';
		for (int j=0;j<y;j++) ans[j]+=now;
		for (int j=y;j<=1000;j+=x)
		{
			now^=1;
			for (int k=0;k<x;k++) ans[j+k]+=now;
		}
	}
	int mx=0;
	for (int i=0;i<=1000;i++) mx=std::max(mx,ans[i]);
	printf("%d\n",mx);
	return 0;
}