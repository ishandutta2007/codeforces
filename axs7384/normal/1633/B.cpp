#include<bits/stdc++.h>
using namespace std;
int t;
char s[200005];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%s",s);
		int l=strlen(s),n0=0,n1=0;
		for (int i=0;i<l;++i)
			if (s[i]=='0')
				++n0;
			else
				++n1;
		printf("%d\n",min(n0,n1)-(n0==n1));
	}
}