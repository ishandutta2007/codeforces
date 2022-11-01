#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=1000005;

int n;
char s[N];
bool vis[N];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int l=1,r=n;
	while (l<r)
	{
		if (s[l]==s[r]) vis[l]=vis[r]=1,l++,r--;
		else if (l+1==r) vis[l]=1,l=r+1;
		else if (s[l+1]==s[r]) vis[l+1]=vis[r]=1,l+=2,r--;
		else if (s[r-1]==s[l]) vis[l]=vis[r-1]=1,l++,r-=2;
		else vis[l+1]=vis[r-1]=1,l+=2,r-=2;
	}
	for (int i=1;i<=n;i++) if (vis[i]) putchar(s[i]);
	return 0;
}