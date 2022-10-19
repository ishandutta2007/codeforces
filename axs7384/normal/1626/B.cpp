#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t;
char s[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%s",s);
		int n=strlen(s);
		int p=1;
		for (int i=n-1;i;--i)
			if (s[i]-'0'+s[i-1]-'0'>=10)
			{
				p=i;
				break;
			}
		for (int i=0;i<p-1;++i)
			putchar(s[i]);
		printf("%d",s[p]-'0'+s[p-1]-'0');
		for (int i=p+1;i<n;++i)
			putchar(s[i]);
		puts("");
	}
	return 0;
}