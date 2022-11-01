#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
char s[105];

bool check(char c)
{
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y';
}

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int flag=0;
	for (int i=1;i<=n;i++)
	{
		if (check(s[i])&&check(s[i-1])) continue;
		putchar(s[i]);
	}
	return 0;
}