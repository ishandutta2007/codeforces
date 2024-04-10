#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[200005];
int n,t;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		ll ans=0;
		scanf("%d",&n);
		scanf("%s",s);
		int m=strlen(s);
		int d=0,r=0;
		for (int i=0;i<m;++i)
			if (s[i]=='D')
				++d;
			else
				++r;
		int x=0,y=0;
		for (int i=0;i<m;++i)
			if (s[i]=='D')
			{
				++x;
				if (y)
					ans+=n-r;
				else
					++ans;
			}
			else
			{
				++y;
				if (x)
					ans+=n-d;
				else
					++ans;
			}
		// cout<<n<<' '<<ans<<"?"<<endl;
		if ((d)&&(r))
		{
			ans+=(ll)(n-d)*(n-r);
		}
		else
		{
			if (d)
				ans+=(n-d);
			if (r)
				ans+=(n-r);
		}
		cout<<ans<<endl;
	}
}