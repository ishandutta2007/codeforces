#include<bits/stdc++.h>
using namespace std;
int t;
char s[100005];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%s",s);
		int n=strlen(s),ans=0;
		for (int i=0;i<n;++i)
			if (s[i]=='N')
				++ans;
		puts(ans==1?"NO":"YES");
	}
	return 0;
}