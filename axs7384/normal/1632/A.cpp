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
		scanf("%s",s);
		puts(n==1||(n==2&&s[0]!=s[1])?"YES":"NO");
	}
	return 0;
}