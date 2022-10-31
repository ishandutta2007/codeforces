#include<bits/stdc++.h>

const int N=10005;

int n;
char str[N];
bool vis[N];

int main()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	int l=1,r=n,s=0;
	while (l<r)
	{
		while (l<r&&str[l]==')') l++;
		while (l<r&&str[r]=='(') r--;
		if (l>=r) break;
		vis[l]=vis[r]=1;
		s++;
		l++;r--;
	}
	if (!s) {puts("0");return 0;}
	puts("1");
	printf("%d\n",s*2);
	for (int i=1;i<=n;i++)
		if (vis[i]) printf("%d ",i);
	return 0;
}