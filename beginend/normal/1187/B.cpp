#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n,m,s[N][26],t[26];
char str[N];

bool check(int x)
{
	for (int i=0;i<26;i++)
		if (s[x][i]<t[i]) return 0;
	return 1;
}

int main()
{
	scanf("%d",&n);
	scanf("%s",str+1);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<26;j++) s[i][j]=s[i-1][j];
		s[i][str[i]-'a']++;
	}
	scanf("%d",&m);
	while (m--)
	{
		scanf("%s",str+1);
		int len=strlen(str+1);
		for (int i=1;i<=len;i++) t[str[i]-'a']++;
		int l=1,r=n;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (check(mid)) r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",r+1);
		for (int i=0;i<26;i++) t[i]=0;
	}
	return 0;
}