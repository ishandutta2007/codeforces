#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
char s[105];

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int ans=n;
	for (int i=1;i<n;i++)
		if (s[i]!=s[i+1]) ans--,i++;
	printf("%d",ans);
	return 0;
}