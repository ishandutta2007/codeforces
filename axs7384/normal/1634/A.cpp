#include<bits/stdc++.h>
using namespace std;
int t,n,m;
char s[100005];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		scanf("%s",s+1);
		int b=1;
		for (int i=1;i<=n;++i)
			if (s[i]!=s[n+1-i])
				b=0;
		if (b||m==0)
			puts("1");
		else
			puts("2");
	}
	return 0;
}