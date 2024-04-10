#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int n,vis[15];
char str[100005];

int main()
{
	scanf("%d",&n);
	scanf("%s",str+1);
	for (int i=1;i<=n;i++)
		if (str[i]=='L')
		{
			for (int j=1;j<=10;j++) if (!vis[j]) {vis[j]=1;break;}
		}
		else if (str[i]=='R')
		{
			for (int j=10;j>=1;j--) if (!vis[j]) {vis[j]=1;break;}
		}
		else vis[str[i]-'0'+1]=0;
	for (int i=1;i<=10;i++) printf("%d",vis[i]);
	return 0;
}