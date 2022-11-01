#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=5005;

int n;
char s[N],t[N];

bool check()
{
	for (int i=1;i<=n/2;i++)
		if (t[i]!=t[n-i+1]) return 0;
	for (int i=1;i<=n;i++)
		if (s[i]!=t[i]) return 1;
	return 0;
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<n;i++)
	{
		int p=0;
		for (int j=i+1;j<=n;j++) t[++p]=s[j];
		for (int j=1;j<=i;j++) t[++p]=s[j];
		if (check()) {printf("%d\n",1);return 0;}
	}
	for (int i=1;i<=n/2;i++)
	{
		int p=0;
		for (int j=n-i+1;j<=n;j++) t[++p]=s[j];
		for (int j=i+1;j<n-i+1;j++) t[++p]=s[j];
		for (int j=1;j<=i;j++) t[++p]=s[j];
		if (check()) {printf("%d\n",2);return 0;}
	}
	puts("Impossible");
}