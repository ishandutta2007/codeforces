#include<bits/stdc++.h>
using namespace std;
int t,n;
char s[100005];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		if (n==1||s[1]<=s[2])
		{
			printf("%c%c\n",s[1],s[1]);
		}
		else
		{
			int p=1;
			for (int i=2;i<=n;++i)
				if (s[i]<=s[i-1])
					p=i;
				else
					break;
			for (int i=1;i<=p;++i)
				putchar(s[i]);
			for (int i=p;i>=1;--i)
				putchar(s[i]);
			putchar('\n');
		}
	}
	return 0;
}