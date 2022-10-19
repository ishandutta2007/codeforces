#include<bits/stdc++.h>
using namespace std;
char s[100];
int t,f[100];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%s",s);
		for (int i=0;i<26;++i)
			f[i]=0;
		int n=strlen(s);
		for (int i=0;i<n;++i)
			++f[s[i]-'a'];
		for (int i=0;i<26;++i)
			if (f[i]==2)
			{
				putchar(i+'a');
				putchar(i+'a');
			}
		for (int i=0;i<26;++i)
			if (f[i]==1)
				putchar(i+'a');
		putchar('\n');
	}
	return 0;
}