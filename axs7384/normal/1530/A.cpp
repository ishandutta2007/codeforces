#include<bits/stdc++.h>
using namespace std;
int t;
char s[100];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%s",s);
		int ans=1;
		for (int i=0;i<strlen(s);++i)
			ans=max(ans,(int)(s[i]-'0'));
		cout<<ans<<endl;
	}
	return 0;
}