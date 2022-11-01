#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int n,t[30];
char s[100005];

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) t[s[i]-'a']++;
	for (int i=0;i<26;i++)
		if (t[i]>1) {puts("Yes");return 0;}
	if (n==1) puts("Yes");
	else puts("No");
	return 0;
}