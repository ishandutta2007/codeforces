#include<bits/stdc++.h>
using namespace std;
int n,a0,a1,b0,b1,an,bn,ans;
char s[1000];
bool pd()
{
	if (a0+an<b1)
		return true;
	if (b0+bn<a1)
		return true;
	return false;
}
int main()
{
	scanf("%d",&n);
	for (int t=1;t<=n;++t)
	{
		scanf("%s",s+1);
		a0=0,a1=0,b0=0,b1=0,an=5,bn=5,ans=10;
		for (int i=1;i<=10;++i)
		{
			if (s[i]=='1')
			{
				++a0;
				++a1;
			}
			if (s[i]=='?')
				++a1;
			--an;
			if (pd())
			{
				ans=i;
				break;
			}
			++i;
			if (s[i]=='1')
			{
				++b0;
				++b1;
			}
			if (s[i]=='?')
				++b1;
			--bn;
			if (pd())
			{
				ans=i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}