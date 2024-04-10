#include<bits/stdc++.h>

const int N=5005;

int n;
char str[N],a[N],b[N];

bool cmp(int x,int y)
{
	int tot=0;
	for (int i=x;i<=n;i++) a[++tot]=str[i];
	if ((n-x+1)&1) for (int i=x-1;i>=1;i--) a[++tot]=str[i];
	else for (int i=1;i<x;i++) a[++tot]=str[i];
	tot=0;
	for (int i=y;i<=n;i++) b[++tot]=str[i];
	if ((n-y+1)&1) for (int i=y-1;i>=1;i--) b[++tot]=str[i];
	else for (int i=1;i<y;i++) b[++tot]=str[i];
	for (int i=1;i<=n;i++)
		if (a[i]<b[i]) return 1;
		else if (a[i]>b[i]) return 0;
	return x<y;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%s",&n,str+1);
		int mx=1;
		for (int i=2;i<=n;i++)
			if (cmp(i,mx)) mx=i;
		for (int i=mx;i<=n;i++) putchar(str[i]);
		if ((n-mx+1)&1) for (int i=mx-1;i>=1;i--) putchar(str[i]);
		else for (int i=1;i<mx;i++) putchar(str[i]);
		puts("");
		printf("%d\n",mx);
	}
	return 0;
}