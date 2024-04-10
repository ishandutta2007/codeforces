#include<bits/stdc++.h>
using namespace std;
inline void read(int &x)
{
	char c=getchar();
	x=0;
	while (c>'9'||c<'0')
		c=getchar();
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
int n,t;
int a[100005];
int main()
{
	read(t);
	while (t--)
	{
		read(n);
		int p=1,ans=1;
		for (int i=1;i<=n;++i)
		{
			read(a[i]);
			if (a[i]==a[i-1])
			{
				++p;
				ans=max(p,ans);
			}
			else
				p=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}