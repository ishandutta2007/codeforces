#include<bits/stdc++.h>
using namespace std;
int t;
char s[500005];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%s",s);
		bool b=true;
		int n=strlen(s);
		int p=0;
		for (int i=0;i<n;++i)
		{
			if (s[i]=='A')
				++p;
			else
				--p;
			if (p<0)
				b=false;
		}
		puts(b&&(s[n-1]=='B')?"YES":"NO");
	}
	return 0;
}