#include<bits/stdc++.h>
using namespace std;
int t,n;
char c[10000],s[10000];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for (int i=1;i<=n;++i)
			c[i]=s[i];
		sort(c+1,c+1+n);
		int ans=0;
		for (int i=1;i<=n;++i)
			if (c[i]!=s[i])
				++ans;
		cout<<ans<<endl;
	}
}