#include<bits/stdc++.h>
using namespace std;
char s[100],s1[100];
int n,b1,b2;
int main()
{
	scanf("%s",s);
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%s",s1);
		if (s[0]==s1[0]&&s[1]==s1[1])
		{
			puts("YES");
			return 0;
		}
		if (s[0]==s1[1])
			b1=1;
		if (s[1]==s1[0])
			b2=1;
	}
	if (b1&b2)
		puts("YES");
	else
		puts("NO");
	return 0;
}