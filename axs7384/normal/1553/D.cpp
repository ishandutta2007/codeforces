#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int tt,n,m;
char s[N],t[N];
int main()
{
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%s",s+1);
		scanf("%s",t+1);
		bool b=true;
		n=strlen(s+1);
		m=strlen(t+1);
		int p=n;
		for (int i=m;i;--i)
		{
			while (p>=1&&t[i]!=s[p])
				p-=2;
			if (p>=1)
				--p;
			else
			{
				b=false;
				break;
			}
		}
		puts(b?"YES":"NO");
	}
	return 0;
}