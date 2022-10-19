#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],b[N],f[N];
int t,n;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for (int i=1;i<=n;++i)
			scanf("%d",&b[i]);
		for (int i=1;i<=n;++i)
			f[i]=0;
		int p=n;
		bool _b=true;
		for (int i=n;i;--i)
		{
			if (p>0)
			{
				if (a[i]==b[p])
				{
					--p;
					while (p>0&&b[p]==a[i])
					{
						++f[b[p]];
						--p;
					}
				}	
				else
				{
					if (f[a[i]])
						--f[a[i]];
					else
					{
						_b=false;
						break;
					}
				}
			}
			else
				break;
		}
		puts(_b?"YES":"NO");
	}
	return 0;
}