#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

char a[1005],b[1005];

int check(char c)
{
	if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return 1;
	else return 0;
}

int main()
{
	scanf("%s%s",a+1,b+1);
	int n=strlen(a+1),m=strlen(b+1);
	if (n!=m) puts("No");
	else
	{
		for (int i=1;i<=n;i++)
			if (check(a[i])!=check(b[i])) {puts("No");return 0;}
		puts("Yes");
	}
	return 0;
}